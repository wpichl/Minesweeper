#ifndef _GAME_H
#define _GAME_H

#include <stdbool.h>

#define TITLE "Minesweeper in C powered by SDL"
#define QUAD 32
#define QORG 64
#define XSIZE 20
#define YSIZE 20
#define WIDTH XSIZE*QUAD
#define HEIGHT YSIZE*QUAD
#define CELLS_NUM XSIZE*YSIZE
#define BOMB_MAX CELLS_NUM/10
#define BOMB 9
#define WALL 10
#define MARK 11

typedef struct{
	int img;
	bool bomb;
	int adj;
	bool check;
} Cell;

#endif
