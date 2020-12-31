#include "misc.h"

void setupGame(SDL_Renderer *ren, SDL_Texture *text, Cell cells[], int x, int y) {
	SDL_RenderClear(ren);
	
	for(int i = 0; i < XSIZE; i++) {
		for(int j = 0; j < YSIZE; j++) {
			cells[i+j*XSIZE].img = WALL;
			cells[i+j*XSIZE].bomb = false;
			cells[i+j*XSIZE].adj = 0;
			cells[i+j*XSIZE].check = false;
			render(ren,text,WALL,i,j);
		}
	}

	setBombs(cells,BOMB_MAX,x,y);

	SDL_RenderPresent(ren);
}
