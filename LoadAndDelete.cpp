#include "Pong.h"
void Game::setScoreAndLine()
{
	Text t;
	text.push_back(t);
	text.push_back(t);
	text.push_back(t);
	Color = { 255, 255, 255 };
	//score 1
	std::string str1 = std::to_string(b.getScore1());
	text[3].surfaceMessage = TTF_RenderText_Solid(Sans, str1.c_str(), Color);
	text[3].Message = SDL_CreateTextureFromSurface(render, text[3].surfaceMessage);
	text[3].Message_rect.x = W / 2 - 150;
	text[3].Message_rect.y = 0;
	text[3].Message_rect.w = 100;
	text[3].Message_rect.h = 100;
	//score 2
	std::string str2 = std::to_string(b.getScore2());
	text[4].surfaceMessage = TTF_RenderText_Solid(Sans, str2.c_str(), Color);
	text[4].Message = SDL_CreateTextureFromSurface(render, text[4].surfaceMessage);
	text[4].Message_rect.x = W / 2 + 50;
	text[4].Message_rect.y = 0;
	text[4].Message_rect.w = 100;
	text[4].Message_rect.h = 100;
	//Line
	Color = { 255, 255, 0 };
	text[5].surfaceMessage = TTF_RenderText_Solid(Sans, "|", Color);
	text[5].Message = SDL_CreateTextureFromSurface(render, text[5].surfaceMessage);
	text[5].Message_rect.x = W / 2 - 5;
	text[5].Message_rect.y = 0;
	text[5].Message_rect.w = 10;
	text[5].Message_rect.h = 10;
}

void Game::setText()
{
	Text t;
	text.push_back(t);
	text.push_back(t);
	text.push_back(t);
	TTF_Init();
	Sans = TTF_OpenFont("1.ttf", 24);
	Color = { 255, 0, 0 };
	text[0].surfaceMessage = TTF_RenderText_Solid(Sans, "Press:", Color);
	//text 1
	text[0].Message = SDL_CreateTextureFromSurface(render, text[0].surfaceMessage);
	text[0].Message_rect.x = 0;
	text[0].Message_rect.y = 0;
	text[0].Message_rect.w = 300;
	text[0].Message_rect.h = 200;
	//text 2
	text[1].surfaceMessage = TTF_RenderText_Solid(Sans, "1 for single player", Color);
	text[1].Message = SDL_CreateTextureFromSurface(render, text[1].surfaceMessage);
	text[1].Message_rect.x = 0;
	text[1].Message_rect.y = 200;
	text[1].Message_rect.w = W;
	text[1].Message_rect.h = 200;
	// text 3
	text[2].surfaceMessage = TTF_RenderText_Solid(Sans, "2 for multiplayer", Color);
	text[2].Message = SDL_CreateTextureFromSurface(render, text[2].surfaceMessage);
	text[2].Message_rect.x = 0;
	text[2].Message_rect.y = 400;
	text[2].Message_rect.w = W;
	text[2].Message_rect.h = 200;

}

void Game::initAll()
{
	b.r.x = W / 2 - 25;
	b.r.y = H / 2 - 25;
	b.r.w = 50;
	b.r.h = 50;
	b.loadMusic();
	surface = NULL;
	window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, W, H, SDL_WINDOW_SHOWN);
	SDL_Init(SDL_INIT_EVERYTHING);
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	surface = SDL_GetWindowSurface(window);
	open = SDL_TRUE;

	ball = IMG_LoadTexture(render, "3.png");
	player1 = IMG_LoadTexture(render, "player1.png");
	player2 = IMG_LoadTexture(render, "player2.png");
	playing = false;
	compute = false;
}

void Game::setPlayer()
{
	Player p;
	pl.push_back(p);
	pl.push_back(p);
	pl[0].pl.h = 160;
	pl[0].pl.w = 20;
	pl[0].pl.x = W - 20;
	pl[0].pl.y = H / 2 - 100;
	pl[1].pl.h = 160;
	pl[1].pl.w = 20;
	pl[1].pl.x = 0;
	pl[1].pl.y = H / 2 - 100;
}

void Game::SetLine(void)
{
	int j = 0;
	while (j < H)
	{
		text[5].Message_rect.y = j;
		SDL_RenderCopy(render, text[5].Message, NULL, &text[5].Message_rect);
		j += 15;
	}
}

void Game::DeleteAll()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(render);
	SDL_DestroyTexture(ball);
	SDL_DestroyTexture(player1);
	SDL_DestroyTexture(player2);
	// text
	SDL_FreeSurface(text[0].surfaceMessage);
	SDL_DestroyTexture(text[0].Message);
	SDL_FreeSurface(text[1].surfaceMessage);
	SDL_DestroyTexture(text[1].Message);
	SDL_FreeSurface(text[2].surfaceMessage);
	SDL_DestroyTexture(text[2].Message);
	TTF_CloseFont(Sans);
	b.deleteMusic();
	SDL_Quit();
}

void Game::DeleteText()
{
	SDL_FreeSurface(text[3].surfaceMessage);
	SDL_DestroyTexture(text[3].Message);
	SDL_FreeSurface(text[4].surfaceMessage);
	SDL_DestroyTexture(text[4].Message);
	SDL_FreeSurface(text[5].surfaceMessage);
	SDL_DestroyTexture(text[5].Message);
}