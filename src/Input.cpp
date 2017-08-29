#include "Input.h"

Input* Input::instance = NULL;

Input* Input::Instance()
{
    if (instance == NULL)
    {
        instance = new Input();
    }

    return instance;
}

void Input::update()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            windowClose = true;
        }
    }
}

bool Input::getKey(SDL_Scancode key)
{
    if (keyboardState != 0)
        return keyboardState[key] == 1;
    return false;
}

bool Input::windowCloseRequest()
{
    return windowClose;
}

bool Input::quit()
{
    return keyboardState[SDL_SCANCODE_ESCAPE];
}

void Input::clean()
{
    delete instance;
}
