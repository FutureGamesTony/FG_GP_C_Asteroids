#include "DrawWindow.h"
#include "SDL.h"
#include <iostream>
using std::cout;
#define WIDTH 1280
#define HEIGHT 720
DrawWindow::DrawWindow()
{

}

DrawWindow::~DrawWindow()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

}

void DrawWindow::CreateWindow()
{
	fullscreen = 0;
	static int lastTime;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) std::cout << "Failed at SDL_Init()" << std::endl; // initializing sdl
	if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) < 0) std::cout << "Failed at SDL_CreateWindowAndRenderer()" << std::endl;
	SDL_SetWindowTitle(window, "Asteroids Dope-ass version ");
	SDL_ShowCursor(0); // hides cursor in window
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2"); // render pixels better (anisotropic filtering)



}

void DrawWindow::UpdateWindow()
{
	SDL_SetRenderDrawColor(renderer, 49, 70, 83, 255); // set color to blueish-grey
	SDL_Rect rect; //creates a rectangle
	rect.x = rect.y = 0;

	rect.w = WIDTH;
	rect.h = HEIGHT;
	SDL_RenderFillRect(renderer, &rect);

	framecount++;
	int timerFPS = SDL_GetTicks() - lastFrame;
	if (timerFPS < (1000 / 60))
	{
		SDL_Delay((1000 / 60) - timerFPS);
	}

	SDL_RenderPresent(renderer);
}

void DrawWindow::Fullscreen()
{
	if (fullscreen)
	{
		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
	}
	if (!fullscreen)
	{
		SDL_SetWindowFullscreen(window, 0);
	}
}
