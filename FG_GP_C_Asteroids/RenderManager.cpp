#include "RenderManager.h"
#include "DrawWindow.h"
#include "Renderer.h"
#include "EngingConfig.h"
#include "PlayerSprite.h"
#include "Asteroid.h"
#include "SDL.h"
RenderManager::RenderManager()
{
	m_drawWindow = new DrawWindow();
	m_createRenderer = new Renderer();
	InitializeWidow();
	InitializeRenderer();
	fps = 0;
	framecount = 0;
	fullscreen = 0;
	lastFrame = 0;
	running = 0;
	timerFPS = 0;
}

RenderManager::~RenderManager()
{
	ShutDown();
    
}

bool RenderManager::InitializeWidow()
{
    m_window = m_drawWindow->CreateWindow(m_window);
	
    return m_drawWindow != nullptr;
}

bool RenderManager::InitializeRenderer()
{
	m_renderer = m_createRenderer->CreateRenderer(m_window, m_renderer);
	return m_renderer != nullptr;
	
}

void RenderManager::UpdateWindow()
{
	m_drawWindow->UpdateWindow(m_renderer, lastFrame, fps, framecount);
}

void RenderManager::DrawAsteroids(Asteroid asteroid)
{
	float x = asteroid.getXpos();
	float y = asteroid.getYpos();
	float velX = asteroid.getXvelocity();
	float velY = asteroid.getYvelocity();
	int size = asteroid.getSize();

	x += velX * lastFrame;
	y += velY * lastFrame;


	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			//????????????????????????????????????????? draw asteroid here
			SDL_SetRenderDrawColor(m_renderer, 10, 140, 160, 255); // set color to blueish-grey
			SDL_Rect rect; //creates a rectangle
			rect.x = rect.y = 0;
			rect.w = EngineConfig::WIDTH;
			rect.h = EngineConfig::HEIGHT;
			SDL_RenderFillRect(m_renderer, &rect);
		}
	}
}

void RenderManager::ShutDown()
{
    SDL_DestroyRenderer(m_renderer);
    m_renderer = nullptr;
    SDL_DestroyWindow(m_window);
    m_window = nullptr;
}
