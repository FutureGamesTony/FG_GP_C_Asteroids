#include "SDL.h"
#include "iostream"
#include "InputManager.h"
#include "RenderManager.h"
#define WIDTH 1280
#define HEIGHT 720

SDL_Renderer* renderer;
SDL_Window* window;

int framecount;
int timerFPS;
int lastFrame;
int fps;

bool fullscreen;


int main(int argc, char** argv) 
{
	InputManager m_getInputManager;
	RenderManager m_getRenderer;
	bool running = true;
	fullscreen = 0;
	static int lastTime;
	m_getRenderer.InitializeWidow();

	while (running)
	{
		lastFrame = SDL_GetTicks();
		if(lastFrame >= (lastFrame + 1000)) 
		{
			lastTime = lastFrame;
			fps = framecount;
			framecount = 0;
		}
		m_getInputManager.GetKey();
		m_getRenderer.UpdateWindow();
		running = !m_getInputManager.QuitApplication();
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}