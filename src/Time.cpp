#include "Time.h"

Time::Time()
{
    //ctor
}

Time::~Time()
{
    //dtor
}

void Time::start()
{
    beginFrame = SDL_GetTicks();
}

void Time::end()
{
    endFrame = SDL_GetTicks();
    deltaTime = endFrame - beginFrame;

    if (deltaTime < TICKS_PER_FRAME) SDL_Delay(TICKS_PER_FRAME - deltaTime);
}

Uint32 Time::getDeltaTime()
{
    return deltaTime;
}
