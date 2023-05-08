#pragma once
#pragma once
#ifndef THREATS_H_
#define THREATS_H_

#include"BASE_FUNCITION.h"
#include "Game.h"
#include "Amo.h"
#include <vector>
class Threat : public Game
{
public:
	Threat();
	~Threat();

	void set_x(const int& xVal) { val_x = xVal; }
	void set_y(const int& yVal) { val_y = yVal; }

	void set_now(const int& xp, const int& yp) { x_pos = xp; y_pos = yp; }

	int  get_xpos() const { return x_pos; }
	int  get_ypos() const { return y_pos; }

	bool LoadImg(string path, SDL_Renderer* screen);

	void Show(SDL_Renderer* des);
	void doThreat();

	void set_amo_list(vector <Amo*> Amo_list);
	vector<Amo*> get_amo_list() const { return p_amo_list; }

	void Init_Amo(Amo* p_amo);
	void Amo_do(SDL_Renderer* des);

	void Reset_Amo(Threat* p_threat);

private:

	vector< Amo* > p_amo_list;
	int val_x;
	int val_y;

	int x_pos;
	int y_pos;

	int width_frame;
	int height_frame;

};
#endif // !THEATS_H_
