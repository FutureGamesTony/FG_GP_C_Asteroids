#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "ICollider.h"
#include "Keyboard.h"
#include "SpriteManager.h"
#include "EngingConfig.h"
class ICollider;
class ISprite;//TODO: Remove comments
struct Circle;
class Keyboard;
class SpriteManager;




class IEntity { //class inherited by every entity created, must be public
public: 

	/*
	* by creating functions in here as we discover there needs in various scripts, we make sure all scripts using this class initialize everything that's needed.
		*/
	// This is an attempt to get everything in the SpriteClass that's needed to create a sprite including collider and sprite
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
