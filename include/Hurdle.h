#pragma once
#include <SDLGameObject.h>
#include <LoaderParams.h>
#include <InputHandler.h>

class Hurdle : public SDLGameObject
{
public:
    Hurdle(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    int score = 0; // Á¡¼ö
};