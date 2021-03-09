#include "RenderManager.h"
#include "DrawWindow.h"
#include "Renderer.h"
#include "EngingConfig.h"
#include "PlayerSprite.h"
#include "AsteroidSprite.h"
#include "SDL.h"
#include "SDL_image.h" //(new)
#include "ISprite.h"
using std::vector;

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
	if (m_renderSprite == nullptr)
	{
		return false;
	}
	m_renderer = m_createRenderer->CreateRenderer(m_window, m_renderer);
	m_renderSprite->DrawSprite(m_renderer);

	return m_renderer != nullptr;
	
}

void RenderManager::UpdateWindow()
{
	m_drawWindow->UpdateWindow(m_renderer, m_texture, lastFrame, fps, framecount, m_renderSprite);
}


void RenderManager::ShutDown()
{
    SDL_DestroyRenderer(m_renderer);
    m_renderer = nullptr;
    SDL_DestroyWindow(m_window);
    m_window = nullptr;
}

ISprite* RenderManager::SetSprite(ISprite* sprite)
{
	dynamic_cast<ISprite*>(sprite);
	m_renderSprite = sprite;
	return sprite;
}
