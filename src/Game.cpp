#include "Game.h"

Game* Game::instance = NULL;

Game::Game()
{
    running = true;
    step = false;

    if (!init()) quit();

    time = new Time();
    /*for (int i = 0; i < 5; i++)
        fishes.push_back(new Fish(rand() % GRID_WIDTH, rand() % GRID_HEIGHT, 10, 10, {250, 150, 0}));*/
    //shark = new Shark(0, 0, 10, 10, {100, 100, 200}, &fishes);
}

Game* Game::Instance()
{
    if (instance == NULL)
    {
        instance = new Game();
    }

    return instance;
}

void Game::mainLoop()
{
    while (running)
    {
        time->start();

        handleInput();
        update();
        render();

        //std::cout << time->getDeltaTime() << std::endl;

        time->end();
    }

    clean();
}

bool Game::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) return false;

	window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL) quit();

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) quit();

	return true;
}

void Game::quit()
{
    running = false;
}

void Game::handleInput()
{
    if (Input::Instance()->getKey(SDL_SCANCODE_ESCAPE) || Input::Instance()->windowCloseRequest())
        quit();

    step = Input::Instance()->getKey(SDL_SCANCODE_SPACE);
}

void Game::update()
{
    Input::Instance()->update();

    if (Input::Instance()->getKey(SDL_SCANCODE_RETURN) && fishes.size() < 5 )
        fishes.push_back(new Fish(rand() % GRID_WIDTH, rand() % GRID_HEIGHT, 10, 10, {250, 150, 0}));

    if (shark == NULL && Input::Instance()->getKey(SDL_SCANCODE_BACKSPACE) && fishes.size() > 0)
    {
        shark = new Shark(0, 0, 10, 10, {100, 100, 200}, &fishes);
    }

    if (step)
    {
        shark->update();
    }
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	// Draw grid lines
	if (DRAW_GRID) drawGrid();

	// Draw agents
	if (shark != NULL) shark->draw(renderer);

	for (unsigned int i = 0; i < fishes.size(); i++)
    {
        if (fishes[i] != NULL) fishes[i]->draw(renderer);
    }

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
    delete shark;
    delete time;

    Input::Instance()->clean();
    delete instance;
	if (renderer != NULL) SDL_DestroyRenderer(renderer);
	if (window != NULL) SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::drawGrid()
{
	// Set color to white
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	// Horizontal lines
	for (int i = 0; i < GRID_HEIGHT; i++)
	{
		SDL_RenderDrawLine(renderer, 0, i*CELL_SIZE, SCREEN_WIDTH, i*CELL_SIZE);
	}

	// Vertical lines
	for (int i = 0; i < GRID_WIDTH; i++)
	{
		SDL_RenderDrawLine(renderer, i*CELL_SIZE, 0, i*CELL_SIZE, SCREEN_HEIGHT);
	}
}

int Game::distance(Agent* a, Agent* b)
{
    return abs((a->getX() - b->getX()) + ((a->getY() - b->getY())));
}
