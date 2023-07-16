#include"display.h"

void display::OnLoop(SDL_Renderer* renderer){
    game->move(renderer);
}