#include "Game.h"
Game* g_game = 0;

int main(int argc, char* argv[])
{


    if (TheGame::Instance()->init("Chapter 1",
        100, 100, 640, 480, false))
    {
        while (TheGame::Instance()->running()) {
            TheGame::Instance()->handleEvents();
            TheGame::Instance()->update();
            TheGame::Instance()->render();
            SDL_Delay(10);
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
