#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
const int SCREEN_WIDTH = 540;	// Adjusted for 3 squares per row
const int SCREEN_HEIGHT = 180;	// Adjusted for 3 squares per column
const int SQUARE_SIZE = 180;	// Size of each square
int i;
#define player1 "1"
#define player2 "2"
#define IMG_PATH "img.jpg"
 SDL_Texture *img = NULL;
// Removed unused map and pole arrays

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

SDL_Rect squares[9];			// Array of rectangles representing squares
/* map chease game future nkw xoxo tictoe game */
int map[9] = { 0,0,0,0,0,0,0,0,0 };
bool isHighlighted[9] = { false };	// Array to track highlighted squares

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

bool CheckCollision(SDL_Rect r1, SDL_Rect r2)
{
	// Simplified collision check using rectangle coordinates
	return (r1.x < r2.x + r2.w && r1.x + r1.w > r2.x && r1.y < r2.y + r2.h && r1.y + r1.h > r2.y);
}


// Function to determine the winner
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

void handleMouseEvents()
{
	SDL_Event event;
	static int currentPlayer;
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
