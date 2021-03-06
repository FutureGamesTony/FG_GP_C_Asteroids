#include "EntityManager.h"
#include "Asteroid.h"

void EntityManager::Func()
{
	Asteroid asteroid({ 20.0f, 10.0f, 8.0f, -6.0f, 15 }); // creating asteroid (debug)
	
	for (auto& a : EntityManager::asteroids) // (debug)
	{
		
	}
}
