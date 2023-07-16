#include"Bodies.h"
#include<vector>
#include"SDL.h"

#define RESET_TIME 200

class Game{
    public:
    Game(SDL_Renderer* renderer);
    void initialize(SDL_Renderer* renderer, int levelCounter);
    void key_down(SDL_KeyboardEvent* event , SDL_Renderer* renderer );
    void key_up(SDL_KeyboardEvent* event );
    void move(SDL_Renderer* renderer);
    void render(SDL_Renderer* renderer, bool &gameEndScreen);

    private:
    int timer;
    std::vector<Bodies*> listOfBodies;
    bool running;
    int gameLevel = 1;
    int coinCounter = 0;
};