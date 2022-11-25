#pragma once
#include <vector>
#include <SDL2/SDL.h> 
class Vector2D;

enum mouse_buttons {
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

class InputHandler {
public:
    ~InputHandler() {}
    static InputHandler* Instance() {
        if (s_pInstance == 0) {
            s_pInstance = new InputHandler();
        }
        return s_pInstance;
    }
    bool isKeyDown(SDL_Scancode key);
    void update();
    void clean() {}
    bool isKeyOneDown(SDL_Scancode key);
    bool getMouseButtonState(int buttonNumber);
    Vector2D* getMousePosition();

    

private:
    InputHandler();
    //void HandleInput();
    static InputHandler* s_pInstance;
    const Uint8* m_keystates;
    std::vector<bool> m_mouseButtonStates;
    Vector2D* m_mousePosition;
};
typedef InputHandler TheInputHandler;