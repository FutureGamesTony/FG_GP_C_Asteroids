#pragma once
#include "IEntity.h"
//#include "sEntity.h"
class AsteroidCollider;
class ICollider;
class Asteroid : public IEntity 
{
public:
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
	Asteroid(float x, float y, float velX, float velY, int passedsize);
	//{
	//int xPos = x;
	//int yPos = y;
	//int velocityX = velX;
	//int velocityY = velY;
	//int size = passedsize;
	//}
	ICollider* GetCollider();
	
	int xPos;
	int yPos;
	int velocityX;
	int velocityY;
	int size;
private:
	AsteroidCollider* SetCollider();
	AsteroidCollider* m_asteroidCollider;
};

