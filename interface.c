#include <stdio.h>
#include <stdlib.h>
#include "LIFE_library.h"

/*  UNICODE CHARACTERS LIBRARY  */

/*  double pipes  */
#define left_top_corner "\u2554"
#define right_top_corner "\u2557"
#define left_bottom_corner "\u255A"
#define right_bottom_corner "\u255D"
#define double_horizontal_pipe "\u2550"
#define double_vertical_pipe "\u2551"
#define crossing_left "\u2560"
#define crossing_right "\u2563"

/*  blocks  */
#define full_block "\u2588"
#define light_shade_block "\u2591"
#define medium_shade_block "\u2592"

/*  1/4 circles  */
#define circle_corner_top_left "\u256D"
#define circle_corner_top_right "\u256E"
#define circle_corner_bottom_left "\u2570"
#define circle_corner_bottom_right "\u256F"

/*  single pipes  */
#define vertical_pipe "\u2502"
#define horizontal_pipe "\u2500"

/*  triangles  */
#define right_pointing_triangle "\u25B6"
#define left_pointing_triangle "\u25C0"

void header() {
	int i, j;
	/*  top border  */
	printf("%s", left_top_corner);
	for	(i = 0; i < 70; i++) {
		printf("%s", double_horizontal_pipe);
	}
	printf("%s\n", right_top_corner);

	/*  middle of a table  */
	printf("%s                                                                      %s\n", double_vertical_pipe, double_vertical_pipe);
	printf("%s         GAME OF                                                      %s\n", double_vertical_pipe, double_vertical_pipe);
	printf("%s                                                                      %s\n", double_vertical_pipe, double_vertical_pipe);
	printf("%s                 ####      ####     #######   #######                 %s\n", double_vertical_pipe, double_vertical_pipe);
	printf("%s                ####      ####     #######   #######                  %s\n", double_vertical_pipe, double_vertical_pipe);
	printf("%s               ####      ####     ####      ####                      %s\n", double_vertical_pipe, double_vertical_pipe);
	printf("%s              ####      ####     #######   #######                    %s\n", double_vertical_pipe, double_vertical_pipe);
	printf("%s             ####      ####     ####      ####                        %s\n", double_vertical_pipe, double_vertical_pipe);
	printf("%s            #######   ####     ####      #######                      %s\n", double_vertical_pipe, double_vertical_pipe);
	printf("%s           #######   ####     ####      #######                       %s\n", double_vertical_pipe, double_vertical_pipe);
	printf("%s                                                                      %s\n", double_vertical_pipe, double_vertical_pipe);
	printf("%s                                            SIMULATION                %s\n", double_vertical_pipe, double_vertical_pipe);
	printf("%s                                                                      %s\n", double_vertical_pipe, double_vertical_pipe);
	

	/*  bottom border  */
	printf("%s", left_bottom_corner);
	for (i = 0; i < 70; i++) {
		printf("%s", double_horizontal_pipe);
	}
	printf("%s\n", right_bottom_corner);
}

void menu() {
	/*
	  TABLE OF CONTENTS:
	  1. Quick play
	  2. Play
	  3. Settings
	  4. About 
	*/
	int i;

	/*  top border  */
	printf("%s", left_top_corner);
	for	(i = 0; i < 70; i++) {
		printf("%s", double_horizontal_pipe);
	}
	printf("%s\n", right_top_corner);

	/*  middle of a table  */ 
	printf("%s                           1. QUICK PLAY                              %s\n", double_vertical_pipe, double_vertical_pipe);
	printf("%s", crossing_left);
	for	(i = 0; i < 70; i++) {
		printf("%s", double_horizontal_pipe);
	}
	printf("%s\n", crossing_right);

	printf("%s                           2. PLAY                                    %s\n", double_vertical_pipe, double_vertical_pipe);
	printf("%s", crossing_left);
	for	(i = 0; i < 70; i++) {
		printf("%s", double_horizontal_pipe);
	}
	printf("%s\n", crossing_right);

	printf("%s                           3. SETTINGS                                %s\n", double_vertical_pipe, double_vertical_pipe);
	printf("%s", crossing_left);
	for	(i = 0; i < 70; i++) {
		printf("%s", double_horizontal_pipe);
	}
	printf("%s\n", crossing_right);

	printf("%s                           4. ABOUT                                   %s\n", double_vertical_pipe, double_vertical_pipe);

	/*  bottom border  */
	printf("%s", left_bottom_corner);
	for (i = 0; i < 70; i++) {
		printf("%s", double_horizontal_pipe);
	}
	printf("%s\n", right_bottom_corner);
}

int main_interface() {
	header();
	menu();
	int ch;
	printf("\nPlease choose from options above and type the number %s   %s\b\b\b", right_pointing_triangle, left_pointing_triangle);
	scanf("%d", &ch);
	return ch;
}

void normal_start_interface() {
	int w, h, va, vb, t, num, mode;
	char name[20];

	printf("WELCOME IN SIMULATION OF LIFE\nPlease fill the form below:\n\n");

	while (1) {
		printf("Simulation's mode (0 - auto, 1 - manual) %s    %s\b\b\b\b", right_pointing_triangle, left_pointing_triangle);
		scanf("%d", &mode);
		if (mode == 0 || mode == 1) {
			break;
		} else {
			printf("You typed something wrong, please try again\n\n");
		}
	}
	
	int def_w, def_h;
	while (1) {
		printf("\nPattern file name (eg. a.txt, max 20 characters) %s                     %s\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b", right_pointing_triangle, left_pointing_triangle);
		scanf("%s", name);
		FILE *data;
		data = fopen(name, "r");
		int w, h, i, j;
		if (data == NULL) {
			printf("File doesn't exist, try with another name\n");
		} else {
			fscanf(data, "%d %d ", &def_w, &def_h);
			break;
		}
	}

	while (1) {
		printf("\nBoard width (min = %d, max = 50) %s    %s\b\b\b\b", def_w < 10 ? 10 : def_w, right_pointing_triangle, left_pointing_triangle);
		scanf("%d", &w);
		if (w > 50 ) {
			printf("Sorry, this value of width is not allowed, try again\n");
		} else if (w < 10) {
			printf("Sorry, this value of width is not allowed, try again\n");
		} else if (w < def_w) {
			printf("Sorry, this value of width is not allowed, try again\n");
		} else {
			break;
		}
	}
	
	while (1) {
		printf("\nBoard height (min = %d, max = 50) %s    %s\b\b\b\b",  def_h < 10 ? 10 : def_h, right_pointing_triangle, left_pointing_triangle);
		scanf("%d", &h);
		if (h > 50 ) {
			printf("Sorry, this value of height is not allowed, try again\n");
		} else if (h < 10) {
			printf("Sorry, this value of height is not allowed, try again\n");
		} else if (h < def_h) {
			printf("Sorry, this value of height is not allowed, try again\n");
		} else {
			break;
		}
	}
	
	while (1) {
		printf("\nPosition of pattern's left corner (pattern must be in the board) :\nFrom left border %s    %s\b\b\b\b", right_pointing_triangle, left_pointing_triangle);
		scanf("%d", &va);
		if (va+def_w > w) {
			printf("Sorry, pattern won't be in the board, this value will be set to default\n");
			va = w - def_w;
		}
		printf("From top border %s    %s\b\b\b\b", right_pointing_triangle, left_pointing_triangle);
		scanf("%d", &vb);
		if (vb+def_h > h) {
			printf("Sorry, pattern won't be in the board, this value will be set to default\n");
			vb = h - def_h;
		}
		if (va+def_w <= w && vb+def_h <= h) {
			break;
		}
	}

	int yn;
	if (mode == 0) {
		printf("\nTime of animation's frame (in nanoseconds - min 50 mln nsec- 0,5 sec,  max 200 mln - 2 sec) %s          %s\b\b\b\b\b\b\b\b\b\b", right_pointing_triangle, left_pointing_triangle);
		scanf("%d", &t);
		if ( t < 50000000 || t > 200000000 ) {
			printf("Sorry, you typed something wrong, this value will be set to default\n");
			t = 80000000;
		}
		printf("\nNumber of animation's frames (max 1000) %s      %s\b\b\b\b\b\b", right_pointing_triangle, left_pointing_triangle);
		scanf("%d", &num);
		if ( num < 1 || num > 1000 ) {
			printf("Sorry, you typed something wrong, this value will be set to default\n");
			num = 200;
		}
		printf("\nSimulation parameters are set to: \nwidth: %d\nheight: %d\nPattern name file: %s\nPattern's left corner: %d %d\nFrame's time %d\nFrame's number %d\n", w, h, name, va, vb, t, num);
	} else {
		printf("\nSimulation parameters are set to: \nwidth: %d\nheight: %d\nPattern name file: %s\nPattern's left corner: %d %d\n", w, h, name, va, vb);
	}
	printf("Do you want to play the simulation? [y - 1/n - 0] ");
	scanf("%d", &yn);
	if (yn) {
		simulation(w, h, va, vb, name, t, num, mode);
	}	
}

void about_game () {  
	int q;   
	printf("The Game of Life, also known simply as Life, is a cellular automaton devised\nby the British mathematician John Horton Conway in 1970.\n");     
	printf("The game is a zero-player game, meaning that its evolution is determined\nby its initial state, requiring no further input. One interacts with\nthe Game of Life by creating an initial configuration and observing\nhow it evolves or, for advanced players, by creating patterns with particular\nproperties.\n"); 
	printf("\nRules\n");
	printf("The universe of the Game of Life is an infinite two-dimensional orthogonal grid\nof square cells, each of which is in one of two possible states,\nalive or dead. Every cell interacts with its eight neighbours, which\nare the cells that are horizontally, vertically, or diagonally adjacent.\nAt each step in time, the following transitions occur:\n");
	printf("\n1. Any live cell with fewer than two live neighbours dies, as if caused by under-population.\n2. Any live cell with two or three live neighbours lives on to the next generation.\n3. Any live cell with more than three live neighbours dies, as if by over-population.\n4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.\n");
	printf("\n\n\nType a number to quit: ");
	scanf("%d", &q);
}
