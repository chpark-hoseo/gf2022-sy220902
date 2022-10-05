#include "Game.h"


bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        m_pWindow = SDL_CreateWindow(
            title, xpos, ypos, width, height, flags);
        if (m_pWindow != 0) {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0) {
                SDL_SetRenderDrawColor(
                    m_pRenderer, 255, 255, 255, 255);
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

    // Texture 생성
    SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/rider.bmp");

    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

    SDL_FreeSurface(pTempSurface);
    
    // 원본상자의 너비/높이 설정
    SDL_QueryTexture(m_pTexture, NULL, NULL,
        &m_sourceRectangle.w, &m_sourceRectangle.h);

    m_sourceRectangle.x = 50;
    m_sourceRectangle.y = 50;

    // 대상상자의 너비/높이 설정
    m_destinationRectangle.w = m_sourceRectangle.w;
    m_destinationRectangle.h = m_sourceRectangle.h;

    // 원본상자/대상상자의 위치 설정
    m_destinationRectangle.x = 150;
    m_destinationRectangle.y = 150;



    m_bRunning = true;
    return true;
}

void Game::update()
{
    // 게임 데이터 갱신
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle); // Texture 그리기
    SDL_RenderPresent(m_pRenderer);
    
}

bool Game::running()
{
    return m_bRunning;
}

void Game::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) // if문은 한 번만 작동하고 끝나기 때문에 switch-case에서 뭐든지 하나의 케이스를 처리하면 끝나버리지만
        // while문은 이벤트가 진행되는 동안 계속 작동되고 있기 때문에 QUIT이외에 다른 케이스도 더 추가할 수 있다. 
    {
        switch (event.type)
        {
        case SDL_QUIT:
            m_bRunning = false;
            break;
        default:
            break;
        }
    }
}

void Game::clean()
{
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

