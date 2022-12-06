#include <Player.h>
#include "main.h"
#include "InputHandler.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::draw()
{
    SDLGameObject::draw();
}

void Player::update()
{
    handleInput();
    m_currentFrame = ((SDL_GetTicks() / 100) % 6);

    if (isJumping)
    {
        m_velocity.setY(-5); // 3�� ������
    }
    else
    {
        m_velocity.setY(5); // �������� �ӷ�
    }

    if (m_position.getY() >= 400) // �ٴ� ���� // 400�� �ٴ��� y ��
    {
        m_position.setY(400);
        isBottom = true;
    }

    
    if (m_position.getY() <= 250) // ���� �ִ� ���� ����
    {
        isJumping = false;
    }


    SDLGameObject::update();
}

void Player::handleInput()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP) && isBottom) {
        isJumping = true;
        isBottom = false;
    }
}



void Player::clean() {}