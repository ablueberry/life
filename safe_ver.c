#include <stdlib.h>
#include <stdio.h>
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

/*  wstawia strukturę na tablicę  */
void pattern (int width, int height, int board[][height], char choice, int va, int vb) {
	/*  g - glider  */
	if (choice == 'g') {
		board[va][vb] = 1;
		board[va+1][vb] = 1;
		board[va+2][vb] = 1;
		board[va][vb+1] = 1;
		board[va+1][vb+2] = 1;	
	}

	/*  d - dakota  */
	if (choice == 'd') {
		board[va+1][vb] = 1;
		board[va+4][vb] = 1;
		board[va][vb+1] = 1;
		board[va][vb+2] = 1;
		board[va][vb+3] = 1;
		board[va+1][vb+3] = 1;
		board[va+2][vb+3] = 1;
		board[va+3][vb+3] = 1;
	}

	/*  t - toad  */
	if (choice == 't') {
		board[va+1][vb] = 1;
		board[va+2][vb] = 1;
		board[va+3][vb] = 1;
		board[va][vb+1] = 1;
		board[va+1][vb+1] = 1;
		board[va+2][vb+1] = 1;
	}

	/* r - r-pentomino  */
	if (choice == 'r') {
		board[va+1][vb] = 1;
		board[va+2][vb] = 1;
		board[va][vb+1] = 1;
		board[va+1][vb+1] = 1;
		board[va+1][vb+2] = 1;
	}
}

/*  wyświetla tablicę  */
void print (int width, int height, int board[][height]) {
	int i, j;
	for (j = 0; j < height; j++) {
		for (i = 0; i < width; i++) {
			printf("%c ", board[i][j] ? '#' : '_');
		}
		printf("\n");
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
			/*  TODO zrobić je tak aby mozna było przekazać je w configu  */
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

/* config - zarządza całą symulacją  */
void simulation (int custom_width, int custom_height) {
	int i, j, k;
	int width = custom_width;
	int height = custom_height;
	int board[width][height];
	initialize_board(width, height, board);
	pattern(width, height, board, 'r', 10, 10);
	print(width, height, board);
	for (i = 0; i < 10; i++) {
		play(width, height, board);
		sleep(1);
		/*deletes current line and returns to beginning*/
		for(j = 0; j < height; j++) {
			for(k = 0; k < width; k++)
			printf("%c[H", 27);
		}
		print(width, height, board);
	}
}
