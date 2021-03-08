#include "DrawWindow.h"
#include "SDL.h"
#include "SDL_image.h"
#include "EngingConfig.h"
#include "DopeAssEngine.h"
#include <iostream>

using std::cout;

DrawWindow::DrawWindow()
{
}

DrawWindow::~DrawWindow()
{
}

SDL_Window* DrawWindow::CreateWindow(SDL_Window* window)
{
	window = SDL_CreateWindow("Asteroids Dope-ass version ", 10, 10, EngineConfig::WIDTH, EngineConfig::HEIGHT, 0);
	return window;
}
void DrawWindow::UpdateWindow(SDL_Renderer* renderer, SDL_Texture* texture, int lastFrame, int fps, int framecount, PlayerSprite* player)
{
	static int lastTime;

	lastFrame = SDL_GetTicks();
	if (lastFrame >= (lastFrame + 1000))
	{
		lastTime = lastFrame;
		fps = framecount;
		framecount = 0;
	}
	//m_playerSprite->DrawPlayer(m_renderer);
	SDL_SetRenderDrawColor(renderer, 49, 70, 83, 255); // set color to blueish-grey
	SDL_Rect rect; //creates a rectangle
	rect.x = rect.y = 0;
	rect.w = EngineConfig::WIDTH;
	rect.h = EngineConfig::HEIGHT;
	SDL_RenderFillRect(renderer, &rect);

	framecount++;
	int timerFPS = SDL_GetTicks() - lastFrame;
	if (timerFPS < (1000 / 60))
	{
		SDL_Delay((1000 / 60) - timerFPS);
	}
	SDL_RenderPresent(renderer);
	//m_drawWindow->UpdateWindow(m_renderer)
	//SDL_Rect* srect;
	//Sdl_redrer
}
//
//SDL_Renderer* DrawWindow::CreateRenderer(SDL_Window* window, SDL_Renderer* renderer)
//{
//
//	static int lastTime;
//	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) std::cout << "Failed at SDL_Init()" << std::endl; // initializing sdl
//	renderer = SDL_CreateRenderer(window, 0, 0);
//	SDL_SetWindowTitle(window, "Asteroids Dope-ass version ");
//	SDL_ShowCursor(0); // hides cursor in window
//	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2"); // render pixels better (anisotropic filtering)
//
//	return renderer;
//}