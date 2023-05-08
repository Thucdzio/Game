#include "Plane.h"

Plane::Plane()
{
	x_pos = 0;
	y_pos = SCR_HEIGHT / 2;

	val_x = 0;
	val_y = 0;


	width_frame = 0;
	height_frame = 0;
	status = 0;

	input_type.right = 0;
	input_type.left = 0;
	input_type.up = 0;
	input_type.down = 0;


}
Plane :: ~Plane()
{

}
bool Plane::LoadImg(string path, SDL_Renderer* screen)
{
	bool ac = Game::LoadImg(path, screen);
	if (ac == true) {

		width_frame = rect.w;
		height_frame = rect.h;
	}
	return ac;

}
void Plane::Show(SDL_Renderer* des)
{
	if (status == walk_left) {
		LoadImg("img//Left.png", des);
	}
	else if (status == walk_right)
	{
		LoadImg("img//Right.png", des);
	}
	else {
		LoadImg("img//Right.png", des);
	}
	rect.x = x_pos;
	rect.y = y_pos;

	SDL_Rect  renderquad = { rect.x, rect.y, rect.w,rect.h };
	SDL_RenderCopy(des, texture, NULL, &renderquad);
}
void Plane::Input_Player(SDL_Event envent, SDL_Renderer* screen)
{


	const Uint8* keyState = SDL_GetKeyboardState(NULL);

	if (keyState[SDL_SCANCODE_A]) {
		input_type.left = 1;
		status = walk_left;
	}
	else {
		input_type.left = 0;
	}
	if (keyState[SDL_SCANCODE_D]) {
		input_type.right = 1;
		status = walk_right;
	}
	else {
		input_type.right = 0;
	}
	if (keyState[SDL_SCANCODE_W]) {
		input_type.up = 1;
	}
	else input_type.up = 0;
	if (keyState[SDL_SCANCODE_S]) {
		input_type.down = 1;
	}
	else input_type.down = 0;
	if (keyState[SDL_SCANCODE_SPACE])
	{
		Amo* p_amo = new Amo();
		p_amo->LoadImg("img//amo.png", screen);
		if (status == walk_left)
		{
			p_amo->set_dir(Amo::DIR_LEFT);
			p_amo->Set_Rect(this->rect.x, rect.y + height_frame * 0.8);
		}
		else {
			p_amo->set_dir(Amo::DIR_RIGHT);
			p_amo->Set_Rect(this->rect.x + width_frame - 35, rect.y + height_frame * 0.8);
		}
		p_amo->set_x(20);
		p_amo->set_is_move(true);

		p_amo_list.push_back(p_amo);
	}
	if (keyState[SDL_SCANCODE_E]) {
		
		p_rocket.LoadImg("img//dan.png", screen);

		
		if (status == walk_left)
		{
			p_rocket.set_dir(Amo::DIR_LEFT);
			p_rocket.Set_Rect(this->rect.x, rect.y + height_frame * 0.8);
		}
		else {
			p_rocket.set_dir(Amo::DIR_RIGHT);
			p_rocket.Set_Rect(this->rect.x + width_frame - 35, rect.y + height_frame * 0.8);
		}
		p_rocket.set_x(3);
		p_rocket.set_is_move(true);
		
	}
	if (keyState[SDL_SCANCODE_Q])
	{

	}

}
void Plane::Amo_do(SDL_Renderer* des)
{
	for (int i = 0; i < p_amo_list.size(); i++)
	{
		Amo* p_amo = p_amo_list.at(i);
		if (p_amo != NULL)
		{
			if (p_amo->get_is_move() == true)
			{
				p_amo->Amo_Move(SCR_WIDTH, SCR_HEIGHT);
				p_amo->Render(des);
			}
			else
			{
				p_amo_list.erase(p_amo_list.begin() + i);
				if (p_amo != NULL) {

					delete p_amo;
					p_amo = NULL;
				}
			}
		}
	}
	
}
void Plane::doPlayer()
{
	val_x = 0;
	val_y = 0;
	if (input_type.left == 1)
	{
		val_x -= PLAYER_SPEED;
	}
	if (input_type.right == 1)
	{
		val_x += PLAYER_SPEED;
	}
	if (input_type.up == 1)
	{
		val_y -= PLAYER_SPEED;
	}
	if (input_type.down == 1)
	{
		val_y += PLAYER_SPEED;
	}
	x_pos += val_x;
	y_pos += val_y;
	x_pos = max(0, min(SCR_WIDTH - width_frame, x_pos));

	y_pos = max(0, min(SCR_HEIGHT - height_frame, y_pos));
}
void Plane::Remove_Amo(const int& id) {

	Amo* p_amo = p_amo_list.at(id);

	p_amo_list.clear();

	//p_amo_list.erase(p_amo_list.begin(), p_amo_list.begin() + id);
	//chay lai di anh
	// no van chua xoa anh dan di sau khi va cham
}
void Plane::do_Skill(SDL_Renderer* des) {
	

	
	p_rocket.Skill_Rocket(SCR_WIDTH, SCR_HEIGHT);
	p_rocket.Render(des);

}
void Plane::Clean_Amo()
{
	p_amo_list.clear();
}