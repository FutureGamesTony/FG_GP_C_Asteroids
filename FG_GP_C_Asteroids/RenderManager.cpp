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
#include "EntityManager.h"
using std::vector;

RenderManager::RenderManager(EntityManager* entityManager)
{
	m_drawWindow = new DrawWindow();
	m_createRenderer = new Renderer();
	m_entityManager = entityManager;
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
	m_spriteManager = new SpriteManager(m_renderer, (Player*)m_entityManager->GetEntity());
	//for (int i = 0; i < m_spriteManager->GetSprites().size(); i++)
	//{
	//	s_renderSprites.push_back(m_spriteManager->GetSprites()[i]); //Gets all the sprites from ISprite, populates list
	//}
	return m_spriteManager != nullptr;
}

void RenderManager::InitializeSprites()
{
	//s_renderSprites.push_back(sprite);
	s_renderSprites = m_spriteManager->GetSprites();
}

void RenderManager::UpdateWindow()
{
	static int lastTime;

	lastFrame = SDL_GetTicks();
	if (lastFrame >= (lastFrame + 1000))
	{
		lastTime = lastFrame;
		fps = framecount;
		framecount = 0;
	}
	framecount++;
	int timerFPS = SDL_GetTicks() - lastFrame;
	if (timerFPS < (1000 / 60))
	{
		SDL_Delay((1000 / 60) - timerFPS);
	}
	SDL_RenderPresent(m_renderer);

	SDL_RenderClear(m_renderer);
	for (ISprite* sprite : s_renderSprites) 
	{
		sprite->DrawSprite(m_renderer);
		sprite->RenderSprite(m_renderer, sprite->GetSprite());
		sprite->ModifyRects();
	}

	SDL_RenderPresent(m_renderer);
}


void RenderManager::ShutDown()
{
    SDL_DestroyRenderer(m_renderer);
    m_renderer = nullptr;
    SDL_DestroyWindow(m_window);
    m_window = nullptr;
}

void RenderManager::RenderColliders()
{
}
