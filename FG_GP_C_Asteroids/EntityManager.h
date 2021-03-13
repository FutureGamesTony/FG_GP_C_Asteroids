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
	EntityManager();
	~EntityManager();
	std::vector<IEntity*> GetEnteties();
	
	IEntity* GetEntity();
	void Func();
	Asteroid* ast;
	EntityManager* GetEntityManager();
	void CreatePlayer();
	void CreateAsteroid();
	void CreateEnteties();

private:
	void SetEnteties();
	std::vector<IEntity*>m_enteties;
	Entity_Type entityType;
	SDL_Window* window; 
	SDL_Renderer* renderer; int renderIndex; 
	Uint32 renderFlags;
	std::vector<ISprite*> sprites; 
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

