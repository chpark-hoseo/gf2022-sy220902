#include "Game.h"
Game* g_game = 0;

int main(int argc, char* argv[])
{
    g_game = new Game();

    g_game->init("20211059", 100, 100, 600, 800, 0);

    while (g_game->running())
    {
        g_game->handleEvents();
        g_game->update();
        g_game->render();
    }

    g_game->clean();

    return 0;
}
