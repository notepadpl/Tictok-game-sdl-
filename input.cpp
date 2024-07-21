#include "xoxo.h"
bool CheckCollision(SDL_Rect r1, SDL_Rect r2)
{
	// Simplified collision check using rectangle coordinates
	return (r1.x < r2.x + r2.w && r1.x + r1.w > r2.x && r1.y < r2.y + r2.h && r1.y + r1.h > r2.y);
}

void handleMouseEvents()
{

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			exit(0);
		}
		else if (event.type == SDL_MOUSEMOTION)
		{
			int mouseX = event.motion.x;
			int mouseY = event.motion.y;

			// Check for collision with each square and update highlighted
			// state
			for (int i = 0; i < 9; ++i)
			{
				isHighlighted[i] = CheckCollision(squares[i],
												  {
												  mouseX, mouseY, 1, 1});

			}
		}
		else if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			// Optional: Handle mouse click events on squares
			int mouseX = event.button.x;
			int mouseY = event.button.y;

			for (int i = 0; i < 9; ++i)
			{
				static int j = 2;
				if (isHighlighted[i])
				{
					j++;
					if (j % 2 == 0)
					{
						map[i] = 1;
					}
					else
					{
						map[i] = 2;
					}
					break;		// Handle only the first clicked square
				}
			}
		}
	}
}