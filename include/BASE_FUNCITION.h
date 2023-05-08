#pragma once
#ifndef FUNCTION_H_
#define FUNCTION_H_

#include<iostream>
#include <time.h>
#include<string>
#include<SDL_image.h>
#include <SDL.h>
#include<windows.h>
#include<string.h>
#include<vector>
#include "SDL_ttf.h"
#include<SDL_mixer.h>



using namespace std;

static SDL_Window* window = NULL;
static SDL_Renderer* screen = NULL;

static SDL_Event   event;

//Screen
const int FBS_GAME = 40;

const int SCR_WIDTH = 1460;
const int SCR_HEIGHT = 700;
const int SCR_BFF = 32;


const int r_color = 256;
const int g_color = 0;
const int b_color = 0;

const int NUM_THREAT = 10;
const int MAX_NUM_DIE = 3;

#define PLAYER_SPEED 10;
#define SCR_SPEED 1;


typedef struct input
{

	int left;
	int right;
	int up;
	int down;

	int pause;
	int start;
};

namespace SDL_FUNC
{
	bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
	int Checkfocus(int x, int y, const SDL_Rect& rect);
		
	
}
#endif