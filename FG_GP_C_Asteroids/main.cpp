#include "SDL.h"
#include "iostream"
#include "InputManager.h"
#include "RenderManager.h"
#define WIDTH 1280
#define HEIGHT 720

SDL_Renderer* renderer;
SDL_Window* window;

int main(int argc, char** argv) 
{
	InputManager m_getInputManager;
	RenderManager m_getRenderer;
	bool running = m_getRenderer.InitializeWidow();

	while (running)
	{
		m_getInputManager.GetKey();
		m_getRenderer.UpdateWindow();
		running = !m_getInputManager.QuitApplication();
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}