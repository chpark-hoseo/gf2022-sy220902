#ifndef __Game__
#define __Game__
#include <TextureManager.h>
#include <SDLGameObject.h>
#include <Player.h>
#include <Hurdle.h>
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
	void quit() { m_bRunning = false; }
	void clean();
	bool move = false;
	
	void DrawGameOver(const int score);
	// bool isCollision(); // 충돌 판정 만들기


	static Game* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	Player* getPlayer() { return (Player*) m_gameObjects[0]; }

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	

	static Game* s_pInstance; // 정적 멤버변수 

	std::vector<GameObject*> m_gameObjects;

	//TextureManager m_textureManager;
	int m_currentFrame;


};

typedef Game TheGame;

#endif /* defined(__Game__) */