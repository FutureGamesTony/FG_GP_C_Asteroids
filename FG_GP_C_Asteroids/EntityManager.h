#pragma once
#include "sEntity.h"
#include "IEntity.h"
#include <vector>
class Asteroid;
class Player;
class CollisionManager;
class EntityManager 
{
public:
	EntityManager(CollisionManager* collisionManger);
	~EntityManager();
	std::vector<IEntity*> GetEnteties();
	
	IEntity* GetEntity();
	void Func();
	Asteroid* ast;
private:
	void CreatePlayer();
	void CreateAsteroid(const char* path, CollisionManager* collisionManager);
	void CreateEnteties();
	std::vector<IEntity*>m_enteties;
	Entity_Type entityType;
	SDL_Window* window; 
	SDL_Renderer* renderer; int renderIndex; 
	Uint32 renderFlags;
	ISprite* sprite; 
	Player* m_player;
	std::vector<Asteroid*> m_asteroids; //asteroids will almost never be alone so created a vector. 
	ICollider* collider; 
	SDL_Surface* image; 
	const char* spriteFilePath; 
	Size size; 
	int asteroidRadius = 10;
	Position position; 
	Movement movementInput;
};

