#include "SDL.h"
#include "iostream"
#include "InputManager.h"
#include "RenderManager.h"
#include "DopeAssEngine.h"
#include "Asteroid.h"

#define WIDTH 1280
#define HEIGHT 720

//SDL_Renderer* renderer;
//SDL_Window* window;

int main(int argc, char** argv) 
{
	InputManager m_getInputManager;
	RenderManager m_getRenderer;
	DopeAssEngine dopeAssEngine;
	Asteroid asteroid({20.0f, 10.0f, 8.0f, -6.0f, 15});
	asteroid.asteroids
	bool running = m_getRenderer.InitializeWidow();
	running = dopeAssEngine.InitEngine();
	while (running)
	{
		for (auto &a : asteroids)
		{
			a.
		}
		/*m_getInputManager.GetKey();*/
		running = dopeAssEngine.UpdateEngine();
		if (!running) dopeAssEngine.ShutDown();
	}

	//SDL_DestroyRenderer(renderer);
	//SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}