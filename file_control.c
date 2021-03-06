#include <stdio.h>
#include <stdlib.h>
#include "LIFE_library.h"

/*  odczytywanie wzoru z pliku txt - edytuje przekazaną tablicę w miejscu gdzie sie mu wstaże  */
void read_pattern (int width, int height, int board[][height], int va, int vb, char *patch) {
	FILE *data;
	data = fopen(patch, "r");
	int w, h, i, j;
	if (data == NULL) {
		printf("something went wrong :( \n");
	} else {
		fscanf(data, "%d %d ", &w, &h);
		int tab[w][h];
		for (j = 0; j < h; j++) {
			for (i = 0; i < w; i++) {
				fscanf(data, "%d ", &tab[i][j]);
			}
		}

		/*  mamy w tab gotowy wzór do wklejenia do board  */
		for (j = 0; j < h; j++) {
			for (i = 0; i < w; i++) {
				board[va+i][vb+j] = tab[i][j];
			}
		}
	}
}

void save_pattern (int width, int height, int board[][height], char *name) {
	FILE *data;
	data = fopen(name, "w");
	int i, j;	
	fprintf(data, "%d %d\n", width, height);
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			fprintf(data, "%d ", board[j][i]);
		}
		fprintf(data, "\n");
	}
	fclose(data);
}