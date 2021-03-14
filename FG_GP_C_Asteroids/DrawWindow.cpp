#include "DrawWindow.h"
#include "SDL.h"
#include "SDL_image.h"
#include "EngingConfig.h"
#include "DopeAssEngine.h"
#include "PlayerSprite.h"
#include "IEntity.h"
#include "RenderManager.h"
#include "Renderer.h"
#include <iostream>

using std::cout;

DrawWindow::DrawWindow()
{
}

DrawWindow::~DrawWindow()
{
}

SDL_Window* DrawWindow::CreateWindow(SDL_Window* window)
{
	window = SDL_CreateWindow("Asteroids Dope-ass version ", 10, 10, EngineConfig::WIDTH, EngineConfig::HEIGHT, 0);
	return window;
}
