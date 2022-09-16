// SDL 
//
// written by changhoonpark@gmail.com


#include "main.h"
#include <SDL2/SDL.h>


SDL_Window*		g_pWindow = 0;
SDL_Renderer*	g_pRenderer = 0;

SDL_Texture*	g_pTexureImage;
SDL_Rect		g_RectImage;

SDL_Texture*	g_pTexureText;
SDL_Rect 		g_RectText;

TTF_Font*		g_pFont;
Mix_Chunk*		g_pChunk;

bool			g_bRunning = false; // true인 동안 게임 루프가 작동, false인 동안 작동하지 않게 하는 역할
bool			g_bLeftMousePressed = false;

bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
void update();
void render();

int main(int argc, char* argv[])
{
	if (init("Breaking Up HelloSDL",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 640, 480,
		SDL_WINDOW_SHOWN))
	{
		g_bRunning = true;
	}
	else
	{
		return 1; // something's wrong
	}

	while (g_bRunning)
	{
		update();
		render();
	}

	SDL_Quit();
	return 0;
}

bool init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		g_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}
	}
	else
	{
		return false;
	}
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

	return true;
}


void update()
{

}

void render()
{
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(g_pRenderer);
	SDL_RenderPresent(g_pRenderer);
}