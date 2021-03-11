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
}

bool DopeAssEngine::InitEngine()
{
    InitializeRenderManager();
    InitializeCollisionManager();
    InitializeEnteties();
    //InitializeSpriteManager();

    InitializeInput();
    //InitializePlayer();
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
    m_renderManager = new RenderManager(m_entityManager);
}

void DopeAssEngine::InitializeEntityManager()
{
    m_entityManager = new EntityManager();
}

//void DopeAssEngine::InitializePlayer()
//{
//    m_player = new Player();
//    //m_renderManager->SetSprite(m_playerSprite);
//}

void DopeAssEngine::InitializeInput()
{
    m_inputManager = new InputManager();
}

void DopeAssEngine::InitializeEnteties()
{
    for (int i = 0; i < m_entities.size(); i++)
    {
        m_colliders.push_back(m_entities[i]->GetCollider());
    }
    InitializeCollisionManager();
}
void DopeAssEngine::InitializeCollisionManager()
{
    m_collisionManager = new CollisionManager();
}
void DopeAssEngine::ShutDown()
{
}
