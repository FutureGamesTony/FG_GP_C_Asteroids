#include "SDL.h"
#include "iostream"
#include "InputManager.h"
#include "RenderManager.h"
#include "DopeAssEngine.h"
#define WIDTH 1280
#define HEIGHT 720



int main(int argc, char** argv) 
{

	DopeAssEngine dopeAssEngine;
	bool running;
	running = dopeAssEngine.InitEngine();
	while (running)
	{
		running = dopeAssEngine.UpdateEngine();
		if (!running) dopeAssEngine.ShutDown();
	}

	SDL_Quit();
	return 0;
}