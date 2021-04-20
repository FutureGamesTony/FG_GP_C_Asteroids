#include "EntityManager.h"
#include "Asteroid.h"
#include "Player.h"
using std::vector;
EntityManager::EntityManager()
{
	
}

EntityManager::~EntityManager()
{
	for (Asteroid* asteroid : m_asteroids) 
	{
		delete asteroid;
		asteroid = nullptr;
	}
	m_asteroids.clear();
	m_asteroids.shrink_to_fit();
}

std::vector<IEntity*> EntityManager::GetEnteties()
{
	return m_enteties;
}

IEntity* EntityManager::GetEntity()
{
	return m_player;
}

void EntityManager::Func()
{

}

void EntityManager::CreatePlayer()
{
	Position position = { EngineConfig::HEIGHT / 2, EngineConfig::WIDTH / 2 };
	double rotation = 0.0;
	m_player = new Player(entityType, sprites[0], colliders[0], position, rotation);
}

void EntityManager::CreateAsteroid(EngineConfig::EntityType entity,  Circle circle, ICollider* collider, ISprite* sprite, Position position, Size size)
{
	entityType = entity;
	m_asteroids.push_back(new Asteroid(entity, circle, collider, sprite, position, size));
}

void EntityManager::CreateBullet()
{
	
}

void EntityManager::CreateEnteties()
{
	if (m_enteties.size() == 0)
	{
		m_enteties.push_back(dynamic_cast<IEntity*>(m_player));
	}
	if (m_enteties.size() - 1 < m_asteroids.size()) 
	{
		for (int i = m_enteties.size() - 1; i < m_asteroids.size(); i++)
		{
			m_enteties.push_back(dynamic_cast<IEntity*>(m_asteroids[i]));
		}
	}
}

void EntityManager::UpdateEnteties()
{
}

void EntityManager::UpdatePlayer(EngineConfig::PlayerInput playerInput)
{

	m_player->SetMovementInput(playerInput);
}

void EntityManager::UpdateAsteroids()
{
}

void EntityManager::SetEnteties()
{
}
