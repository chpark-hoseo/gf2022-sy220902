#pragma once
#include <SDLGameObject.h>
#include <LoaderParams.h>

class Player : public SDLGameObject
{
public:
    Player(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    void handleInput();

    bool isJumping = false;
    bool isBottom = true;
    
};