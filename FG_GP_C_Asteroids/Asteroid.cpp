#include "Asteroid.h"
#include "AsteroidCollider.h"
#include "AsteroidSprite.h"
#include "EngingConfig.h"
#include "RenderManager.h"
#include "ICollider.h"
#include "ISprite.h"
#include "SDL.h"
#include "SDL_image.h"
Asteroid::Asteroid(EngineConfig::EntityType entityType, Circle circle, ICollider* collider, ISprite* sprite, Position position, Size size)
{
	m_asteroidSprite = sprite;

	//path = filePath.c_str();
	m_asteroid_Entity = entityType;
	circleCollider = circle;
	m_asteroidCollider = collider;
	m_movement = { 0,0 };
	m_position = position;
	m_size = size;
	velocityX = 0;
	velocityY = 0;
	//m_asteroidCollider = new AsteroidCollider(Asteroid_Entity, collisionManager, size, position, movement, circleCollider);
}
Asteroid::~Asteroid()
{

}
int Asteroid::getXpos()
{
	return this->m_position.x;
}

int Asteroid::getYpos()
{
	return this->m_position.y;
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
	return this->m_size.height;
}

void Asteroid::CreateEntity(EngineConfig::EntityType entityType, SDL_Window* window, SDL_Renderer* renderer, int renderIndex, Uint32 renderFlags, ISprite* sprite, ICollider* collider, SDL_Surface* image, char* spriteFilePath, Size size, Circle circle, Position position, Movement movementInput)
{
	CreateAsteroid(entityType, window, renderer, renderIndex, renderFlags, sprite, collider, image, spriteFilePath, circle, position, movementInput);
}

void Asteroid::UpdateMovement(float moveX, float moveY, float xPos, float yPos)
{
}

ICollider* Asteroid::GetCollider()
{
	return m_asteroidCollider;
}

ISprite* Asteroid::GetSprite()
{
	return m_asteroidSprite;
}

Size Asteroid::SetSize()
{
	return m_size;
}

Position Asteroid::SetPosition()
{
	return m_position;
}

void Asteroid::Update()
{
}

void Asteroid::CreateAsteroid(EngineConfig::EntityType entityType, SDL_Window* window, SDL_Renderer* renderer, int renderIndex, Uint32 renderFlags, ISprite* asteroidSprite, ICollider* asteroidCollider, SDL_Surface* surface, char* spriteFilePath, Circle circle, Position position, Movement movement)
{

	asteroidSprite = m_asteroidSprite;
	entityType = m_asteroid_Entity;
}

Movement Asteroid::SetMovementInput(EngineConfig::PlayerInput moveCommand)
{
	return m_movement;
}

void Asteroid::CreateSprite(SDL_Renderer* renderer)
{

}

EngineConfig::EntityType Asteroid::GetEntityType()
{
	return m_asteroid_Entity;
}

