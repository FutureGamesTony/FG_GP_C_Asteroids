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
    circle = { 0, 0, 0 };


    position = { 0, 0 };
    size = { 0, 0 };
    playerRotation = 0;
    
    keyPressed = EngineConfig::PlayerInput::NoKeyPressed;
    m_keyPressed = keyPressed;
    playerPosition = { 0, 0 };
    playerMovement = { 0, 0 };
    entityType = EngineConfig::EntityType::Player_Entity;
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
    InitializeEntityManager();
    InitializeRenderManager();
    InitializeCollisionManager();
    InitializeSprites();
    InitializeInput();
    m_sprites = m_renderManager->GetSprites();
    return m_renderManager != nullptr && m_inputManager != nullptr;
    return true;
}

bool DopeAssEngine::UpdateEngine()
{
    if (m_playerSprite == nullptr)
    {
        for (ISprite* playerSprite : m_sprites) 
        {

            if (playerSprite->GetEntityType() == EngineConfig::EntityType::Player_Entity) m_playerSprite = playerSprite;
        }
    }
    for (IEntity* entity : m_entities)
    {
        entityType = entity->GetEntityType();
        switch (entityType)
        {
        case EngineConfig::EntityType::Player_Entity:
            break;
        case EngineConfig::EntityType::Bullet_Entity:
            break;
        case EngineConfig::EntityType::Asteroid_Entity:
            break;
        default:
            break;
        }

    EngineConfig::PlayerInput input = m_inputManager->GetInput();
    m_entityManager->UpdatePlayer(input);
    m_renderManager->UpdateSprite(m_playerSprite, playerRotation, playerPosition.x, playerPosition.y);

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

void DopeAssEngine::InitializeInput()
{
    m_inputManager = new InputManager();
}

void DopeAssEngine::UpdatePlayerDebug()
{
}

void DopeAssEngine::GetInput()
{
    keyPressed = m_inputManager->GetInput();
    switch (keyPressed)
    {
    case EngineConfig::PlayerInput::NoKeyPressed:
        break;
    case EngineConfig::PlayerInput::PlayerForward:
        //UpdatePlayerPosition(playerPosition.x, playerPosition.y, playerRotation);
        break;
    case EngineConfig::PlayerInput::PlayerRotateLeft:
        //playerRotation = UpdatePlayerRotation(playerRotation);
        break;
    case EngineConfig::PlayerInput::PlayerRotateRight:
        //playerRotation = UpdatePlayerRotation(playerRotation);
        break;
    case EngineConfig::PlayerInput::PlayerBreak:
        break;
    case EngineConfig::PlayerInput::PlayerFireWeapon:
        break;
    case EngineConfig::PlayerInput::PlayerQuit:
        break;
    default:
        break;
    }

}

Position DopeAssEngine::UpdatePosition(int x, int y, int rotation) //Needs calibration
{
    return playerPosition;
}

int DopeAssEngine::UpdatePlayerRotation(int rotation)
{
    switch (keyPressed)
    {

    case EngineConfig::PlayerInput::PlayerRotateLeft:
        rotation--;
        break;
    case EngineConfig::PlayerInput::PlayerRotateRight:
        rotation++;
        break;
    }
    return rotation;
}

void DopeAssEngine::InitializeEnteties(EngineConfig::EntityType entity)
{
    switch (entity)
    {
    case EngineConfig::EntityType::Player_Entity:
        m_entityManager->CreatePlayer();
        break;
    case EngineConfig::EntityType::Bullet_Entity:
        m_entityManager->CreateBullet();
        break;
    case EngineConfig::EntityType::Asteroid_Entity:
        SpawnAsteroids();
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

void DopeAssEngine::SpawnAsteroids()
{
    circle = {10,10,10};
    position.x = circle.x;
    position.y = circle.y;
    size = { 10 };
    m_entityManager->CreateAsteroid(EngineConfig::EntityType::Asteroid_Entity, circle, collider, m_asteroidSprite, position, size);
}
