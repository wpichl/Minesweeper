#include "renderer.h"

void render(SDL_Renderer* ren, SDL_Texture* text, int offset, int x, int y) {
	SDL_Rect srcR;
	SDL_Rect destR;

	srcR.x = offset*QORG;
	srcR.y = 0;
	srcR.w = QORG;
	srcR.h = QORG;

	destR.x = x*QUAD;
	destR.y = y*QUAD;
	destR.w = QUAD;
	destR.h = QUAD;

	SDL_RenderCopy(ren,text,&srcR,&destR);
}

void renderAll(SDL_Renderer* ren, SDL_Texture* text, Cell cells[]) {
	SDL_RenderClear(ren);
	for(int i = 0; i < XSIZE; i++) {
		for(int j = 0; j < YSIZE; j++) {
			render(ren, text, cells[i+XSIZE*j].img,i,j);
		}
	}
	SDL_RenderPresent(ren);
}