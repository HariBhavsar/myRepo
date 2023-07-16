#ifndef _BODIES_H_
#define _BODIES_H_

#include"SDL.h"
#include<iostream>
class Bodies{
    public:
    Bodies(double u, double v, double w, double h, int type);
    bool check_col(Bodies* B);
    void display(SDL_Renderer* renderer);
    void SetColour(int ri, int gi, int bi);
    void SetVel(int ux, int uy);
    void move();
    int widthOfBody();
    int heightOfBody();
    double x,y;
    double vel_x,vel_y;
    SDL_Surface * image;
    SDL_Texture * texture;
    int giveColor();
    void initialiseTextureAndImage(SDL_Renderer* renderer);
    void clearUp();
    int giveType();
    int giveTime();
    void resetTime();
    void changeHeight();
    void setDefaultHei();
    void resetPos();
    int giveColorGreen();
    private:
    double wid,hei,maxHeight;
    int type;
    int r,g,b,o;
    int timeTracker  = 0;
    double defaultHei, defaultY, defaultX, defaultWid;
    bool hasItReachedMaxHeight = true;
};

#endif