#include "xoxo.h"
#define IMG_PATH "img.jpg"


void createSquares()
{
	for (int i = 0; i < 9; ++i)
	{
		squares[i].x = (i % 3) * SQUARE_SIZE;
		squares[i].y = (i / 3) * SQUARE_SIZE;
		squares[i].w = SQUARE_SIZE;
		squares[i].h = SQUARE_SIZE;
	}
}

void drawSquares()
{
	  img = IMG_LoadTexture(renderer, IMG_PATH);
	// Set background color to red before drawing squares
	SDL_SetRenderDrawColor(renderer, 25, 0, 0, 25);	// Red background
	SDL_RenderClear(renderer);

	for (int i = 0; i < 9; ++i)
	{
		if (map[i] == 1)
		{
			SDL_SetRenderDrawColor(renderer, 200, 5, 200, 0);
			SDL_RenderFillRect(renderer, &squares[i]);
		}
		if (map[i] == 0)
		{
			SDL_SetRenderDrawColor(renderer, 55, 55, 25, 255);
			SDL_RenderFillRect(renderer, &squares[i]);
 SDL_RenderCopy(renderer, img, &squares[i], &squares[i]);
		}
		if (map[i] == 2)
		{
			SDL_SetRenderDrawColor(renderer, 255, 5, 5, 20);
			SDL_RenderFillRect(renderer, &squares[i]);
			 SDL_RenderCopy(renderer, img, NULL, &squares[i]);
		

		}
		checkWinner();
	}
}
