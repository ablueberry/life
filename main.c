#include <stdlib.h>
#include <stdio.h>
#include "LIFE_library.h"

#define BOARD_WIDTH 25
#define BOARD_HEIGHT 25

void qstart() {
	int height =  BOARD_HEIGHT;
	int width = BOARD_WIDTH;
	simulation(width, height, 10, 10, "a.txt", 80000000, 200, 0);
}

void nstart() {
	printf("\033c");
	normal_start_interface();
}
void create() {
	printf("\033c");
	create_pattern();
}
int about() {
	printf("\033c");
	about_game();
}
int main(){
	/*
	  TABLE OF CONTENTS:
	  1. Quick play
	  2. Play
	  3. Create pattern
	  4. About 
	  5. Quit
	*/
	int choose;
	while (1) {
		printf("\033c");
		choose = main_interface();
		if (choose == 1) {
			qstart();
		}
		if (choose == 2) {
			nstart();
		}
		if (choose == 3) {
			create();
		}
		if (choose == 4) {
			about();
		}
		if (choose == 5) {
			break;
		}
	}
	return 0;
}