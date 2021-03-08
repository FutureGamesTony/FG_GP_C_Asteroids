#include "RenderManager.h"
#include "DrawWindow.h"
#include "Renderer.h"
#include "EngingConfig.h"
#include "PlayerSprite.h"
#include "AsteroidSprite.h"
#include "SDL.h"
#include "SDL_image.h" //(new)
#include "ISprite.h"
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
	m_playerSprite = new PlayerSprite();
	return m_renderer != nullptr;
	
}

void RenderManager::UpdateWindow()
{
	m_playerSprite->DrawPlayer(m_renderer);
	m_drawWindow->UpdateWindow(m_renderer, m_texture, lastFrame, fps, framecount,);

}

void RenderManager::DrawAsteroids(AsteroidSprite asteroid)
{
	//float x = asteroid.getXpos();
	//float y = asteroid.getYpos();
	//float velX = asteroid.getXvelocity();
	//float velY = asteroid.getYvelocity();
	//int size = asteroid.getSize();

	//x += velX * lastFrame;
	//y += velY * lastFrame;
}

void RenderManager::ShutDown()
{
    SDL_DestroyRenderer(m_renderer);
    m_renderer = nullptr;
    SDL_DestroyWindow(m_window);
    m_window = nullptr;
}
