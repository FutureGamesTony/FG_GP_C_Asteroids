#include "Asteroid.h"
#include "AsteroidCollider.h"
#include "AsteroidSprite.h"
#include "EngingConfig.h"
#include "RenderManager.h"
#include "ICollider.h"
#include "ISprite.h"
#include "SDL.h"
#include "SDL_image.h"
Asteroid::Asteroid(const char* path, SDL_Renderer* renderer)
{
	path = filePath.c_str();

	m_asteroidSprite = new AsteroidSprite(renderer);
	m_asteroidCollider = new AsteroidCollider(Asteroid_Entity, size, position, movement, collider, circleCollider);
}
Asteroid::~Asteroid()
{
	delete m_asteroidSprite;
	m_asteroidSprite = nullptr;
	delete m_asteroidCollider;
	m_asteroidCollider = nullptr;
}
int Asteroid::getXpos()
{
	return this->position.xPosition;
}

int Asteroid::getYpos()
{
	return this->position.yPosition;
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
	return this->size.height;
}

void Asteroid::CreateEntity(Entity_Type entityType, SDL_Window* window, SDL_Renderer* renderer, int renderIndex, Uint32 renderFlags, ISprite* sprite, ICollider* collider, SDL_Surface* image, char* spriteFilePath, Size size, Circle circle, Position position, Movement movementInput)
{
	CreateAsteroid(entityType, window, renderer, renderIndex, renderFlags, sprite, collider, image, spriteFilePath, circle, position, movementInput);
}

void Asteroid::UpdateMovement()
{
}

ICollider* Asteroid::GetCollider()
{
	return dynamic_cast<AsteroidCollider*>(m_asteroidCollider);
}

ISprite* Asteroid::GetSprite()
{
	return dynamic_cast<AsteroidSprite*>(m_asteroidSprite);
}

Size Asteroid::SetSize()
{
	return size;
}

Position Asteroid::SetPosition()
{
	return position;
}

Movement Asteroid::SetMovementInput()
{
	return movement;
}

void Asteroid::Update()
{
}

void Asteroid::CreateAsteroid(Entity_Type& entityType, SDL_Window* window, SDL_Renderer* renderer, int renderIndex, Uint32 renderFlags, ISprite* asteroidSprite, ICollider* asteroidCollider, SDL_Surface* surface, char* spriteFilePath, Circle circle, Position position, Movement movement)
{

	asteroidSprite = dynamic_cast<AsteroidSprite*>(m_asteroidSprite);
	entityType = m_asteroid_Entity;
}

