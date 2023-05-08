#include"Boss.h"

Boss::Boss() {
	x_val = 0;
	status = -1;
}
Boss :: ~Boss()
{

}

bool Boss::LoadImg(string path, SDL_Renderer* screen)
{
	bool ret = Game::LoadImg(path, screen);
	
	return ret;
}
void Boss::Show_Boss(SDL_Renderer* des)
{

	SDL_Rect  renderquad = { rect.x, rect.y, rect.w,rect.h };
	SDL_RenderCopy(des, texture, NULL, &renderquad);
	//cout << rect.x <<" " << rect.y << endl;
}

void Boss::do_Boss()
{
	
	if (rect.x < -100  and status == walk_left) {
		
		
		status = walk_right;
		
	}
	if (rect.x > SCR_WIDTH - 500 and status == walk_right)
	{
		status = walk_left;
		
	}
	if ( status == walk_left){
		rect.x -= x_val;
	}
	else if (status == walk_right )
	{
		rect.x += x_val;
	}
}
bool Boss::checkBoss()
{
	if (rect.x < -100 and status == walk_left) {
		status = walk_right;
		return true;
	}
	if (rect.x > SCR_WIDTH - 500 and status == walk_right)
	{
		status = walk_left;
		return false;
	}
	return true;
}