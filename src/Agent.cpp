#include "Agent.h"

Agent::Agent(int px, int py, int psight, int plifetime, SDL_Color pcolor)
{
	x = px;
	y = py;
	sight = psight;
	lifetime = plifetime;
	color = pcolor;

	move_x = 0;
	move_y = 0;

	rect.x = x;
	rect.y = y;
	rect.w = CELL_SIZE;
	rect.h = CELL_SIZE;

	currentState = IDLE;
	nextState = currentState;
}

Agent::~Agent()
{
}

bool Agent::outOfScreen(int px, int py)
{
    if (px > GRID_WIDTH-1) return true;
	if (py > GRID_HEIGHT-1) return true;
	if (px < 0) return true;
	if (py < 0) return true;

	return false;
}

void Agent::move(DIRECTION dir)
{
	switch (dir)
	{
		case RIGHT: move_x = 1; move_y = 0; break;
		case LEFT: move_x = -1; move_y = 0; break;
		case DOWN: move_x = 0; move_y = 1; break;
		case UP: move_x = -0; move_y = -1; break;
		default: break;
	}

	x += move_x;
	y += move_y;
}

DIRECTION Agent::getRandomDirection()
{
    int r = rand() % possibleDirections.size();
    return possibleDirections[r];
}

void Agent::getPossibleDirections()
{
    if (outOfScreen(x+1, y) == false) possibleDirections.push_back(RIGHT);
    if (outOfScreen(x-1, y) == false) possibleDirections.push_back(LEFT);
    if (outOfScreen(x, y+1) == false) possibleDirections.push_back(DOWN);
    if (outOfScreen(x, y-1) == false) possibleDirections.push_back(UP);
}

/*void Agent::update()
{
    getPossibleDirections();
    DIRECTION dir = getRandomDirection();

    move(dir);

	x += move_x;
	y += move_y;

	// Clamp the x and y within the grid dimensions
	if (x > GRID_WIDTH-1) x = GRID_WIDTH-1;
	if (y > GRID_HEIGHT-1) y = GRID_HEIGHT-1;
	if (x < 0) x = 0;
	if (y < 0) y = 0;

	possibleDirections.clear();
}*/

void Agent::update()
{
    // Clamp the x and y within the grid dimensions
	if (x > GRID_WIDTH-1) x = GRID_WIDTH-1;
	if (y > GRID_HEIGHT-1) y = GRID_HEIGHT-1;
	if (x < 0) x = 0;
	if (y < 0) y = 0;
}

void Agent::draw(SDL_Renderer* renderer)
{
	rect.x = x * CELL_SIZE;
	rect.y = y * CELL_SIZE;

	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
	SDL_RenderFillRect(renderer, &rect);
}

void Agent::changeState(STATE next)
{
    if (nextState == currentState)
        nextState = next;
}
