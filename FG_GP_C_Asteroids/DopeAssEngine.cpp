#include "DopeAssEngine.h"
#include "Player.h"
#include "InputManager.h"
#include "EntityManager.h"
#include "RenderManager.h"
#include "DrawWindow.h"
#include "SpriteManager.h"
#include "Asteroid.h"
#include "ISprite.h"
#include "IEntity.h"
#include "SDL.h"
#include "ICollider.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "CollisionManager.h"
#include "PlayerSprite.h"

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
    InitializeRenderManager();
    InitializeEnteties();
    InitializeSpriteManager();
    InitializeCollisionManager();
    InitializeInput();
    InitializePlayer();
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
    m_renderManager = new RenderManager();
}

void DopeAssEngine::InitializePlayer()
{
    //m_player = new Player();
    m_renderManager->SetSprite(m_playerSprite);
}

void DopeAssEngine::InitializeInput()
{
    m_inputManager = new InputManager();
}
//void DopeAssEngine::InitializeAsteroids()
//{
//        //TODO: When Asteroid class is done, add here m_asteroid = new Asteroid(); to create object Asteroid.
//}
void DopeAssEngine::InitializeEnteties()
{
    m_entityManager = new EntityManager();
    m_player = m_entityManager->GetEntity();
    m_playerSprite = m_player->GetSprite();

}
void DopeAssEngine::InitializeSpriteManager()
{
    m_spriteManager = new SpriteManager();
}
void DopeAssEngine::InitializeCollisionManager()
{
    m_collisionManager = new CollisionManager();
}
void DopeAssEngine::ShutDown()
{
}
