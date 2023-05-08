#include"PLAYER_PW.h"

Health::Health()
{
	number_ = 0;
}
Health :: ~Health()
{

}
void Health::AddPos(const int & xp)
{
	pos_list.push_back(xp);

}
void Health::Show(SDL_Renderer * screen)

{
	for (int i = 0; i < pos_list.size(); i++)
	{
		rect.x = pos_list.at(i);
		rect.y = 0;
		Render(screen);
	}

}
void Health::Init(SDL_Renderer * screen)
{
	bool t  = LoadImg("img//mang.png", screen);
	if (t == NULL) cout << " Hee" << endl;
	number_ = 3;
	if (pos_list.size() > 0)
	{
		pos_list.clear();
	}
	AddPos(20);
	AddPos(60);
	AddPos(100);
}
void Health::Decrease()
{
	number_--;
	pos_list.pop_back();
}