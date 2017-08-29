#ifndef SHARK_H
#define SHARK_H

#include <vector>
#include <iostream>
#include "Agent.h"
#include "Fish.h"
#include "Vector2D.h"

class Shark : public Agent
{
    public:
        Shark(int, int, int, int, SDL_Color, std::vector<Fish*>*);
        ~Shark();

        void update();

    private:
        void searchFish();

        Fish* nearestFish;

        std::vector<Fish*> *fishes;
};

#endif // SHARK_H
