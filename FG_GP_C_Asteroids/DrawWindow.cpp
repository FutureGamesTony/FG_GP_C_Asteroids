#include "DrawWindow.h"
#include "SDL.h"
#include <iostream>

using std::cout;
#define WIDTH 1280
#define HEIGHT 720
DrawWindow::DrawWindow(SDL_Window* window, SDL_Renderer* renderer)
{
	//CreateWindow(window);
	//CreateRenderer(window, renderer);
}

DrawWindow::~DrawWindow()
{
	//SDL_DestroyWindow(window);
	//SDL_Quit();

}

SDL_Window* DrawWindow::CreateWindow(SDL_Window* window)
{
	window = SDL_CreateWindow("Asteroids Dope-ass version ", 10, 10, WIDTH, HEIGHT, 0);
	return window;
}

SDL_Renderer* DrawWindow::CreateRenderer(SDL_Window* window, SDL_Renderer* renderer)
{
	fullscreen = 0;
	static int lastTime;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) std::cout << "Failed at SDL_Init()" << std::endl; // initializing sdl
	renderer = SDL_CreateRenderer(window, 0, 0);
	SDL_SetWindowTitle(window, "Asteroids Dope-ass version ");
	SDL_ShowCursor(0); // hides cursor in window
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2"); // render pixels better (anisotropic filtering)

	return renderer;
}

void DrawWindow::UpdateWindow(SDL_Renderer* renderer)
{
	static int lastTime;

	lastFrame = SDL_GetTicks();
	if (lastFrame >= (lastFrame + 1000))
	{
		lastTime = lastFrame;
		fps = framecount;
		framecount = 0;
	}
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
		//SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
	}
	if (!fullscreen)
	{
		//SDL_SetWindowFullscreen(window, 0);
	}
}
