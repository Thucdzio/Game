#pragma once
#ifndef PLAYER_PW_H_
#define PLAYER_PW_H_

#include "BASE_FUNCITION.h"
#include "Game.h"
class Health : public Game
{
public:
	Health();
	~Health();

	void SetNum(const int& num) { number_ = num; }
	void AddPos(const int& xp);
	void Show(SDL_Renderer* screen);
	void Init(SDL_Renderer* screen);
	void Decrease();

private:
	int number_;
	vector < int > pos_list;
};
#endif // !PLAYER_PW_H_
