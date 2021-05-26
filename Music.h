#pragma once
#include "Observer.h"
#include <SDL_mixer.h>
#include <SDL.h>

class Music : public Observer
{
public:
	virtual void onNotify(int a, Mix_Music* sound)
	{
		if (a == 1)
			Mix_PlayMusic(sound, 1);
		if (a == 2)
			Mix_PlayMusic(sound, 2);
	}
};


