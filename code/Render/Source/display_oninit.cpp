#include"display.h"

bool display::OnInit(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
    
    window = SDL_CreateWindow("COLLIDE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

    if(window==NULL) {
        return false;
    }

    renderer = SDL_CreateRenderer(window,-1,0);
    	
    image = SDL_LoadBMP("test.bmp");
    	
    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
    if(renderer == NULL){
        return false;
    }

    game = new Game(renderer);

    return true;
}