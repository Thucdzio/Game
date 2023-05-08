#include"Time.h"
#include"BASE_FUNCITION.h"
#include "Plane.h"

Time::Time()
{
	start_time = 0;
	pause_time = 0;

	is_start = false;
	is_pause = false;


}
Time :: ~Time()
{

}

void Time::start()
{
	is_start = true;
	is_pause = false;

	start_time = SDL_GetTicks();
}

void Time::stop()
{
	is_start = false;
	is_pause = false;

}
void Time::pause()
{
	if (is_start == true and is_pause == false)
	{
		is_pause = true;
		pause_time = SDL_GetTicks() - start_time;

	}
}
void Time::unpause()
{
	if (is_pause == true) {
		is_pause = false;
		start_time = SDL_GetTicks() - pause_time;
		pause_time = 0;
	}
}
int Time::Get_Time()
{
	if (is_start == true)
	{
		if (is_pause == true) {
			return pause_time;
		}
		else return SDL_GetTicks() - start_time;
	}
	return 0;
}
bool Time::paused()
{
	return is_pause;
}
bool Time::started()
{
	return is_start;
}
void input_Game(SDL_Event  event, SDL_Renderer* screen)
{

}