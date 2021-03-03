#pragma once
#include "SDL.h"
class DrawWindow;
class RenderManager
{
public:
	RenderManager();
	~RenderManager();
	bool InitializeWidow();
	void UpdateWindow();
	void ShutDown();
	void WrapCoordinates(float inX, float inY, float &outX, float &outY);
private:
	int m_width = 800;
	int m_height = 600;
	SDL_Window* m_window = nullptr;
	SDL_Renderer* m_renderer = nullptr;
	DrawWindow* m_drawWindow = nullptr;
	const char* m_windowTitle = "Window Title"; //TODO: Destroy pointer array
};

