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
                return false; // ������ ���� ����
            }
        }
        else {
            return false; // ������ ���� ����
        }
    }
    else {
        return false; // SDL �ʱ�ȭ ����
    }

    // ��� �ҷ�����
    if (!TheTextureManager::Instance()->load("Assets/ground_grass.png", "Ground_grass", m_pRenderer))
    {
        return false;
    }

    // Ŀ�� �ҷ�����
    if (!TheTextureManager::Instance()->load("Assets/cursor.png", "Cursor", m_pRenderer))
    {
        return false;
    }


    // �÷��̾� �ҷ�����
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
    // ���� ������ ����
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);



    //TheTextureManager::Instance()->draw("animate", 0, 0, 60, 90,
    //    m_pRenderer);

    // ��� �׸���
    TheTextureManager::Instance()->draw("Ground_grass", 0, 0, 800,
        600, m_pRenderer);

    // Ŀ�� �׸���
    TheTextureManager::Instance()->drawFrame("Cursor", m_cursor_x, m_cursor_y, 67,
        70, 0, m_cursor, m_pRenderer);


    // �÷��̾� �׸���
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
    


    while (SDL_PollEvent(&event) != 0) // if���� �� ���� �۵��ϰ� ������ ������ switch-case���� ������ �ϳ��� ���̽��� ó���ϸ� ������������
        // while���� �̺�Ʈ�� ����Ǵ� ���� ��� �۵��ǰ� �ֱ� ������ QUIT�̿ܿ� �ٸ� ���̽��� �� �߰��� �� �ִ�. 
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

