#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <SDL.h>

class Input
{
    public:
        static Input* Instance();

        void update();

        bool getKey(SDL_Scancode);
        bool windowCloseRequest();
        bool quit();
        void clean();

    private:
        Input() { windowClose = false; }
        ~Input() {}

        static Input* instance;

        bool windowClose;

        const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
};

#endif // INPUT_H
