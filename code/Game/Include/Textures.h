#include"SDL.h"
class textureAndImage {
    public:
    SDL_Surface * image;
    SDL_Texture * texture;
    void initialise(SDL_Renderer* renderer);
    void clearUp();
};