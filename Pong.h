#pragma once

#include "SDL.h"
#include <stdio.h>
#include <iostream>
#include "SDL_image.h"
#include "Ball.h"
#include "Player.h"
#include <vector>
#include "SDL_ttf.h"
#include "Text.h"
#include <string> 
#include <cstdlib>


#define W 720
#define H 720


class Game 
{

public:
	// initialization of the window and the starting coordinates of the ball
	void initAll();

	//launches the game or start window
	void EventAndRender();


	SDL_bool open;

	//removes window and player textures
	void DeleteAll();


	virtual ~Game() {};

	// sets the starting coordinates of the players
	void setPlayer();

	// sets the coordinates of the text and text for the start window
	void setText();
	
	// draws player scores
	void setScoreAndLine();

	// removes player scores
	void DeleteText();

	// keyboard events
	void keys();

private:
	//bot
	void Compute(void);

	void SetLine(void);

	// draws the start window
	void playingFalse();

	// draws the game process
	void playingTrue();

	bool pause;
	std::vector<Player> pl;
	SDL_Surface* surface;
	SDL_Window* window;
	SDL_Renderer* render;
	SDL_Event event;
	SDL_Surface* image;
	SDL_Texture* ball;
	SDL_Texture* player1;
	SDL_Texture* player2;
	Ball b;
	//text
	std::vector<Text> text;
	TTF_Font* Sans;
	SDL_Color Color;
	bool playing;
	bool compute;
};

int Run();