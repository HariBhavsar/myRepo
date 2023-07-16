#include"display.h"
#include<iostream>
void display::OnRender(){
    
    if (!gameEndScreen) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderClear(renderer);
        //SDL_RenderCopy(renderer, texture, NULL, NULL);
        //SDL_RenderPresent(renderer);
        game->render(renderer, gameEndScreen);
        SDL_RenderPresent(renderer);        
    }
    else {
        image = SDL_LoadBMP("endscreen.bmp");
    	
        texture = SDL_CreateTextureFromSurface(renderer, image);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);            
    }
}

