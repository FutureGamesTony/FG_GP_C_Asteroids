#pragma once
#include "sEntity.h"
#include "IEntity.h"
#include <vector>
class Asteroid;
class Player;
class EntityManager : sEntity
{
public:
	EntityManager();
	~EntityManager();
	std::vector<IEntity*> GetEnteties();
	IEntity* GetPlayer();
	void Func();
	Asteroid* ast;
private:
	Entity_Type entityType;
	SDL_Window* window; 
	SDL_Renderer* renderer; int renderIndex; 
	Uint32 renderFlags;
	ISprite* sprite; 
	Player* m_player;
	ICollider* collider; 
	SDL_Surface* image; 
	char* spriteFilePath; 
	Size size; 
	Position position; 
	Movement movementInput;
};

