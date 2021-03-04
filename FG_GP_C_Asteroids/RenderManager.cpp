#include "RenderManager.h"
#include "DrawWindow.h"
#include "Renderer.h"
#include "EngingConfig.h"
#include "PlayerSprite.h"
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

void RenderManager::ShutDown()
{
    SDL_DestroyRenderer(m_renderer);
    m_renderer = nullptr;
    SDL_DestroyWindow(m_window);
    m_window = nullptr;
}
