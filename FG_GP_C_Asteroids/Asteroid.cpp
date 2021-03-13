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
	//path = filePath.c_str();


	//m_asteroidCollider = new AsteroidCollider(Asteroid_Entity, collisionManager, size, position, movement, circleCollider);
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

void Asteroid::UpdateMovement(float moveX, float moveY, float xPos, float yPos)
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

void Asteroid::Update()
{
}

void Asteroid::CreateAsteroid(Entity_Type& entityType, SDL_Window* window, SDL_Renderer* renderer, int renderIndex, Uint32 renderFlags, ISprite* asteroidSprite, ICollider* asteroidCollider, SDL_Surface* surface, char* spriteFilePath, Circle circle, Position position, Movement movement)
{

	asteroidSprite = dynamic_cast<AsteroidSprite*>(m_asteroidSprite);
	entityType = m_asteroid_Entity;
}

Movement Asteroid::SetMovementInput(Keyboard::PlayerInput moveCommand)
{
	return movement;
}

void Asteroid::CreateSprite(SDL_Renderer* renderer)
{
	m_asteroidSprite = new AsteroidSprite(renderer);
}

