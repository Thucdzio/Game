#pragma once
#pragma once
#ifndef TIME_H
#define TIME_H

#include"BASE_FUNCITION.h"

class Time
{
public:
	Time();
	~Time();

	void start();
	void pause();
	void unpause();
	void stop();

	bool started();
	bool paused();

	int Get_Time();
	void Input_Game(SDL_Event  event, SDL_Renderer* screen);
private:

	int start_time;
	int pause_time;

	bool  is_pause;
	bool is_start;



};




#endif // !TIME_H
