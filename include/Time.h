#ifndef TIME_H
#define TIME_H

#include <SDL.h>
#include "globals.h"

class Time
{
    public:
        Time();
        ~Time();

        void start();
        void end();

        Uint32 getDeltaTime();

    private:
        const Uint32 TICKS_PER_FRAME = 1000/FPS;

        Uint32 beginFrame, endFrame;
        //Uint32 totalTime;
        Uint32 deltaTime;
};

#endif // TIME_H
