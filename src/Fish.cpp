#include "Fish.h"

Fish::Fish(int px, int py, int psight, int plifetime, SDL_Color pcolor) : Agent(px, py, psight, plifetime, pcolor) {}

Fish::~Fish() {}

void Fish::update()
{
    Agent::update();
}
