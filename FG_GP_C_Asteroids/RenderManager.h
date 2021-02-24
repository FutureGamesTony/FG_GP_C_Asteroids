#pragma once
#include "SDL.h"

class RenderManager
{
public:
	RenderManager();
	~RenderManager();
	bool InitializeWidow();
	void ShutDown();
private:
	int m_width = 800;
	int m_height = 600;
	SDL_Window* m_window = nullptr;
	SDL_Renderer* m_renderer = nullptr;
	const char* m_windowTitle = "Window Title"; //TODO: Destroy pointer array
};

