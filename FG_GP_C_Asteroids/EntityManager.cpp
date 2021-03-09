#include "EntityManager.h"
#include "Asteroid.h"
#include "Player.h"
EntityManager::EntityManager()
{
	
	m_player = new Player();
}

EntityManager::~EntityManager()
{
}

IEntity* EntityManager::GetPlayer()
{
	return m_player;
}

void EntityManager::Func()
{

}
