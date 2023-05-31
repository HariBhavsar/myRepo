#include"display.h"

void display::OnRender(){
    //SDL_SetRenderDrawColor(renderer,96,128,255,255); R value is 96 G is 128 B is 255 whats the last value??
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderClear(renderer);

    
    game->render(renderer);

    
    SDL_RenderPresent(renderer);
}

