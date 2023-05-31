#include"display.h"


bool display::OnInit(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
    
    window = SDL_CreateWindow("Changed the name?", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
    //SDL_GetWindowSize(window,&windowData.width,&windowData.height);
    if(window==NULL) {
        return false;
    }

    renderer = SDL_CreateRenderer(window,-1,0);

    if(renderer == NULL){
        return false;
    }

    game = new Game(WIDTH/2,HEIGHT/2);

    return true;
}