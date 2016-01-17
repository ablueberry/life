#include <stdio.h>
#define right_pointing_triangle "\u25B6"
#define left_pointing_triangle "\u25C0"
int main()
{
	int w, h, va, vb, t, num;
	char name[20];
	printf("WELCOME IN SIMULATION OF LIFE\nPlease fill the form below:\n\n");
	printf("Board width (min - 10, max - 50) %s    %s\b\b\b\b", right_pointing_triangle, left_pointing_triangle);
	scanf("%d", &w);
	printf("\n");
	printf("Board height (min - 10, max - 50) %s    %s\b\b\b\b", right_pointing_triangle, left_pointing_triangle);
	scanf("%d", &h);
	printf("\n");
	printf("Pattern file name (eg. a.txt, max 20 characters) %s                     %s\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b", right_pointing_triangle, left_pointing_triangle);
	scanf("%s", name);
	printf("\n");
	printf("Position of pattern's left corner (pattern must be in the board) :\nFrom left border %s    %s\b\b\b\b", right_pointing_triangle, left_pointing_triangle);
	scanf("%d", &va);
	printf("\n");
	printf("From top border %s    %s\b\b\b\b", right_pointing_triangle, left_pointing_triangle);
	scanf("%d", &vb);
	printf("\n");
	printf("Time of animation's frame (in nanoseconds - min 50 mln nsec- 0,5 sec,  max 200 mln - 2 sec) %s          %s\b\b\b\b\b\b\b\b\b\b", right_pointing_triangle, left_pointing_triangle);
	scanf("%d", &t);
	printf("\n");
	printf("Number of animation's frames (max 1000) %s      %s\b\b\b\b\b\b", right_pointing_triangle, left_pointing_triangle);
	scanf("%d", &num);
	printf("\n");
	printf("%d %d %d %d %d %d %s", w, h, va, vb, t, num, name);
    return 0;
}