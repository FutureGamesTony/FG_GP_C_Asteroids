#pragma once
#include "IEntity.h"

#include <iostream>
//#include "sEntity.h"
class CollisionManager;
class AsteroidCollider;
class ICollider;
class ISprite;
class AsteroidSprite;
class EntityType;
class Asteroid : public IEntity 
{
public:
	Asteroid(EngineConfig::EntityType entityType, Circle circle, ICollider* collider, ISprite* sprite, Position position, Size size);
	~Asteroid();

	void Split();
	void Explode();
	void Advance();
	int getXpos();
	int getYpos();
	int getXvelocity();
	int getYvelocity();
	int getSize();
	void CreateEntity(EngineConfig::EntityType entityType, SDL_Window* window, SDL_Renderer* renderer, int renderIndex, Uint32 renderFlags,
		ISprite* sprite, ICollider* collider, SDL_Surface* image, char* spriteFilePath, Size size, Circle circle, Position position, Movement movementInput) override;
	void UpdateMovement(float moveX, float moveY, float xPos, float yPos) override;
	ICollider* GetCollider() override;
	ISprite* GetSprite() override;
	Size SetSize() override;
	Position SetPosition() override;
	void Update() override;
	SDL_Rect* collider = nullptr;
	Circle circleCollider;
	int velocityX;
	int velocityY;
	virtual void CreateSprite(SDL_Renderer* renderer) override;
	EngineConfig::EntityType GetEntityType() override;

private:
	EngineConfig::EntityType m_asteroid_Entity;
	void CreateAsteroid(EngineConfig::EntityType entityType, SDL_Window* window, SDL_Renderer* renderer, int renderIndex,
						Uint32 renderFlags, ISprite* asteroidSprite, ICollider* asteroidCollider, 
						SDL_Surface* surface, char* spriteFilePath, Circle circle, Position position, Movement movement);
	std::string filePath = "assets/AsteroidLarge.png";
	ISprite* m_asteroidSprite;
	ICollider* m_asteroidCollider;
	Position m_position;
	Movement m_movement;
	Size m_size;
	Movement SetMovementInput(EngineConfig::PlayerInput moveCommand) override;
};

