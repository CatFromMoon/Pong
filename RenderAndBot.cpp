#include "Pong.h"

void Game::Compute(void)
{
	int rnd = rand() % 10 + 1;
	int tik = SDL_GetTicks() / 100;
	if (tik % 2 == 0 && tik > 1)
	{
		if (rnd <= 6)
		{
			if (pl[1].pl.y > 0 && pl[1].pl.y > b.r.y)
				pl[1].pl.y -= 30;
			else if (pl[1].pl.y < H - pl[1].pl.h && (pl[1].pl.y + pl[1].pl.h < b.r.y + b.r.h))
				pl[1].pl.y += 30;
		}
		else if (7 == rnd)
		{
			if (pl[1].pl.y > 0)
				pl[1].pl.y -= 30;
		}
		else if (8 == rnd)
		{
			if (pl[1].pl.y < H - pl[1].pl.h)
				pl[1].pl.y += 30;
		}
		else if (9 <= rnd && rnd <= 10)
			pl[1].pl.y;
	}
}

void Game::playingTrue()
{
	if (!pause)
		b.check_move(W, H, pl[0].pl, pl[1].pl);
	if (compute)
		Compute();
	SDL_RenderClear(render);
	SDL_RenderCopy(render, ball, NULL, &b.r);
	SDL_RenderCopy(render, player1, NULL, &pl[0].pl);
	SDL_RenderCopy(render, player2, NULL, &pl[1].pl);
	SDL_RenderCopy(render, text[3].Message, NULL, &text[3].Message_rect);
	SDL_RenderCopy(render, text[4].Message, NULL, &text[4].Message_rect);
	SetLine();
	if (b.getScore1() == 12 || b.getScore2() == 12)
	{
		b.setScore();
		pl[0].pl.y = H / 2 - pl[0].pl.h / 2;
		pl[1].pl.y = H / 2 - pl[1].pl.h / 2;
		SDL_Delay(5000);
		playing = false;
	}
	SDL_RenderPresent(render);
	if (b.stop)
	{
		SDL_Delay(2000);
		b.stop = false;
	}
}

void Game::playingFalse()
{
	SDL_RenderClear(render);
	SDL_RenderCopy(render, text[0].Message, NULL, &text[0].Message_rect);
	SDL_RenderCopy(render, text[1].Message, NULL, &text[1].Message_rect);
	SDL_RenderCopy(render, text[2].Message, NULL, &text[2].Message_rect);
	SDL_RenderPresent(render);
}

void Game::EventAndRender()
{
	playing ? playingTrue() : playingFalse();
}