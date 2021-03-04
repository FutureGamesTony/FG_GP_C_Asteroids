#include "Renderer.h"
#include "SDL.h"
#include <iostream>
using std::cout;
Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

SDL_Renderer* Renderer::CreateRenderer(SDL_Window* window, SDL_Renderer* renderer)
{

	static int lastTime;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) std::cout << "Failed at SDL_Init()" << std::endl; // initializing sdl
	renderer = SDL_CreateRenderer(window, 0, 0);
	SDL_SetWindowTitle(window, "Asteroids Dope-ass version ");
	SDL_ShowCursor(0); // hides cursor in window
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2"); // render pixels better (anisotropic filtering)

	return renderer;
}