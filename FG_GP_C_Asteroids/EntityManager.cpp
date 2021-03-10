#include "EntityManager.h"
#include "Asteroid.h"
#include "Player.h"
#include "CollisionManager.h"
using std::vector;
EntityManager::EntityManager(CollisionManager* collisionManger)
{
	CreatePlayer();
	CreateAsteroid(spriteFilePath, collisionManger);
}

EntityManager::~EntityManager()
{
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
	m_player = new Player(renderer);
}

void EntityManager::CreateAsteroid(const char* path, CollisionManager *collisionManager)
{
	m_asteroids.push_back(new Asteroid(path, renderer, collisionManager));
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
