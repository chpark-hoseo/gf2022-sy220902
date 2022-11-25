#pragma once
#include <SDLGameObject.h>
#include <LoaderParams.h>
#include <InputHandler.h>

class Enemy : public SDLGameObject
{
public:
    Enemy(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    void handleInput();
};