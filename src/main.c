#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#include "game.h"
#include "renderer.h"
#include "logger.h"
#include "misc.h"


int main(int argc, char** argv) 
{
	srand(time(NULL));

	if(SDL_Init(SDL_INIT_EVERYTHING) != 0 ) {
		printf("[SDL] Initializing Error: %s\n", SDL_GetError());
		return 1;
	}
	else
	{
		printf("[SDL] Initializing successful\n");
	}

	SDL_Window *win = NULL;
	SDL_Renderer *ren = NULL;

	win = SDL_CreateWindow(TITLE,
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WIDTH, HEIGHT, 0);
	if(!win) {
		printf("[SDL] Window Error: %s\n", SDL_GetError());
		return 1;
	}
	else
	{
		printf("[SDL] Window initializing successful\n");
	}

	ren = SDL_CreateRenderer(win, 0, SDL_RENDERER_ACCELERATED);
	if(!ren) {
		printf("[SDL] Renderer Error: %s\n", SDL_GetError());	
		return 1;
	}
	else
	{
		printf("[SDL] Render initializing successful\n");
	}

	SDL_Texture *sprites;

	sprites = IMG_LoadTexture(ren, "./assets/tileset.png");

	if (!sprites)
	{
		printf("[SDL] Sprite loading failed\n");
		return 1;
	}
	else
	{
		printf("[SDL] Sprite loading successful\n");
	}
	Cell cells[CELLS_NUM];

	setupGame(ren,sprites,cells,0,0);

	SDL_Event event;
	bool running = true;

	bool lost = false;

	int undisc = CELLS_NUM;
	int marked = 0;
	int disc = 0;

	bool init = false;

	while(running) {
		if(SDL_PollEvent(&event)) {
			switch(event.type) {

				case SDL_QUIT: {
					running = false;
					break;
				}

				case SDL_KEYDOWN: {
					SDL_Keysym key = event.key.keysym;
					switch(key.sym){
						case SDLK_ESCAPE: {
							running = false;
							break;
						}
						case SDLK_n: {
							setupGame(ren,sprites,cells,0,0);
							undisc = CELLS_NUM;
						}

					}
					break;
				}	

				case SDL_MOUSEBUTTONDOWN: {
					SDL_MouseButtonEvent button = event.button;
					int x = button.x/QUAD;
					int y = button.y/QUAD;
					if(!init) {
						setupGame(ren,sprites,cells,x,y);
						undisc = CELLS_NUM;
						marked = 0;
						disc = 0;
						init = true;
					}
					if(button.button == SDL_BUTTON_LEFT){
						lost = !click(cells,x,y);
						if(lost) {
							logger("Game Over! Bomb exploded!");
							for(int i=0;i<XSIZE;i++) {
								for(int j=0;j<YSIZE;j++) {
									Cell *cell = &cells[i+j*XSIZE];
									if(cell->bomb) {
										cell->img = BOMB;
									}
								}
							}
							renderAll(ren,sprites,cells);
							SDL_Delay(4000);
							setupGame(ren,sprites,cells,0,0);
							undisc = CELLS_NUM;
							marked = 0;
							disc = 0;
							init = false;
						} else {
							undisc -= checkCell(cells,x,y);
							if(undisc == BOMB_MAX) {
								logger("You Won!");
								renderAll(ren,sprites,cells);
								SDL_Delay(2000);
								setupGame(ren,sprites,cells,0,0);
								undisc = CELLS_NUM;
								marked = 0;
								disc = 0;
								init = false;
							}
						} 
					} else if(button.button == SDL_BUTTON_RIGHT) {
						if(mark(&cells[x+y*XSIZE], &marked, &disc)) {

							if(disc == BOMB_MAX) {
								logger("You Won!");
								renderAll(ren,sprites,cells);
								SDL_Delay(2000);
								setupGame(ren,sprites,cells,0,0);
								undisc = CELLS_NUM;
								marked = 0;
								disc = 0;	
								init = false;
							}
						}
					}
				renderAll(ren,sprites,cells);
				}
			}
		}
	}

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);

	SDL_Quit();

	return 0;
}
