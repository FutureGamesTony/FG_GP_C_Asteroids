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
	void CreatePlayer();
	void CreateAsteroid(EngineConfig::EntityType entity, Circle circle, ICollider* collider, ISprite* sprite, Position position, Size size);
	void CreateBullet();
	void CreateEnteties();
	void UpdateEnteties();
	void UpdatePlayer(EngineConfig::PlayerInput playerInput);
	void UpdateAsteroids();

private:
	void SetEnteties();
	std::vector<IEntity*>m_enteties;
	EngineConfig::EntityType entityType;
	std::vector<ISprite*> sprites; 
	std::vector<ICollider*> colliders; 
	Player* m_player = nullptr;
	Asteroid* m_asteroid = nullptr;
	std::vector<Asteroid*> m_asteroids; 

};

