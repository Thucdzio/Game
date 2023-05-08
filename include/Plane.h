#pragma once
#pragma once
#ifndef PLANE_H_
#define PLANE_H_

#include"BASE_FUNCITION.H"
#include"Game.h"
#include "Amo.h"

class Plane : public Game
{
public:
	Plane();
	~Plane();
	enum walk_type
	{
		walk_right = 1,
		walk_left = -1,
	};
	bool LoadImg(string path, SDL_Renderer* screen);
	void Show(SDL_Renderer* des);
	void Input_Player(SDL_Event  event, SDL_Renderer* screen);

	void doPlayer();

	void set_amo_list(vector <Amo*> Amo_list);
	vector<Amo*> get_amo_list() const { return p_amo_list; }
	void Amo_do(SDL_Renderer* des);
	void set_now(const int& x, const int& y) { x_pos = x, y_pos = y; }
	void Remove_Amo(const int& id);
	void Clean_Amo();
	void do_Skill(SDL_Renderer* des);


private:
	vector<Amo*> p_amo_list;
	Amo  p_rocket;
	int val_x;
	int val_y;

	int x_pos;
	int y_pos;


	input input_type;

	int width_frame;
	int height_frame;
	int status;

};

#endif