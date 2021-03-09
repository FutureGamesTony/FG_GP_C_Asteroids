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
	//InputManager m_getInputManager;
	//RenderManager m_getRenderer;
	DopeAssEngine dopeAssEngine;
	//EntityManager entityManager;
	//Asteroid asteroid({20.0f, 10.0f, 8.0f, -6.0f, 15}); //(debug)
	bool running = dopeAssEngine.InitEngine();
	PlayerSprite* player;
	player = new PlayerSprite();
	while (running)
	{
		//m_getRenderer.DrawAsteroids(asteroid);
		/*m_getInputManager.GetKey();*/
		running = dopeAssEngine.UpdateEngine();
		if (!running) dopeAssEngine.ShutDown();
	}

	//SDL_DestroyRenderer(renderer);
	//SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}