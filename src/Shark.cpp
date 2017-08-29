#include "Shark.h"

Shark::Shark(int px, int py, int psight, int plifetime, SDL_Color pcolor, std::vector<Fish*> *pfishes) : Agent(px, py, psight, plifetime, pcolor)
{
    nearestFish = NULL;
    fishes = pfishes;
}

Shark::~Shark()
{
    if (nearestFish != NULL)
        delete nearestFish;
}

void Shark::update()
{
    currentState = nextState;

    switch (currentState)
    {
        case IDLE:
            // Move around
            getPossibleDirections();
            move(getRandomDirection());
            if (nearestFish != NULL)
            {
                if (Vector2D::distance(this->getX(), this->getY(), nearestFish->getX(), nearestFish->getY()) <= getSight())
                {
                    changeState(CHASE);
                }
            }
            break;
        case CHASE:
            // Chase the nearest fish
            if (getX() > nearestFish->getX()) move(LEFT);
            else if (getX() < nearestFish->getX()) move (RIGHT);
            else if (getY() > nearestFish->getY()) move(UP);
            else if (getY() < nearestFish->getY()) move(DOWN);

            if (Vector2D::distance(this->getX(), this->getY(), nearestFish->getX(), nearestFish->getY()) > getSight()) changeState(IDLE);
            else if (Vector2D::distance(this->getX(), this->getY(), nearestFish->getX(), nearestFish->getY()) <= 0) changeState(ATTACK);
            break;
        case ATTACK:
            // Eats the fish
            for (std::vector<Fish*>::iterator i = fishes->begin(); i <= fishes->end(); i++)
            {
                if (nearestFish == *i)
                {
                    fishes->erase(i);
                    nearestFish = NULL;
                    break;
                }
            }
            changeState(IDLE);
            break;
        default:
            break;
    }

    if (fishes->size() > 0) searchFish();
    if (nearestFish == NULL) std::cout << "NULL" << std::endl;
    Agent::update();
}

void Shark::searchFish()
{
    for (int i = 0; i < fishes->size(); i++)
    {
        Fish* tempFish = (*fishes)[i];
        if (nearestFish != NULL)
        {
            int distA = Vector2D::distance(this->getX(), this->getY(), tempFish->getX(), tempFish->getY());
            int distB = Vector2D::distance(this->getX(), this->getY(), nearestFish->getX(), nearestFish->getY());
            if (distA < distB)
            {
                nearestFish = tempFish;
            }
        }
        else
        {
            nearestFish = tempFish;
        }
    }
}
