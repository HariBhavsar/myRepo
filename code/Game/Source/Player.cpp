#include"Player.h"
#include"display.h"
#include"defs.h"
#include"SDL.h"

Player::Player(): x(0), y(0),vel_x(0),vel_y(0){;}

Player::Player(int u, int v): x(u),y(v),vel_x(0),vel_y(0) {;}

int Player::get_x(){
    return x;
    }

int Player::get_y(){return y;}

void Player::inc_vel_x(int u){vel_x += u;}

void Player::inc_vel_y(int u){vel_y += u;}

void Player::move(){
    //int width,height;
    //SDL_GetWindowSize(window,&width,&height);
    if (x + vel_x < (3*WIDTH-100) && x + vel_x > 0) {
    x+=vel_x;
    }
    if (y + vel_y < 2*HEIGHT && y + vel_y > 0) {
    y+=vel_y;
    }
}