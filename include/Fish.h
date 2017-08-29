#ifndef FISH_H
#define FISH_H

#include <SDL.h>
#include "Agent.h"

/*enum STATE
{
    IDLE,
    FLEE,
    REPRODUCE
};*/

class Fish : public Agent
{
    public:
        Fish(int, int, int, int, SDL_Color);
        ~Fish();

        void update();

    private:

};

#endif // FISH_H
