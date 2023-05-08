#pragma once
#pragma once

#ifndef AMO_H
#define AMO_H

#include "Game.h"
#include "BASE_FUNCITION.h"
class Amo : public Game
{
public:
	Amo();
	~Amo();

	enum Amo_DIR
	{
		DIR_LEFT = 2,
		DIR_RIGHT = -2,
	};


	void set_x(const int& xVal) { x_val = xVal; }
	void set_y(const int& yVal) { y_val = yVal; }

	int get_x() const { return x_val; }
	int get_y() const { return y_val; }

	void set_is_move(const bool& Move) { is_move = Move; }
	bool get_is_move() const { return is_move; }

	void Amo_Move(const int& x_border, const int& y_border);
	void Amo_Threat();
	void Skill_Rocket(const int& x_border, const int& y_border);
	void set_dir(const int AmoDir) { amo_dir = AmoDir; }
	int get_dir() const { return amo_dir; }
private:
	int x_val;
	int y_val;

	bool is_move;

	int amo_dir;


};
#endif 
