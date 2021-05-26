#pragma once
#include "Music.h"
#include "Observer.h"
#include <SDL.h>

class Middle
{
protected:
	void notify(int  a, Mix_Music* sound) { observer->onNotify(a, sound); }

private:
	Music music;
	Observer* observer = &music;
};

class Ball : public Middle
{
	public:

		//1 == player hit
		//2 == missing ball
		void sound(int a, Mix_Music* sound) { notify(a, sound); }

		//sets the direction of the ball
		void check_move(int W, int H, SDL_Rect pl1, SDL_Rect pl2);
		SDL_Rect r;

		//get Score 1 player
		int getScore1(void) { return score1; }

		//get Score 2 player
		int getScore2(void) { return score2; }

		//set Score 1 and 2 player
		void setScore(void) { score1 = 0; score2 = 0; }

		void loadMusic(void);

		void deleteMusic(void);

		Mix_Music* boom;
		Mix_Music* beep;
		bool stop = true;
private:
	int score1 = 0;
	int score2 = 0;

	// ball movement check
	// if it is impossible to move, changes direction
	// if the racket is hit or the ball flew past, a sound is called
	void check(int W, int H, SDL_Rect pl1, SDL_Rect pl2);

	int speed_x = 5;
	int speed_y = 5;
	bool x_p = true;
	bool x_m = false;
	bool y_p = true;
	bool y_m = false;
	
};