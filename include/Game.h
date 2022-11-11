#ifndef __Game__
#define __Game__
#include <TextureManager.h>
#include <GameObject.h>
#include <Player.h>
#include <Monster.h>
#include <vector>

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
	bool move = false;

	static Game* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	SDL_Renderer* getRenderer() const { return m_pRenderer; }

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	GameObject m_go;
	Player m_player;
	Monster m_monster;

	static Game* s_pInstance; // 정적 멤버변수 

	std::vector<GameObject*> m_gameObjects;

	//TextureManager m_textureManager;
	int m_currentFrame;


};

typedef Game TheGame;

#endif /* defined(__Game__) */