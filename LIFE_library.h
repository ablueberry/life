#ifndef LIFE_LIBRARY_
#define LIFE_LIBRARY_

/*  simulation.c  */
void simulation (int custom_width, int custom_height, int pattern_va, int pattern_vb, char *pattern_patch, int frame_time_nsek, int frame_number);

/*  file_control.c  */
void read_pattern (int width, int height, int board[][height], int va, int vb, char *patch);

/*  interface.c  */
int main_interface();
void normal_start_interface();
#endif