#include "Asteroid.h"
#include "AsteroidCollider.h"
#include "AsteroidSprite.h"
#include "EngingConfig.h"
#include "RenderManager.h"
#include "ICollider.h"
#include "ISprite.h"
#include "SDL.h"
#include "SDL_image.h"
Asteroid::Asteroid()
{
	m_asteroidSprite = new AsteroidSprite();
	m_asteroidCollider = new AsteroidCollider(position.xPosition, position.yPosition);
}
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

void Asteroid::ModifyRects()
{
}

int Asteroid::getSize()
{
	return this->size;
}

ICollider* Asteroid::GetCollider()
{
	return dynamic_cast<AsteroidCollider*>(m_asteroidCollider);
}

ISprite* Asteroid::GetSprite()
{
	return dynamic_cast<AsteroidSprite*>(m_asteroidSprite);
}

void Asteroid::CreateAsteroid(Entity_Type& entityType, SDL_Window* window, SDL_Renderer* renderer, int renderIndex, Uint32 renderFlags, ISprite* asteroidSprite, ICollider* asteroidCollider, SDL_Surface* surface, char& spriteFilePath, Circle circle, Position position, Movement movement)
{

	asteroidSprite = dynamic_cast<AsteroidSprite*>(m_asteroidSprite);
	entityType = m_asteroid_Entity;
}

