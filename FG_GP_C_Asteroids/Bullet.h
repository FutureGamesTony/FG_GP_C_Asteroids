#pragma once
#include "IEntity.h"
#include "EngingConfig.h"
class BulletSprite;
class CollisionManager;
class AsteroidCollider;
class ICollider;
class ISprite;

class Bullet : public IEntity
{
	Bullet(); 
	~Bullet();
	int getXpos();
	int getYpos();
	int getXvelocity();
	int getYvelocity();
	int getSize();
	void CreateEntity(EngineConfig::EntityType entityType, SDL_Window* window, SDL_Renderer* renderer, int renderIndex, Uint32 renderFlags,
		ISprite* sprite, ICollider* collider, SDL_Surface* image, char* spriteFilePath, Size size, Circle circle, Position position, Movement movementInput) override;

	ICollider* GetCollider() override;
	ISprite* GetSprite() override;
	Size SetSize() override;
	Position SetPosition() override;
	void Update() override;
	virtual void CreateSprite(SDL_Renderer* renderer) override;
	SDL_Rect* collider = nullptr;
	Circle circleCollider;
	int velocityX;
	int velocityY;
	EngineConfig::EntityType m_bulletEntity = EngineConfig::EntityType::Bullet_Entity;
	BulletSprite* m_bulletSprite = nullptr;
};

