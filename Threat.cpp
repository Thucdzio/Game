#include "Threat.h"

Threat::Threat()
{
	val_x = 0;
	val_y = 0;

	x_pos = SCR_WIDTH;
	y_pos = SCR_HEIGHT * 0.5;

	width_frame = 0;
	height_frame = 0;

}
Threat  :: ~Threat()
{

}

bool Threat::LoadImg(string path, SDL_Renderer* screen)
{
	bool ret = Game::LoadImg(path, screen);
	if (ret == true)
	{
		width_frame = rect.w;
		height_frame = rect.h;
	}// cai amo can ham load nua ha anh dau can dau ok anh
	return ret;
}
void Threat::Init_Amo(Amo* p_amo) {
	//bool ret = p_amo->LoadImg("img//threat.png", screen);
	if (p_amo != NULL) {
		//bool ret = p_amo->LoadImg("img//threat.png", screen);

		//if (ret == false) cout << "fff" << endl;
		p_amo->set_is_move(true);
		rect.x = x_pos;
		rect.y = y_pos;
		p_amo->Set_Rect(rect.x, rect.y + height_frame * 0.6);
		//cout << rect.x << " " << rect.y << endl;
		p_amo->set_is_move(true);
		p_amo_list.push_back(p_amo);

	}

}
void Threat::Amo_do(SDL_Renderer* des)
{
	for (int i = 0; i < p_amo_list.size(); i++) {
		Amo* p_amo = p_amo_list.at(i);
		if (p_amo)
		{
			if (p_amo->get_is_move() == true)
			{
				p_amo->Amo_Threat();
				p_amo->Render(des);

			}
			else
			{
				p_amo->set_is_move(true);
				p_amo->Set_Rect(rect.x, rect.y + height_frame * 0.8);
			}
		}
	}
}
void Threat::Show(SDL_Renderer* des)
{
	rect.x = x_pos;
	rect.y = y_pos;

	SDL_Rect  renderquad = { rect.x, rect.y, rect.w,rect.h };
	//cout << rect.x << ' ' << rect.y << ' ' << rect.w << ' ' << rect.h << '\n';
	SDL_RenderCopy(des, texture, NULL, &renderquad);
}
void Threat::doThreat()
{
	x_pos -= val_x;
	if (x_pos < 0) x_pos = SCR_WIDTH;

	y_pos += val_y;
	
}


void Threat::Reset_Amo(Threat* p_threat)
{
	Sleep(1);
	p_amo_list.clear();

}