#ifndef XOXO_H
#define XOXO_H
// Include Statements
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


// Global Constants
const int SCREEN_WIDTH = 540;
const int SCREEN_HEIGHT = 180;
const int SQUARE_SIZE = 180;
SDL_Event event;
	static int currentPlayer;
SDL_Rect squares[9];			// Array of rectangles representing squares
/* map chease game future nkw xoxo tictoe game */
int map[9] = { 0,0,0,0,0,0,0,0,0 };
bool isHighlighted[9] = { false };	// Array to track highlighted squares
int i;
//#define player1 "1"
//#define player2 "2"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Texture *img = NULL;
// Function Prototypes
void createSquares();
bool CheckCollision(SDL_Rect r1, SDL_Rect r2);
bool checkWinner();
void handleMouseEvents();
void drawSquares();



#endif // XOXO_H
