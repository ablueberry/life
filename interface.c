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
	  3. About 
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
	int choose;
	printf("\nPlease choose from options above and type the number %s   %s\b\b\b", right_pointing_triangle, left_pointing_triangle);
	scanf("%d", &choose);
	return choose;
}

void normal_start_interface() {
	int w, h, va, vb, t, num;
	char name[20];

	printf("WELCOME IN SIMULATION OF LIFE\nPlease fill the form below:\n\n");
	printf("Board width (min - 10, max - 50) %s    %s\b\b\b\b", right_pointing_triangle, left_pointing_triangle);
	scanf("%d", &w);
	printf("\n");
	if (w < 10 || w > 50 ) {
		printf("Sorry, you typed something wrong, this value will be set to default\n\n");
		w = 20;
	}
	printf("Board height (min - 10, max - 50) %s    %s\b\b\b\b", right_pointing_triangle, left_pointing_triangle);
	scanf("%d", &h);
	printf("\n");
	if (h < 10 || h > 50 ) {
		printf("Sorry, you typed something wrong, this value will be set to default\n\n");
		h = 20;
	}
	printf("Pattern file name (eg. a.txt, max 20 characters) %s                     %s\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b", right_pointing_triangle, left_pointing_triangle);
	scanf("%s", name);
	printf("\n");
	printf("Position of pattern's left corner (pattern must be in the board) :\nFrom left border %s    %s\b\b\b\b", right_pointing_triangle, left_pointing_triangle);
	scanf("%d", &va);
	printf("\n");
	printf("From top border %s    %s\b\b\b\b", right_pointing_triangle, left_pointing_triangle);
	scanf("%d", &vb);
	if ( va > w || vb > h ) {
		printf("Sorry, you typed something wrong, this value will be set to default\n\n");
		va = w / 2;
		vb = h / 2;	
	}
	printf("\n");
	printf("Time of animation's frame (in nanoseconds - min 50 mln nsec- 0,5 sec,  max 200 mln - 2 sec) %s          %s\b\b\b\b\b\b\b\b\b\b", right_pointing_triangle, left_pointing_triangle);
	scanf("%d", &t);
	printf("\n");
	if ( t < 50000000 || t > 200000000 ) {
		printf("Sorry, you typed something wrong, this value will be set to default\n\n");
		t = 80000000;
	}
	printf("Number of animation's frames (max 1000) %s      %s\b\b\b\b\b\b", right_pointing_triangle, left_pointing_triangle);
	scanf("%d", &num);
	printf("\n");
	if ( num < 1 || num > 1000 ) {
		printf("Sorry, you typed something wrong, this value will be set to default\n\n");
		num = 200;
	}
	int yn;
	printf("Simulation parameters are set to: \nwidth: %d\nheight: %d\nPattern name file: %s\nPattern's left corner: %d %d\nFrame's time %d\nFrame's number %d\n", w, h, name, va, vb, t, num);
	printf("Do you want to play the simulation? [y - 1/n - 0] ");
	scanf("%d", &yn);
	if (yn) {
		simulation(w, h, va, vb, name, t, num);
	}	
}