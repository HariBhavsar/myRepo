#ifndef _CAPP_H_
#define _CAPP_H_
 
#include <SDL.h>
#include "defs.h"
#include "Game.h"

class display {
    private:
    bool running;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface * image;
    SDL_Texture * texture;
    Game* game;
    bool gameEndScreen = false;
    public:

    display();
    int OnExecute();
    
    bool OnInit();
  
    void OnEvent(SDL_Event* Event);
    void OnLoop(SDL_Renderer* renderer);
    void OnRender();
    void OnCleanup();
 
};
 
#endif