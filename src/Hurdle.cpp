#include <Hurdle.h>
#include "main.h"
#include "InputHandler.h"
#include "Game.h"


Hurdle::Hurdle(const LoaderParams* pParams) : SDLGameObject(pParams) {}


void Hurdle::draw()
{
    SDLGameObject::draw();
}

void Hurdle::update()

{
    Player* player = Game::Instance()->getPlayer();
    Vector2D  pos = player->m_position;

    // 충돌 검사
    if (m_position.getX() > 50 && m_position.getX() < 200 && pos.getY() >= 350) // 수치 조정
    {
        printf("GameOver"); // 게임 종료
        SDL_Quit();
        
    }



    //printf("%f %f\n", pos.getX(), pos.getY());

    if (score < 1000)
    {
        m_velocity.setX(-5);
    }
    else if (score >= 1000)
    {
        m_velocity.setX(-7);
    }
    

    if (m_position.getX() < -100)
    {
        m_position.setX(1050);
        score += 100;
        printf("SCORE : %d", score);
        printf("\n\n\n\n\n\n\n\n\n");
    }

    


    //m_currentFrame = ((SDL_GetTicks() / 100) % 6);
    SDLGameObject::update();


    //m_acceleration.setX(1);
}



void Hurdle::clean() {}