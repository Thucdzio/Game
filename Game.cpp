#include "Game.h"


Game::Game()
{
	texture = NULL;
	rect.x = 0; rect.y = 0;
	rect.h = 0; rect.w = 0;
}
Game::~Game() {
	Clean();
}

bool Game::LoadImg(string path, SDL_Renderer* screen) {

	SDL_Texture* new_tex = NULL;
	SDL_Surface* load_surface = IMG_Load(path.c_str());

	if (load_surface != NULL) {
		SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format, r_color, g_color, b_color));
		new_tex = SDL_CreateTextureFromSurface(screen, load_surface);
		if (new_tex != NULL) {

			rect.w = load_surface->w;
			rect.h = load_surface->h;
		}
		SDL_FreeSurface(load_surface);
	}
	texture = new_tex;

	return texture != NULL;
}
void Game::Render(SDL_Renderer* des)
{
	SDL_Rect  renderquad = { rect.x, rect.y, rect.w,rect.h };

	SDL_RenderCopy(des, texture, NULL, &renderquad);
}



void Game::Clean() {

	if (texture != NULL) {
		SDL_DestroyTexture(texture);
		texture = NULL;
		rect.h = 0;
		rect.w = 0;
	}
}