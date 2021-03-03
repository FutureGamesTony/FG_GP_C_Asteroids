#pragma once
#include "SDL.h"
class DrawWindow
{
public:
	DrawWindow(SDL_Window* window, SDL_Renderer* renderer);
	~DrawWindow();
	SDL_Window* CreateWindow(SDL_Window* window);
	SDL_Renderer* CreateRenderer(SDL_Window* window, SDL_Renderer* renderer);
	void UpdateWindow(SDL_Renderer* renderer);
	int framecount;
	int timerFPS;
	int lastFrame;
	int fps;
	bool running;
	bool fullscreen;
	//SDL_Renderer* renderer = nullptr;
	//SDL_Window* window;
private:
	void Fullscreen();



	
};