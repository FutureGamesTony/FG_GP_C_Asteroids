#include "SDL.h"
#include "iostream"
#include "InputManager.h"
#include "RenderManager.h"
#include "DopeAssEngine.h"
#include "Asteroid.h"
#include "EntityManager.h"
#include "PlayerSprite.h"

#define WIDTH 1280
#define HEIGHT 720

//SDL_Renderer* renderer;
//SDL_Window* window;

int main(int argc, char** argv) 
{
	DopeAssEngine dopeAssEngine;
	bool running = dopeAssEngine.InitEngine();
	while (running)
	{

		running = dopeAssEngine.UpdateEngine();
		if (!running) dopeAssEngine.ShutDown();
	}
	SDL_Quit();
	return 0;
}