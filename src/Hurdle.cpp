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
    m_velocity.setX(-5);

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