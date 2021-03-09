#pragma once
#include "IEntity.h"
//#include "sEntity.h"
class AsteroidCollider;
class ICollider;
class ISprite;
class AsteroidSprite;
class Asteroid : public IEntity 
{
public:
	Asteroid();

	void Split();
	void Explode();
	void Advance();
	int getXpos();
	int getYpos();
	int getXvelocity();
	int getYvelocity();
	int getSize();
	void CreateEntity(Entity_Type entityType, SDL_Window* window, SDL_Renderer* renderer, int renderIndex, Uint32 renderFlags,
		ISprite* sprite, ICollider* collider, SDL_Surface* image, char& spriteFilePath, Size size, Position position, Movement movementInput) override;
	void ModifyRects();
	//{
	//int xPos = x;
	//int yPos = y;
	//int velocityX = velX;
	//int velocityY = velY;
	//int size = passedsize;
	//}
	ICollider* GetCollider();
	ISprite* GetSprite();
	Position position;
	int xPos;
	int yPos;
	int velocityX;
	int velocityY;
	int size;
private:
	Entity_Type m_asteroid_Entity = Entity_Type::Asteroid_Entity;
	void CreateAsteroid(Entity_Type &entityType, SDL_Window* window, SDL_Renderer* renderer, int renderIndex,
						Uint32 renderFlags, ISprite* asteroidSprite, ICollider* asteroidCollider, 
						SDL_Surface* surface, char& spriteFilePath, Circle circle, Position position, Movement movement);
	AsteroidSprite* m_asteroidSprite;
	AsteroidCollider* m_asteroidCollider;
};

