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
    delete m_collisionManager;
    m_collisionManager = nullptr;
}

bool DopeAssEngine::InitEngine()
{
    InitializeEntityManager(); //(J)
    InitializeRenderManager();
    InitializeCollisionManager();
    //InitializeEnteties();
    InitializeSprites();
    InitializeInput();
    //InitializePlayer();
    return m_renderManager != nullptr /*&& m_inputManager != nullptr*/;
    return true;
}

bool DopeAssEngine::UpdateEngine()
{
    m_renderManager->UpdateWindow();
    m_inputManager->GetKey(m_entityManager->GetEntity());
    return true;
}


void DopeAssEngine::InitializeRenderManager()
{
    m_renderManager = new RenderManager(m_entityManager);
}

void DopeAssEngine::InitializeEntityManager()
{
    m_entityManager = new EntityManager();
}

void DopeAssEngine::InitializeInput()
{
    m_inputManager = new InputManager();
}

void DopeAssEngine::InitializeEnteties(Entity_Type entity)
{
    switch (entity)
    {
    case Player_Entity:
        m_entityManager->CreatePlayer();
        break;
    case Bullet_Entity:
        m_entityManager->CreateBullet();
        break;
    case Asteroid_Entity:
        m_entityManager->CreateAsteroid();
        break;
    default:
        break;
    }
}
void DopeAssEngine::InitializeSprites()
{
    m_renderManager->InitializeSprites();
}
void DopeAssEngine::InitializeCollisionManager()
{
    m_collisionManager = new CollisionManager();
}
void DopeAssEngine::ShutDown()
{
}
