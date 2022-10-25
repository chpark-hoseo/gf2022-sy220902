#ifndef __Game__
#define __Game__
#include <TextureManager.h>


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



	SDL_Event event;

	enum LButtonSprite
	{
		BUTTON_SPRITE_MOUSE_OUT = 0,
		BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
		BUTTON_SPRITE_MOUSE_DOWN = 2,
		BUTTON_SPRITE_MOUSE_UP = 3,
		BUTTON_SPRITE_TOTAL = 4
	};




	//TextureManager m_textureManager;
	int m_ground_grass;
	int m_cursor;
	int m_player_idle;
	
	int m_player_x = 10;
	int m_player_y = 300;
	int m_cursor_x = 200;
	int m_cursor_y = 300;

	


};


#endif /* defined(__Game__) */