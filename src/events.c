#include "misc.h"

bool mark(Cell *cell, int *marked, int *disc) {
	switch(cell->img) {
		case MARK: {
			cell->img = WALL;
			*marked -= 1;
			break;
		}
		case WALL: {
			if(*marked >= BOMB_MAX) break;
			cell->img = MARK;
			*marked+=1;
			if(cell->bomb) {
				*disc+=1;
			}
			return true;
			break;
		}
	}
	return false;
}

bool click(Cell cells[], int x, int y) {
	Cell *cell = &cells[x+y*XSIZE];
	if(cell->bomb) {
		cell->img = BOMB;
		cell->check=true;
		return false;
	}
	return true;
}