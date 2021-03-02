#pragma once
#include "SDL.h"
class DrawWindow
{
public:
	DrawWindow();
	~DrawWindow();
	void CreateWindow();
	void UpdateWindow();
	int framecount;
	int timerFPS;
	int lastFrame;
	int fps;
	bool running;
	bool fullscreen;
	SDL_Renderer* renderer = nullptr;
	SDL_Window* window;

private:
	void Fullscreen();



	
};