#pragma once
#ifndef MENU_H_
#define MENU_H_
#include "TextOB.h"
#include "BASE_FUNCITION.h"
#include "Game.h"
class Menu : public Game {
public:
    Menu();
    ~Menu();
    int showMenu(SDL_Renderer* screen);
    int renderTutorial(SDL_Renderer* des);
    int CheckReplay(SDL_Renderer * des);

private:
    Game g_image;
    Game img_tutorial;
};


#endif // !