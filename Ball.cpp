#include "Ball.h"

void Ball::loadMusic()
{
	Mix_OpenAudio(22050, AUDIO_S32, 2, 4096);

	boom = Mix_LoadMUS("boom.wav");
	beep = Mix_LoadMUS("beep.wav");
}

void Ball::check(int W, int H, SDL_Rect pl1, SDL_Rect pl2)
{
	if (r.x > pl1.x - r.w && (pl1.y <= r.y + r.h &&  r.y <= pl1.y + pl1.h))
	{
		x_p = false;
		sound(1, boom);
		if (speed_x < 20)
			speed_x++;
	}
	if (r.x > W)
	{
		score1++;
		sound(2, beep);
		r.x = W / 2;
		r.y = H / 2;
		speed_x = 5;
	}
	if (r.y > H - r.h)
		y_p = false;
	if (r.x < pl2.x + pl2.w && (pl2.y <= r.h + r.y && r.y <= pl2.y + pl2.h))
	{
		x_p = true;
		sound(1, boom);
		if (speed_x < 20)
			speed_x++;
	}
	if (r.x < 0)
	{
		score2++;
		sound(2, beep);
		r.x = W / 2;
		r.y = H / 2;
		speed_x = 5;
	}
	if (r.y < 0)
		y_p = true;
}

void Ball::check_move(int W, int H, SDL_Rect pl1, SDL_Rect pl2)
{
	check(W, H, pl1, pl2);
	if (x_p)
		r.x += speed_x;
	if (y_p)
		r.y += speed_y;
	if (!x_p)
		r.x -= speed_x;
	if (!y_p)
		r.y -= speed_y;
}

void Ball::deleteMusic()
{
	Mix_FreeMusic(boom);
	Mix_FreeMusic(beep);
}