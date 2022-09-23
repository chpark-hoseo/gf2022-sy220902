#ifndef __Game__
#define __Game__
#include <SDL2/SDL.h>

class Game
{
public:
	Game() { }
	~Game() { }

	bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	SDL_Texture* m_pTexture;

	// ���� �簢��
	SDL_Rect m_sourceRectangle;

	// ��� �簢��
	SDL_Rect m_destinationRectangle;
};


#endif /* defined(__Game__) */