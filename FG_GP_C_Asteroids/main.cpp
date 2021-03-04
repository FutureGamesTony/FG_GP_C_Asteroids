#include "SDL.h"
#include "iostream"
#include "InputManager.h"
#include "RenderManager.h"
#include "DopeAssEngine.h"
#include "Asteroid.h"
#include "EntityManager.h"

#define WIDTH 1280
#define HEIGHT 720

//SDL_Renderer* renderer;
//SDL_Window* window;

int main(int argc, char** argv) 
{
	InputManager m_getInputManager;
	RenderManager m_getRenderer;
	DopeAssEngine dopeAssEngine;
	EntityManager entityManager; //(debug)
	bool running = m_getRenderer.InitializeWidow();
	running = dopeAssEngine.InitEngine();
	while (running)
	{
		/*m_getInputManager.GetKey();*/
		running = dopeAssEngine.UpdateEngine();
		if (!running) dopeAssEngine.ShutDown();
	}

	//SDL_DestroyRenderer(renderer);
	//SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}