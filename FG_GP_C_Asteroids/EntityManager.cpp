#include "EntityManager.h"
#include "Asteroid.h"
#include "Player.h"
using std::vector;
EntityManager::EntityManager()
{
	CreatePlayer();

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
	m_player = new Player();
}

void EntityManager::CreateAsteroid(int posX, int posY, int sizeX, int sizeY, char* path)
{
	m_asteroids.push_back(new Asteroid(posX, posY, sizeX, sizeY, path));
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
