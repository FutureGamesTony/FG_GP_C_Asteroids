#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "ICollider.h"
#include "Keyboard.h"
#include "SpriteManager.h"
#include "EngingConfig.h"
class ICollider;
class ISprite;
struct Circle;
class Keyboard;
class SpriteManager;




class IEntity { 
public: 
	virtual void CreateEntity(EngineConfig::EntityType entityType, SDL_Window* window, SDL_Renderer* renderer, int renderIndex, Uint32 renderFlags,
		ISprite* sprite, ICollider* collider, SDL_Surface* image, char* spriteFilePath, Size size, Circle circle, Position position, Movement movementInput) = 0;
	virtual Size SetSize() = 0;
	virtual Position SetPosition() = 0;
	virtual Movement SetMovementInput(EngineConfig::PlayerInput moveCommand) = 0;
	virtual void UpdateMovement(float moveX, float moveY, float xPos, float yPos) = 0;
	virtual ISprite* GetSprite() = 0;
	virtual ICollider* GetCollider() = 0;
	virtual void CreateSprite(SDL_Renderer* renderer) = 0;
	virtual void Update() = 0;
	virtual EngineConfig::EntityType GetEntityType() = 0;
};
