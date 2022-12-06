#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include "Game.h"
#include "InputHandler.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        m_pWindow = SDL_CreateWindow(
            title, xpos, ypos, width, height, flags);
        if (m_pWindow != 0) {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0) {
                SDL_SetRenderDrawColor
                (m_pRenderer, 0, 0, 0, 255); // );
            }
            else {
                return false; // 랜더러 생성 실패
            }
        }
        else {
            return false; // 윈도우 생성 실패
        }
    }
    else {
        return false; // SDL 초기화 실패
    }


    m_gameObjects.push_back(new Player(new LoaderParams(50, 400, 196, 188, "animate")));

    m_gameObjects.push_back(new Hurdle(new LoaderParams(1050, 500, 64, 64, "pokeball")));


    if (!TheTextureManager::Instance()->load("Assets/vnfls.png", "animate", m_pRenderer)) 
    {
        return false;
    }

    if (!TheTextureManager::Instance()->load("Assets/pokeball.png", "pokeball", m_pRenderer)) 
    {
        return false;
    }





    m_bRunning = true;
    return true;
}

void Game::update()
{


    {
        for (int i = 0; i < m_gameObjects.size(); i++)
        {
            m_gameObjects[i]->update();
        }
    }



    // m_currentFrame = ((SDL_GetTicks() / 100) % 6);
    // 게임 데이터 갱신
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);

    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }

    SDL_RenderPresent(m_pRenderer);
    
}

bool Game::running()
{
    return m_bRunning;
}

void Game::handleEvents()
{
    TheInputHandler::Instance()->update();
}


void DrawGameOver(const int score)
{
    printf("\n\n\n\n\n\n\n\n\n");
    system("GAME OVER\n");
}






void Game::clean()
{
    TheInputHandler::Instance()->clean();
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

