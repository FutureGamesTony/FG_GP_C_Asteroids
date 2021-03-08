#include "Asteroid.h"
#include "AsteroidCollider.h"
#include "EngingConfig.h"
#include "RenderManager.h"

int Asteroid::getXpos()
{
	return this->xPos;
}

int Asteroid::getYpos()
{
	return this->yPos;
}

int Asteroid::getXvelocity()
{
	return this->velocityX;
}

int Asteroid::getYvelocity()
{
	return this->velocityY;
}

int Asteroid::getSize()
{
	return this->size;
}

ICollider* Asteroid::GetCollider()
{
	return dynamic_cast<AsteroidCollider*>(m_asteroidCollider);
}

AsteroidCollider* Asteroid::SetCollider()
{
	m_asteroidCollider = new AsteroidCollider();
	return m_asteroidCollider;
}
