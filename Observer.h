#pragma once
#include <SDL_mixer.h>

class Observer
{
public:
	virtual ~Observer() {}
	virtual void onNotify(int a, Mix_Music* sound) = 0;
};