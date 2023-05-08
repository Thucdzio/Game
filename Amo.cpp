#include "Amo.h"

Amo::Amo()
{
	x_val = 0;
	y_val = 0;

	is_move = false;

}
Amo::~Amo()
{

}
void Amo::Amo_Threat()
{
	rect.x -= 5;
	//cout << rect.x << endl;
	if (rect.x < 0) {
		is_move = false;
	}
}
void Amo::Amo_Move(const int& x_border, const int& y_border) {
	if (amo_dir == DIR_RIGHT)
	{
		rect.x += x_val;
		if (rect.x > x_border)
		{
			is_move = false;
		}
	}
	else if (amo_dir == DIR_LEFT)
	{
		rect.x -= x_val;
		if ((rect.x < 0)) is_move = false;

	}
}
void Amo::Skill_Rocket(const int& x_border, const int& y_border) {
	if (amo_dir == DIR_RIGHT)
	{
		rect.x += x_val;
		if (rect.x > x_border)
		{
			is_move = false;
		}
	}
	else if (amo_dir == DIR_LEFT)
	{
		rect.x -= x_val;
		if ((rect.x < 0)) is_move = false;

	}
}