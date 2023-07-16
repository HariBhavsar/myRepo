#include"Game.h"
#include"defs.h"
#include"Textures.h"
#include<iostream>

Game::Game(SDL_Renderer* renderer){
    running = true;
    timer= 0;
    int level;
    std::cout<<"enter the level \n";
    std::cin>>level;
    initialize(renderer,level);
}
void Game::initialize(SDL_Renderer* renderer, int levelCounter){

    //Clear the list of bodies
    while(listOfBodies.size()) listOfBodies.pop_back();

    //Add player
    if (levelCounter != 4 && levelCounter !=5) {
        Bodies* B = new Bodies(WIDTH/2-10,HEIGHT/2-10,20,20,0);
        B->SetColour(255,0,0);
        B->initialiseTextureAndImage(renderer);
        listOfBodies.push_back(B);
    }
    else {
        Bodies* B = new Bodies(10,HEIGHT/2-10,20,20,0);
        B->SetColour(255,0,0);
        B->initialiseTextureAndImage(renderer);
        listOfBodies.push_back(B);    
    }

    // Add one obstacle
    if (levelCounter == 1) { //type 1 is pipe
        gameLevel = 1;
        Bodies* pipe1 = new Bodies(WIDTH - 20,HEIGHT-60,20,60,4); //creates a bottom pipe, one that is at the bottom of the screen
        pipe1->SetColour(0,255,0);
        pipe1->SetVel(-5,0);
        pipe1->initialiseTextureAndImage(renderer);
        listOfBodies.push_back(pipe1);

        Bodies *movingBody = new Bodies(WIDTH-20,0,20,60,1);
        movingBody->SetColour(0,255,0);
        movingBody->SetVel(-5,0);
        movingBody->initialiseTextureAndImage(renderer);
        listOfBodies.push_back(movingBody);

        Bodies *movingReflector1 = new Bodies(WIDTH-60,HEIGHT/2-60,60,30,2);
        movingReflector1->SetColour(255,255,255);
        movingReflector1->SetVel(-5,0);
        listOfBodies.push_back(movingReflector1);

        Bodies *movingReflector2 = new Bodies(WIDTH-60,HEIGHT/2+30,60,30,2);
        movingReflector2->SetColour(255,255,255);
        movingReflector2->SetVel(-5,0);
        listOfBodies.push_back(movingReflector2);

        Bodies *gameOver = new Bodies(WIDTH - 20, HEIGHT - 20, 20,20,3);
        gameOver->SetColour(0,0,255);
        gameOver->SetVel(0,0);
        listOfBodies.push_back(gameOver);
    }
    else if (levelCounter == 2) {
        gameLevel = 2;

        Bodies *gameOver = new Bodies(WIDTH - 20, HEIGHT - 20, 20,20,3);
        gameOver->SetColour(0,0,255);
        gameOver->SetVel(0,-5);
        listOfBodies.push_back(gameOver);

        Bodies *reflector1 = new Bodies(WIDTH - 60, HEIGHT/2 - 20, 60, 40, 2);
        reflector1->SetColour(255,255,255);
        reflector1->SetVel(-5,0);
        listOfBodies.push_back(reflector1);
        for (int i=0; 20*i < WIDTH - 20; i+=4) {
            Bodies *reflector2 = new Bodies(20*i, 0, 20, 60, 2);
            reflector2->SetColour(255,255,255);
            reflector2->SetVel(0,5);
            listOfBodies.push_back(reflector2);
        }

        for (int i=0; 40*i < WIDTH - 40; i+=4) {
            Bodies *downPipe = new Bodies(i*40, HEIGHT - 80, 40, 80, 4);
            downPipe->SetColour(0,255,0);
            downPipe->SetVel(0,0);
            downPipe->initialiseTextureAndImage(renderer);
            listOfBodies.push_back(downPipe);
        }
        for (int i=0; 50*i < WIDTH - 20; i+=4) {
            Bodies *downPipe = new Bodies(i*40,0, 40, 80, 1);
            downPipe->SetColour(0,255,0);
            downPipe->SetVel(0,0);
            downPipe->initialiseTextureAndImage(renderer);
            listOfBodies.push_back(downPipe);
        }                                 
    }
    else if (levelCounter == 3) {
        gameLevel = 3;

        Bodies *gameOver = new Bodies(WIDTH - 20, HEIGHT - 20, 20,20,3);
        gameOver->SetColour(0,0,255);
        gameOver->SetVel(0,-5);
        listOfBodies.push_back(gameOver);

        for (int i=0; i*20 < HEIGHT - 20; i+=4) {
            Bodies *spawner = new Bodies(WIDTH - 50,20*i, 50, 20, 5);
            spawner->SetColour(255,0,255);
            spawner->SetVel(0,0);
            listOfBodies.push_back(spawner);            
        }

        for (int i=0; i*20<HEIGHT - 20; i+=4) {
            Bodies *spawned = new Bodies (WIDTH - 70, 20*i, 20, 20, 6);
            spawned->SetColour(0,255,0);
            spawned->SetVel(-8,0);
            listOfBodies.push_back(spawned);
        }

        for (int i=0; i*20<WIDTH - 20; i+=4) {
            Bodies *spawner = new Bodies (i*20, 0, 20, 50, 5);
            spawner->SetColour(255,0,255);
            spawner->SetVel(0,0);
            listOfBodies.push_back(spawner);
        }

        for (int i=0; i*20<WIDTH - 20; i+=4){
            Bodies *spawned = new Bodies (i*20,50,20,20,6);
            spawned->SetColour(0,255,0);
            spawned->SetVel(0,8);
            listOfBodies.push_back(spawned);
        }
    }
    else if (levelCounter == 4){

        gameLevel = 4;

        Bodies *gameOver = new Bodies(WIDTH - 20, HEIGHT - 40, 20,20,3);
        gameOver->SetColour(0,0,255);
        gameOver->SetVel(0,-5);
        listOfBodies.push_back(gameOver);

        Bodies *shield = new Bodies(WIDTH - 40, HEIGHT - 80, 20, 80, 2);
        shield->SetColour(255,255,255);
        shield->SetVel(0,-5);
        listOfBodies.push_back(shield);

        for (int i=0; 20*i < WIDTH - 60; i+=4) {
            Bodies *spawner = new Bodies (i*20, 0, 20, 50, 5);
            spawner->SetColour(255,0,255);
            spawner->SetVel(0,0);
            listOfBodies.push_back(spawner);            
        }
        for (int i=0; 20*i < WIDTH - 60; i+=4) {
            Bodies *spawned = new Bodies (i*20,50,20,20,6);
            spawned->SetColour(0,255,0);
            spawned->SetVel(0,10);
            listOfBodies.push_back(spawned);            
        }

        Bodies *laser = new Bodies(WIDTH/2 - 20, 0, 20, HEIGHT, 7);
        laser->SetColour(0,255,0);
        laser->SetVel(0,0);
        listOfBodies.push_back(laser);

        Bodies *laser2 = new Bodies(0,HEIGHT - 20, WIDTH, 20, 7);
        laser2->SetColour(0,255,0);
        laser2->SetVel(0,0);
        listOfBodies.push_back(laser2);        
    }

    else if (levelCounter == 5){
        gameLevel = 5;
        coinCounter = 0;
        
        Bodies *coin = new Bodies(100,0,20,30,8);
        coin->SetColour(255,215,0);
        coin->SetVel(0,0);
        listOfBodies.push_back(coin);

        Bodies *coin2 = new Bodies(300,0,20,30,8);
        coin2->SetColour(255,215,0);
        coin2->SetVel(0,0);
        listOfBodies.push_back(coin2);
        
        Bodies *coin3 = new Bodies(500,0,20,30,8);
        coin3->SetColour(255,215,0);
        coin3->SetVel(0,0);
        listOfBodies.push_back(coin3); 

        Bodies *coin4 = new Bodies(150,HEIGHT - 30,20,30,8);
        coin4->SetColour(255,215,0);
        coin4->SetVel(0,0);
        listOfBodies.push_back(coin4);  

        Bodies *coin5 = new Bodies(450,HEIGHT - 30,20,30,8);
        coin5->SetColour(255,215,0);
        coin5->SetVel(0,0);
        listOfBodies.push_back(coin5);

        for (int i=0; i<3; i++) {
            Bodies *reflector = new Bodies(80 + 200*i,30, 60, 20, 2);
            reflector->SetColour(255,255,255);
            reflector->SetVel(0,0);
            listOfBodies.push_back(reflector);
        }
        for (int i=0; i<2; i++) {
            Bodies *reflector2 = new Bodies(130 + 300*i,HEIGHT -50, 60, 20,2);
            reflector2->SetColour(255,255,255);
            reflector2->SetVel(0,0);
            listOfBodies.push_back(reflector2); 
        }

        Bodies *lockedButton = new Bodies(WIDTH/2-10, HEIGHT/2 - 10, 20,20,9);
        lockedButton->SetColour(255,255,255);
        lockedButton->SetVel(0,0);
        listOfBodies.push_back(lockedButton);

        for (int i=0; i<2; i++) {
            Bodies *laser = new Bodies (0,60 + 340*i,WIDTH,20,7);
            laser->SetColour(0,255,0);
            laser->SetVel(0,0);
            listOfBodies.push_back(laser);
        }

        for (int i=0; i<3; i++) {
            Bodies *cannons = new Bodies(WIDTH - 50, 160 + i*80, 50, 20, 5);
            cannons->SetColour(255,0,255);
            cannons->SetVel(0,0);
            listOfBodies.push_back(cannons);
        }
        for (int i=0; i<3; i++) {
            Bodies *cannonball = new Bodies(WIDTH - 70, 160 + i*80, 20, 20, 6);
            cannonball->SetColour(0,255,0);
            cannonball->SetVel(-8,0);
            listOfBodies.push_back(cannonball);
        }
        for (int i=0; i<3; i++) {
            Bodies *pipe = new Bodies(60 + 260*i, HEIGHT - 60,20,60,4);
            pipe->SetColour(0,255,0);
            pipe->initialiseTextureAndImage(renderer);
            pipe->SetVel(0,0);
            listOfBodies.push_back(pipe);
        }
        for (int i=0; i<2; i++) {
            Bodies *pipe = new Bodies(180 + 200*i, 0, 20,60,1);
            pipe->SetColour(0,255,0);
            pipe->initialiseTextureAndImage(renderer);
            pipe->SetVel(0,0);
            listOfBodies.push_back(pipe);
        }
    }
    else {
        gameLevel = 6;
        while(listOfBodies.size()) listOfBodies.pop_back();
    }
}

void Game::key_down(SDL_KeyboardEvent* event ,  SDL_Renderer* renderer){//when key is pressed

    if(event->repeat==0){
        // Press any key to restart game
        if(timer>RESET_TIME && !running){ 
            running = true;
            initialize(renderer,gameLevel);
        }
        switch (event->keysym.scancode){
            case SDL_SCANCODE_UP:
                listOfBodies[0]->vel_y=-5;
                break;

            case SDL_SCANCODE_DOWN:
                listOfBodies[0]->vel_y=5;
                break;

            case SDL_SCANCODE_LEFT:
                listOfBodies[0]->vel_x=-5;
                break;

            case SDL_SCANCODE_RIGHT:
                listOfBodies[0]->vel_x=5;   
                break;
            default:
                break;
        }
    }
}


void Game::key_up(SDL_KeyboardEvent* event ){//when the key stops being pressed
    if(event->repeat==0){
        switch (event->keysym.scancode){
            case SDL_SCANCODE_UP:
                listOfBodies[0]->vel_y=5;
                break;
            case SDL_SCANCODE_DOWN:
                listOfBodies[0]->vel_y=5;
                break;
            case SDL_SCANCODE_LEFT:
                listOfBodies[0]->vel_x=0;
                break;
            case SDL_SCANCODE_RIGHT:
                listOfBodies[0]->vel_x=0;   
                break;
            default:
                break;
        }
    }
}


void Game::move(SDL_Renderer* renderer){
    if(running){
        //move the bodies
        for(long unsigned int i=0; i<listOfBodies.size();i++){
            listOfBodies[i]->move();
            listOfBodies[i]->changeHeight();
            if (listOfBodies[i]->giveType() != 3) {
                if (listOfBodies[i]->giveType()!=0){
                    if (listOfBodies[i]->x + listOfBodies[i]->widthOfBody() + listOfBodies[i]->vel_x > WIDTH) {
                        listOfBodies[i]->vel_x = -5;
                        if (listOfBodies[i]->giveType() == 6){
                            listOfBodies[i]->vel_x = -8;
                        }
                    }
                    else if (listOfBodies[i]->x + listOfBodies[i]->vel_x < 0) {
                        if (listOfBodies[i]->giveType() == 6){
                            listOfBodies[i]->resetPos();
                        }
                        listOfBodies[i]->vel_x = 5;
                    }
                    if (listOfBodies[i]->y + listOfBodies[i]->vel_y <0) {
                        listOfBodies[i]->vel_y = 5;
                        if (listOfBodies[i]->giveType() == 6){
                            listOfBodies[i]->vel_y = 8;
                        }
                    }
                    else if (listOfBodies[i]->y + listOfBodies[i]->heightOfBody() + listOfBodies[i]->vel_y >HEIGHT) {
                        if (listOfBodies[i]->giveType() == 6){
                            listOfBodies[i]->resetPos();
                        }
                        listOfBodies[i]->vel_y = -5;
                    }                    
                    else if (listOfBodies[i]->giveType() == 2) {
                        if (listOfBodies[i]->vel_x > 0 ) {
                            listOfBodies[i]->vel_x += 0.07;
                        }
                        else if (listOfBodies[i]->vel_x < 0) {
                            listOfBodies[i]->vel_x -= 0.07;
                        }
                    }
                }
            }
            else {
                if (gameLevel == 2 || gameLevel == 3) {
                    if (listOfBodies[i]->y + listOfBodies[i]->vel_y <0) {
                        listOfBodies[i]->vel_y = 5;
                    }
                    else if (listOfBodies[i]->y + listOfBodies[i]->heightOfBody() + listOfBodies[i]->vel_y >HEIGHT) {
                        listOfBodies[i]->vel_y = -5;
                    }
                }
                if (gameLevel == 4) {
                    if (listOfBodies[2]->vel_y == 5) {
                        listOfBodies[i]->vel_y = 5;
                    }
                    else if (listOfBodies[2]->vel_y == -5) {
                        listOfBodies[i]->vel_y = -5;
                    }
                }
            }
        }

        //check for collision
        for(long unsigned int i=1; i<listOfBodies.size();i++){
            if(listOfBodies[0]->check_col(listOfBodies[i]))
            {
                if (listOfBodies[i]->giveType() == 1 || listOfBodies[i]->giveType() == 4 || listOfBodies[i]->giveType() == 5 || listOfBodies[i]->giveType() == 6) {
                    while (listOfBodies.size()) {
                        listOfBodies.pop_back();
                    }
                    running = false;
                    timer = RESET_TIME + 1;
                    break;
                }
                else if (listOfBodies[i]->giveType() == 2) {
                    for (int u=0; u<2; u++) {
                        if (listOfBodies[0]->x-listOfBodies[0]->vel_x > 0 && listOfBodies[0]->x - listOfBodies[0]->vel_x < WIDTH) {
                            listOfBodies[0]->x -= listOfBodies[0]->vel_x;
                        }
                        else {
                           while (listOfBodies.size()) {
                                listOfBodies.pop_back();
                            }
                            running = false;
                            timer = RESET_TIME + 1;
                            break; 
                        }
                        if (listOfBodies[0]->y - listOfBodies[0]->vel_y > 0 && listOfBodies[0]->y - listOfBodies[0]->vel_y < HEIGHT) {
                            listOfBodies[0]->y -= listOfBodies[0]->vel_y;
                        }
                        else {
                           while (listOfBodies.size()) {
                                listOfBodies.pop_back();
                            }
                            running = false;
                            timer = RESET_TIME + 1;
                            break;                             
                        }
                    }
                }
                else if (listOfBodies[i]->giveType() == 8) {
                    if (listOfBodies[i]->giveColorGreen() == 215) {
                        coinCounter++;
                        if (coinCounter == 5) {
                            listOfBodies[11]->SetColour(0,0,255);
                        }
                    }
                    listOfBodies[i]->SetColour(255,0,0);
                }
                else if (listOfBodies[i]->giveType() == 7) {
                    if (listOfBodies[i]->giveColor() == 0) {
                        listOfBodies[i]->SetColour(0,255,0);
                        while (listOfBodies.size()) {
                            listOfBodies.pop_back();
                        }
                        running = false;
                        timer = RESET_TIME + 1;
                        break;          
                    }
                }
                else if (listOfBodies[i]->giveType() == 9) {
                    if (coinCounter < 5) {
                        for (int u=0; u<2; u++) {
                            if (listOfBodies[0]->x-listOfBodies[0]->vel_x > 0 && listOfBodies[0]->x - listOfBodies[0]->vel_x < WIDTH) {
                                listOfBodies[0]->x -= listOfBodies[0]->vel_x;
                            }
                            else {
                               while (listOfBodies.size()) {
                                    listOfBodies.pop_back();
                                }
                                running = false;
                                timer = RESET_TIME + 1;
                                break; 
                            }
                            if (listOfBodies[0]->y - listOfBodies[0]->vel_y > 0 && listOfBodies[0]->y - listOfBodies[0]->vel_y < HEIGHT) {
                                listOfBodies[0]->y -= listOfBodies[0]->vel_y;
                            }
                            else {
                                while (listOfBodies.size()) {
                                    listOfBodies.pop_back();
                                }
                                running = false;
                                timer = RESET_TIME + 1;
                                break;                             
                            }
                        }                        
                    }
                    else {
                        gameLevel++;
                        initialize(renderer,gameLevel);                        
                    }
                }
                else {
                    gameLevel++;
                    initialize(renderer,gameLevel);
                }
            }
        }
    }
    else timer++;
}

//render
void Game::render(SDL_Renderer* renderer, bool &gameEndScreen){
    if(running){
        if (gameLevel == 6) {
            gameEndScreen = true;
        }
        for(long unsigned int i=0; i<listOfBodies.size();i++){
            if (listOfBodies[i]->giveType() == 7) {
                if (gameLevel == 4) {
                    if (listOfBodies[i]->giveTime() % 300 <= 60) {
                        listOfBodies[i]->SetColour(255,0,0);
                    }
                    else {
                        listOfBodies[i]->SetColour(0,255,0);
                    }
                }
                else {
                    if (listOfBodies[i]->giveTime()%500 <= 150) {
                        listOfBodies[i]->SetColour(255,0,0);
                    }
                    else {
                        listOfBodies[i]->SetColour(0,255,0);
                    }
                }
            }
            listOfBodies[i]->display(renderer);
        }
    }
}
