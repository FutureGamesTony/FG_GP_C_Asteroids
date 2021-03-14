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
	void CreateAsteroid(EngineConfig::EntityType entity, Circle circle, ICollider* collider, ISprite* sprite, Position position, Size size);
	void CreateBullet();
	void CreateEnteties();
	void MovePlayer();
private:
	void SetEnteties();
	std::vector<IEntity*>m_enteties;
	EngineConfig::EntityType entityType;
	std::vector<ISprite*> sprites; 
	Player* m_player;
	Asteroid* m_asteroid;
	std::vector<Asteroid*> m_asteroids; //asteroids will almost never be alone so created a vector. 

};

