#include "Pong.h"

void Game::keys()
{
	if (SDL_PollEvent(&event))
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			if (pl[0].pl.y > 0)
				pl[0].pl.y -= 30;
			break;
		case SDLK_DOWN:
			if (pl[0].pl.y < H - pl[0].pl.h)
				pl[0].pl.y += 30;
			break;
		case SDLK_w:
			if (pl[1].pl.y > 0 && !compute)
				pl[1].pl.y -= 30;
			break;
		case SDLK_s:
			if (pl[1].pl.y < H - pl[1].pl.h && !compute)
				pl[1].pl.y += 30;
			break;
		case SDLK_SPACE:
			if (!pause)
				pause = true;
			break;
		case SDLK_p:
			if (pause)
				pause = false;
			break;
		default:
			break;
		}
		if (event.type == SDL_QUIT)
			open = SDL_FALSE;
		if (event.key.keysym.sym == SDLK_ESCAPE)
			open = SDL_FALSE;
		if (event.key.keysym.sym == SDLK_1 || event.key.keysym.sym == SDLK_KP_1)
		{
			compute = true;
			playing = true;
		}
		if (event.key.keysym.sym == SDLK_2 || event.key.keysym.sym == SDLK_KP_2)
		{
			compute = false;
			playing = true;
		}
	}
}
