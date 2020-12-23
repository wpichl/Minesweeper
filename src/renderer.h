#ifndef ___RENDERER_H
#define ___RENDERER_H
#include "game.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

void render(SDL_Renderer* ren, SDL_Texture* text, int offset, int x, int y);
void renderAll(SDL_Renderer* ren, SDL_Texture* text, Cell cells[]);
#endif