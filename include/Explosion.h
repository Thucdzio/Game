#pragma once
#pragma once
#ifndef EXPLOSION_H_
#define EXPLOSION_H_

#include"Game.h"
#include"BASE_FUNCITION.h"




class Explosion : public Game
{
public:
	Explosion();
	~Explosion();

	void set_clip();
	void set_frame(const int& fr) { frame_ = fr; }
	void Show_Ex(SDL_Renderer* des);
	bool LoadImg(string path, SDL_Renderer* screen);

private:
	int frame_;
	SDL_Rect clip_[4];
	int we; int he;

};

#endif // !EXPLOSION_H_
