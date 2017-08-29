#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "globals.h"
#include "Time.h"
#include "Input.h"
#include "Agent.h"
#include "Shark.h"
#include "Fish.h"

class Game
{
    public:
        Game();

        static Game* Instance();

        void mainLoop();

        bool init();
        void quit();
        void handleInput();
        void update();
        void render();
        void clean();

        void drawGrid();

        int distance(Agent*, Agent*);

        std::vector<Fish*> getFishes() { return fishes; }

    private:
        ~Game() {}

        static Game* instance;

        const bool DRAW_GRID = true;

        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;
        bool running;
        bool step;
        Time* time;
        Shark* shark;
        std::vector<Fish*> fishes;
};

/*
    PARA FAZER:
    Da um jeito no estado CHASE do tubarao.
    Tem que achar uma maneira dele encontrar o peixe mais próximo.
    Não dá pra usar métodos do Game na classe Shark, porque você teria que
    dar um include nela, e isso com certeza vai dar merda.
    Boa sorte ae. Termina isso logo, carai!
*/

#endif // GAME_H
