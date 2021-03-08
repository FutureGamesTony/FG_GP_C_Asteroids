#include "DopeAssEngine.h"
#include "Player.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "DrawWindow.h"

#include "Asteroid.h"
#include "ISprite.h"
#include "IEntity.h"
#include "SDL.h"
#include "ICollider.h"
#include "Keyboard.h"
#include "Mouse.h"

DopeAssEngine::DopeAssEngine()
{

}

DopeAssEngine::~DopeAssEngine()
{
    delete m_player;
    m_player = nullptr;
    delete m_inputManager;
    m_inputManager = nullptr;
    delete m_renderManager;
    m_renderManager = nullptr;
}

bool DopeAssEngine::InitEngine()
{
    m_renderManager = new RenderManager();
    m_inputManager = new InputManager();
    return m_renderManager != nullptr && m_inputManager != nullptr;
    return true;
}

bool DopeAssEngine::UpdateEngine()
{
    m_renderManager->UpdateWindow();
    return true;
}


void DopeAssEngine::InitializeRenderManager()
{
}

void DopeAssEngine::InitializePlayer()
{
    m_player = new Player();
    SDL_Surface* tempSurface = IMG_Load("assets/AsteroidShip.png"); //(new)
    playerTex = SDL_CreateTextureFromSurface(m_renderManager->m_renderer, tempSurface); //(new)
    SDL_FreeSurface(tempSurface); //(new)
}

void DopeAssEngine::InitializeInput()
{
    m_inputManager = new InputManager();
}
void DopeAssEngine::InitializeAsteroids()
{
        //TODO: When Asteroid class is done, add here m_asteroid = new Asteroid(); to create object Asteroid.
}
void DopeAssEngine::InitializeSprites()
{
}
void DopeAssEngine::InitializeCollision()
{
}
void DopeAssEngine::ShutDown()
{
}
