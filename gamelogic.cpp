// Function to determine the winner
#include "xoxo.h"
bool checkWinner()
{
	// Check rows, columns, and diagonals for three Xs or Os
	for (int i = 0; i < 3; ++i)
	{
		if (map[i * 3] == map[i * 3 + 1] && map[i * 3 + 1] == map[i * 3 + 2] && map[i * 3] !=0)
		{
			/*winner 0*/
			/*tutaj potrzebuje jakiegos kwadratu poza kwadratem rozgrywki ktory bedzie informowal o tym kto wygral i tak bedzie pozniej tekstura w tych kwadratach */	SDL_SetRenderDrawColor(renderer, 252, 0, 5, 0);
			SDL_RenderFillRect(renderer, &squares[i]);
			return true;		// Winner ? 0:2
		}
		else if(map[i * 3] == map[i * 3 + 1] && map[i * 3 + 1] == map[i * 3 + 2] && map[i * 3] == 2){
			/*winner 2*/
		}
		if (map[i] == map[i + 3] && map[i + 3] == map[i + 6] && map[i] != 0)
		{
			SDL_SetRenderDrawColor(renderer, 2, 3, 255, 200);
			SDL_RenderFillRect(renderer, &squares[i]);
			return true;		// Winner found in current column
		}
	}
	if (map[0] == map[4] && map[4] == map[8] && map[0] != 0)
	{
		SDL_SetRenderDrawColor(renderer, 2, 3, 255, 200);
		SDL_RenderFillRect(renderer, &squares[i]);
		return true;			// Winner found in diagonal
	}
	if (map[2] == map[4] && map[4] == map[6] && map[2] != 0)
	{
		SDL_SetRenderDrawColor(renderer, 2, 3, 225, 255);
		SDL_RenderFillRect(renderer, &squares[i]);
		return true;			// Winner found in other diagonal
	}

	// Check for a draw (all squares filled)
	// Draw if all squares are filled
}