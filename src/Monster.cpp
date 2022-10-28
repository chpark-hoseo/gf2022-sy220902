#include <Monster.h>



void Monster::load(int x, int y, int width, int height, std::string textureID)
{
    GameObject::load(x, y, width, height, textureID);
}

void Monster::draw(SDL_Renderer* pRenderer)
{
    GameObject::draw(pRenderer);
}

void Monster::update()
{
    if (moveRight == false)
    { 
        //
        m_x -= 1;
    }
    else if (moveRight == true)
    {
        m_x += 1;
    }
    
}