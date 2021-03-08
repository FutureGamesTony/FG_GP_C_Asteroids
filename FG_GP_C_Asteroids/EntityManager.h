#pragma once
#include "sEntity.h"
#include "IEntity.h"
class Asteroid;
class Player;
class EntityManager : sEntity
{
public:
	EntityManager();
	~EntityManager();
	void Func();
	Asteroid* ast;
private:
	Entity_Type entityType;
	SDL_Window* window; 
	SDL_Renderer* renderer; int renderIndex; 
	Uint32 renderFlags;
	ISprite* sprite; 
	ICollider* collider; 
	SDL_Surface* image; 
	char* spriteFilePath; 
	Size size; 
	Position position; 
	Movement movementInput;
};

