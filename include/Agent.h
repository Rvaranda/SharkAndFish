#ifndef AGENT_H
#define AGENT_H

#include <SDL.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include "globals.h"

enum DIRECTION
{
    STOP,
    RIGHT,
    UP,
    LEFT,
    DOWN
};

enum STATE
{
    IDLE,
    CHASE,
    FLEE,
    ATTACK,
    REPRODUCE
};

class Agent
{
	public:
        Agent(int, int, int, int, SDL_Color);
		virtual ~Agent();

		virtual void update() = 0;
		void draw(SDL_Renderer*);

		int getX() { return x; }
		int getY() { return y; }
		int getSight() { return sight; }

    protected:
        void move(DIRECTION);
		DIRECTION getRandomDirection();
		void getPossibleDirections();
		void changeState(STATE);

		STATE currentState, nextState;

	private:
	    bool outOfScreen(int, int);
		int x, y, sight, lifetime;
		int move_x, move_y;
		SDL_Color color;
		SDL_Rect rect;
		std::vector<DIRECTION> possibleDirections;
};

#endif // AGENT_H
