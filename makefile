life: main.c simulation.c file_control.c interface.c
	gcc -std=c99 -D _POSIX_C_SOURCE=200809L simulation.c file_control.c interface.c main.c -o life