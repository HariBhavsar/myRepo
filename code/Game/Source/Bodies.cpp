#include"Bodies.h"
#include"defs.h"
#include"Textures.h"
#include<iostream>
Bodies::Bodies(double u, double v, double w, double h,int type): x(u),y(v),wid(w),hei(h), type(type) {
    r = 0;
    g = 0;
    b = 0;
    o = 255;
    vel_x=0;
    vel_y = 0;
}

void Bodies::SetColour(int ri, int gi, int bi){
    r = ri;
    g = gi;
    b = bi;
    setDefaultHei();
}

void Bodies::SetVel(int ux, int uy){
    vel_x = ux;
    vel_y = uy;
}


bool Bodies::check_col(Bodies* B){
    if ((x< ( B->x + ( B->wid )) && (x + wid) > ( B->x))&& (y < ( B->y + (B->hei)) && (y + hei) > (B->y ))) {
        return true;
    }
    // TODO
    return false;  
}

void Bodies::display(SDL_Renderer* renderer){
    if (type != 0 && type !=4 && type != 1) {
    int xNew, yNew, widNew, heiNew;
    xNew = x/1;
    yNew = y/1;
    widNew = wid/1;
    heiNew = hei/1; 
    SDL_Rect fillRect = {xNew ,yNew ,widNew,heiNew};
    SDL_SetRenderDrawColor( renderer, r, g, b, o );
    SDL_RenderFillRect( renderer, &fillRect );
    }
    else {
        int xNew, yNew, widNew, heiNew;
        xNew = x/1;
        yNew = y/1;
        widNew = wid/1;
        heiNew = hei/1; 
        SDL_Rect fillRect = {xNew ,yNew ,widNew,heiNew};
        SDL_RenderCopy(renderer, texture, NULL, &fillRect);
        SDL_RenderPresent(renderer);
    }
}

void Bodies::move(){
    if(!(x+vel_x<0 || x+vel_x+wid>WIDTH)) {x+=vel_x; timeTracker++;}
    if(!(y+vel_y<0 || y+vel_y+hei>HEIGHT)) {y+=vel_y; timeTracker++;}
}

int Bodies::widthOfBody(){
    return wid;
}
int Bodies::heightOfBody(){
    return hei;
}

void Bodies::initialiseTextureAndImage(SDL_Renderer* renderer) {
    if (type == 0) {
        image = SDL_LoadBMP("pacman.bmp");
    }
    else if (type == 4) {
        image = SDL_LoadBMP("pipe.bmp");
    }
    else {
        image = SDL_LoadBMP("pipeUpsideDown.bmp");
    }
    texture = SDL_CreateTextureFromSurface(renderer, image);
}

void Bodies::clearUp(){
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
}

int Bodies::giveType(){
    return type;
}

int Bodies::giveTime() {
    return timeTracker;
}

void Bodies::resetTime() {
    timeTracker = 0;
    hei = defaultHei;
    y = defaultY;
}

void Bodies::changeHeight(){
    if (type == 1) {
        if (hei + timeTracker/20 >= maxHeight) {
            hasItReachedMaxHeight = false;
            timeTracker = 20;
        }
        if (hei - timeTracker/20 <= defaultHei) {
            hasItReachedMaxHeight = true;
            timeTracker = 20;
        }
        if (hei + timeTracker/20 < maxHeight && hasItReachedMaxHeight) {
            hei = hei + timeTracker/20;
        }
        else if (hei - timeTracker/20 > defaultHei) {
            hei = hei - timeTracker/20;
        }
    }
    else if (type == 4) {
        if (y - timeTracker/20 <= maxHeight) {
            hasItReachedMaxHeight = false;
            timeTracker = 20;
        }
        if (y + timeTracker/20 >= defaultY) {
            hasItReachedMaxHeight = true;
            timeTracker = 20;
        }
        if (y - timeTracker/20 > maxHeight && hasItReachedMaxHeight) {
            y = y - timeTracker/20;
            hei = HEIGHT - y;
        }
        else if (y + timeTracker/20 < defaultY) {
            y = y + timeTracker/20;
            hei = HEIGHT - y;
        }
    }
}

void Bodies::setDefaultHei(){
    defaultHei = hei;
    defaultY = y;
    defaultX = x;
    defaultWid = wid;
    if (type == 1) {
        maxHeight = HEIGHT/2 - 60;
    }
    else if (type == 4) {
        maxHeight = HEIGHT/2 + 60;
    }
}

void Bodies::resetPos(){
    x = defaultX;
    y = defaultY;
} 

int Bodies::giveColor() {
    return r;
}

int Bodies::giveColorGreen(){
    return g;
}