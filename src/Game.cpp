#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include "Game.h"

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

    // 배경 불러오기
    if (!TheTextureManager::Instance()->load("Assets/ground_grass.png", "Ground_grass", m_pRenderer))
    {
        return false;
    }

    // 커서 불러오기
    if (!TheTextureManager::Instance()->load("Assets/cursor.png", "Cursor", m_pRenderer))
    {
        return false;
    }


    // 플레이어 불러오기
    if (!TheTextureManager::Instance()->load("Assets/player_idle_animate.png", "Player", m_pRenderer))
    {
        return false;
    }

    



    m_bRunning = true;
    return true;
}

void Game::update()
{
    
        

    //m_currentFrame = ((SDL_GetTicks() / 100) % 6);
    // 게임 데이터 갱신
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);



    //TheTextureManager::Instance()->draw("animate", 0, 0, 60, 90,
    //    m_pRenderer);

    // 배경 그리기
    TheTextureManager::Instance()->draw("Ground_grass", 0, 0, 800,
        600, m_pRenderer);

    // 커서 그리기
    TheTextureManager::Instance()->drawFrame("Cursor", m_cursor_x, m_cursor_y, 67,
        70, 0, m_cursor, m_pRenderer);


    // 플레이어 그리기
    TheTextureManager::Instance()->drawFrame("Player", m_player_x, m_player_y, 60,
        90, 0, m_player_idle, m_pRenderer);



    //m_textureManager.draw("animate", 0, 0, 128, 82, m_pRenderer);
    //m_textureManager.drawFrame("animate", 100, 100, 128, 82, 0, m_currentFrame, m_pRenderer);
    //SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
    SDL_RenderPresent(m_pRenderer);
    
}

bool Game::running()
{
    return m_bRunning;
}

void Game::handleEvents()
{
    


    while (SDL_PollEvent(&event) != 0) // if문은 한 번만 작동하고 끝나기 때문에 switch-case에서 뭐든지 하나의 케이스를 처리하면 끝나버리지만
        // while문은 이벤트가 진행되는 동안 계속 작동되고 있기 때문에 QUIT이외에 다른 케이스도 더 추가할 수 있다. 
    {
        if (event.type == SDL_QUIT)
        {
            m_bRunning = false;
            break;
        }
        else if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_UP:
                m_player_y -= 3;
                break;

            case SDLK_DOWN:
                m_player_y += 3;
                break;

            case SDLK_LEFT:
                m_player_x -= 3;
                break;

            case SDLK_RIGHT:
                m_player_x += 3;
                break;

            default:
                break;
            }
        }

        if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP)
        {
            SDL_GetMouseState(&m_cursor_x, &m_cursor_y);
        }

    
    }
}

void Game::clean()
{
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

