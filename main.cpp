
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "xoxo.h"
#include "graphics.cpp"
#include "input.cpp"
#include "gamelogic.cpp"

int main(int argc, char *argv[])
{
//	SDL_Init(SDL_INIT_VIDEO);
SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Squares", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
							  SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
SDL_Texture *bitmapTex = NULL;
  img = IMG_LoadTexture(renderer, IMG_PATH);
SDL_SetRenderTarget(renderer, img);

  SDL_RenderCopy(renderer, bitmapTex, NULL, NULL);
	createSquares();

	bool quit = false;
	while (!quit)
	{
		SDL_RenderClear(renderer);	// Clear the screen before drawing

		handleMouseEvents();
		drawSquares();

		SDL_RenderPresent(renderer);

		SDL_Delay(16);			// Update screen at ~60 FPS
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
