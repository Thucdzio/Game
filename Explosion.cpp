#include "Explosion.h"

Explosion::Explosion()
{
	we = 0;
	he = 0;
	frame_ = 0;
}
Explosion:: ~Explosion()
{

}
bool Explosion::LoadImg(string path, SDL_Renderer* screen) {
	SDL_Texture* new_tex = NULL;
	SDL_Surface* load_surface = IMG_Load(path.c_str());

	if (load_surface != NULL) {
		SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format, r_color, g_color, b_color));
		new_tex = SDL_CreateTextureFromSurface(screen, load_surface);
		if (new_tex != NULL) {

			rect.w = load_surface->w / 4;
			rect.h = load_surface->h;
			we = rect.w;
			he = rect.h;
		}
		SDL_FreeSurface(load_surface);
	}
	texture = new_tex;

	return texture != NULL;
}
void Explosion::set_clip() {
	clip_[0].x = 0;
	clip_[0].y = 0;
	clip_[0].w = we;
	clip_[0].h = he;

	clip_[1].x = we;
	clip_[1].y = 0;
	clip_[1].w = we;
	clip_[1].h = he;


	clip_[2].x = 2 * we;
	clip_[2].y = 0;
	clip_[2].w = we;
	clip_[2].h = he;

	clip_[3].x = 3 * we;
	clip_[3].y = 0;
	clip_[3].w = we;
	clip_[3].h = he;

}

void Explosion::Show_Ex(SDL_Renderer* des)
{
	SDL_Rect* current_clip = &clip_[frame_];

	SDL_Rect render_quad = { rect.x,rect.y,rect.w,rect.h };

	SDL_RenderCopy(des, texture, current_clip, &render_quad);
}