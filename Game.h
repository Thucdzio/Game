#pragma once
#ifndef GAME_H_
#define GAME_H_

#include"BASE_FUNCITION.h"


class  Game
{
public:
	Game();
	~Game();
	void Set_Rect(const int& x, const int& y) {
		rect.x = x;
		rect.y = y;
	}
	SDL_Rect GetRect() const { return rect; }
	SDL_Texture* GetTexture() const { return texture; }

	virtual bool LoadImg(string path, SDL_Renderer* screen);
	
	void Render(SDL_Renderer* des);
	void Clean();
protected:
	SDL_Texture* texture;
	SDL_Rect  rect;
};
#endif // !
