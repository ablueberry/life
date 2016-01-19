#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "LIFE_library.h"

/*  wyzerowanie tablicy  */
void initialize_board (int width, int height, int board[][height]) {
	int i, j;
	for (j = 0; j < height; j++) {
		for (i = 0; i < width; i++) {
			board[i][j] = 0;
		}
	}
}

/*  oblicza współrzędne łącząc brzegi tablicy - tworzy walec  */
int xadd (int i, int a, int width) {
	i += a;
	while (i < 0) {
		i += width;
	}
	while (i >= width) {
		i -= width;
	}
	return i;
}
int yadd (int i, int a, int height) {
	i += a;
	while (i < 0) {
		i += height;
	}
	while (i >= height) {
		i -= height;
	}
	return i;
}

/*  oblicza liczbę sąsiadów  */
int neighbours (int width, int height, int board[][height], int i, int j) {
	int k, l, count = 0;
	for (k = -1; k <= 1; k++) {
		for (l = -1; l <= 1; l++) {
			if (l || k) {
				if (board[xadd(i, k, width)][yadd(j, l, height)]) {
					count++;
				}
			}
		}
	}
	return count;
}

void play (int width, int height, int board[][height]) {
	int new_board[width][height], i, j, n;

	for (i = 0; i < width; i++) {
		for (j = 0; j < height; j++) {
			n = neighbours(width, height, board, i, j);
			/*  ustawienia reguł gry  */
			if (n == 2) new_board[i][j] = board[i][j];
			if (n == 3) new_board[i][j] = 1;
			if (n < 2 || n > 3) new_board[i][j] = 0;
		}
	}

	for (i = 0; i < width; i++) {
		for (j = 0; j < height; j++) {
			board[i][j] = new_board[i][j];
		}
	}
}

/*  wyświetla tablicę  */
void print (int width, int height, int board[][height]) {
	int i, j;
	/*  ramka górna  */
	for (j = 0; j < width+2; j++) {
		printf("\u2588\u2588");
	}
	printf("\b \b\n");
	/*  ramki boczne i plansza  */
	for (j = 0; j < height; j++) {
		printf("\u2588 ");
		for (i = 0; i < width; i++) {
			printf("%s ", board[i][j] ? "\u2587" : "\u2591");
		}
		printf("\u2588\n");
	}
	/*  ramka dolna  */
	for (j = 0; j < width+2; j++) {
		printf("\u2588\u2588");
	}
	printf("\b \b\n");
}
/*  porównuje dwie tablice i zwraca 1 jeśli są takie same  */
int compare_frames (int width, int height, int prev[][height], int next[][height]) {
	int i, j;
	for (j = 0; j < height; j++) {
		for (i = 0; i < width; i++) {
			if (prev[i][j] != next[i][j]) {
				return 0;
			}
		}
	}
	return 1;
}
/*  kopiuje tablice  */
void copy(int width, int height, int board[][height], int prev[][height]) {
	int i, j;
	for (j = 0; j < height; j++) {
		for (i = 0; i < width; i++) {
			prev[i][j] = board[i][j];
		}
	}
}
/* config - zarządza całą symulacją  */
void simulation (int custom_width, int custom_height, int pattern_va, int pattern_vb, char *pattern_patch, int frame_time_nsec, int frame_number, int mode) {
	int i, j, k, q;
	int width = custom_width;
	int height = custom_height;
	int board[width][height], prev[width][height];
	/*  czyści terminal  */
	printf("\033c");
	/*  wczytanie pierwszej klatki symulacji  */
	initialize_board(width, height, board);
	initialize_board(width, height, prev);
	read_pattern(width, height, board, pattern_va, pattern_vb, pattern_patch);
	print(width, height, board);
	/*  mode - auto simulation  */
	if (mode == 0) {
		/*  zdefiniowanie czasu pomiędzy klatkami symulacji  */
		struct timespec reqtime;
		reqtime.tv_sec = 0;
   		reqtime.tv_nsec = frame_time_nsec;

   		int cmp = 0;
   		/*  symulacja kolejnych klatek  */
		for (i = 0; i < frame_number; i++) {
			play(width, height, board);
			/*  porównuje aktualną klatke z poprzednią  */
			cmp = compare_frames(width, height, prev, board);
			/*  kopiuje aktualna klatke  */
			copy(width, height, board, prev);
			nanosleep(&reqtime, NULL);
			printf("\033c");
			print(width, height, board);

			if (cmp == 1) {
				printf("Next frames will be the same - end of simulation. Type a number to quit: \n");
				scanf("%d", &q);
				break;
			}
		}
	}
	/*	mode - safe to file at end  */
	if (mode == 1) { 
		char c;
		while (1) {
			play(width, height, board);
			printf("\033c");
			print(width, height, board);
			printf("Type 's' to save, 'q' to quit: ");
			scanf("%c", &c);
			if (c == 'q') {
				break;			
			}
			if (c == 's') {
				char name[20];
				printf("Type a name of file to save this pattern: ");
				scanf("%20s", name);
				save_pattern (width, height, board, name);			
			}		
		}	
	}
}
