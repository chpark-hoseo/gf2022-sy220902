#include "Game.h"
#include <iostream>

Game* g_game = 0;
const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* argv[])
{


    if (TheGame::Instance()->init("Chapter 1",
        100, 100, 700, 1000, false))
    {
        Uint32 frameStart, frameTime;
        while (TheGame::Instance()->running()) {
            frameStart = SDL_GetTicks();     // step 1
            TheGame::Instance()->handleEvents();
            TheGame::Instance()->update();
            TheGame::Instance()->render();
            frameTime = SDL_GetTicks() - frameStart;  // step 2
            if (frameTime < DELAY_TIME) {
                SDL_Delay((int)(DELAY_TIME - frameTime)); // step 3
            }
        }
    }
    else {
        std::cout << "game init failure " << SDL_GetError() << "\n";
        return -1;
    }
    TheGame::Instance()->clean();
    return 0;

    /*
    g_game = new Game();

    g_game->init("Game Class", 100, 100, 640, 480, 0);

    while (g_game->running())
    {
        g_game->handleEvents();
        g_game->update();
        g_game->render();
        SDL_Delay(10); // add the delay
    }

    g_game->clean();

    return 0;
    */
}
