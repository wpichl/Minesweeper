#ifndef ___MISC_H
#define ___MISC_H
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#include "game.h"
#include "renderer.h"

void setBombs(Cell cells[], int bombs,int x, int y);
int checkCell(Cell cells[], int x, int y);
bool mark(Cell *cell, int *marked, int *disc);
bool click(Cell cells[], int x, int y);
void setupGame(SDL_Renderer *ren, SDL_Texture *text, Cell cells[], int x, int y);
int coin(int min, int max);
void addObject(Cell cells[], int x, int y);
#endif