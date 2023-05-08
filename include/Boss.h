#pragma once
#ifndef BOSS_H_
#define BOSS_H_

#include "BASE_FUNCITION.h"
#include "Game.h"


class Boss : public Game
{
public :
	Boss();
	~Boss();
	enum walk_type
	{
		walk_right = 1,
		walk_left = -1,
	};

	bool LoadImg(string path, SDL_Renderer* screen);
	
	void setx(const int& xv) { x_val = xv; }
	int get_x_pos() { return rect.x; }
	void Show_Boss(SDL_Renderer* des);
	void do_Boss();
	bool checkBoss();
	void Skill_Boss();


private :
	int x_val;
	int status;


};
#endif // !BOSS_H_
