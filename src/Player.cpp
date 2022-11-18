#include <Player.h>
#include "main.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::draw()
{
    SDLGameObject::draw();
}

void Player::update()
{
    m_currentFrame = ((SDL_GetTicks() / 100) % 6);
    m_velocity.setX(1);
    SDLGameObject::update(); // ← 부모 클래스의 함수 호출 
}

void Player::clean() {}