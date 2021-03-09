#include "RenderManager.h"
#include "DrawWindow.h"
#include "Renderer.h"
#include "EngingConfig.h"
#include "ISprite.h"
#include "PlayerSprite.h"
#include "SpriteManager.h"
#include "AsteroidSprite.h"
#include "SDL.h"
#include "SDL_image.h"
using std::vector;

RenderManager::RenderManager()
{
	m_drawWindow = new DrawWindow();
	m_createRenderer = new Renderer();
	m_renderSprite = new PlayerSprite(m_renderer); // Debug
	InitializeWidow();
	InitializeRenderer();
	InitializeSpriteManager();
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
	//m_renderSprite->DrawSprite(m_renderer); redundant?

	return m_renderer != nullptr;
	
}

bool RenderManager::InitializeSpriteManager()
{
	m_spriteManager = new SpriteManager();
	for (int i = 0; i < m_spriteManager->GetSprites().size(); i++)
	{
		s_renderSprites.push_back(m_spriteManager->GetSprites()[i]); //Gets all the sprites from ISprite, populates list
	}
	return m_spriteManager != nullptr;
}

void RenderManager::UpdateWindow()
{
	for (int i = 0; i < s_renderSprites.size(); i++)
	{
		m_drawWindow->UpdateWindow(m_renderer, s_renderSprites[i]->GetSprite(), lastFrame, fps, framecount, m_renderSprite);
	}
	//m_drawWindow->UpdateWindow(m_renderer, m_texture, lastFrame, fps, framecount, m_renderSprite);
}


void RenderManager::ShutDown()
{
    SDL_DestroyRenderer(m_renderer);
    m_renderer = nullptr;
    SDL_DestroyWindow(m_window);
    m_window = nullptr;
}

void RenderManager::SetSprite()
{
	//for (int i = 0;  i < spritema; i++)
	//{

	//}
}
