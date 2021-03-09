#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "ICollider.h"
class ICollider;
class ISprite;//TODO: Remove comments
struct Circle;
struct Size // Just wanted an easier way to set size
{
	int width;
	int height;
};
struct Position // Just wanted an easier way to set position
{
	int xPosition;
	int yPosition;
};

struct Movement // Just wanted an easier way to set movement
{
	int movementX;
	int movementY;
};
enum Entity_Type //to easy identify what entity for an entity handler, without having to compare objects. 
{

	Player_Entity,
	Bullet_Entity,
	Asteroid_Entity,

}; //TODO: Remove comments 
class IEntity { //class inherited by every entity created, must be public
public: 
	/*
	* by creating functions in here as we discover there needs in various scripts, we make sure all scripts using this class initialize everything that's needed.
		*/
	// This is an attempt to get everything in the SpriteClass that's needed to create a sprite including collider and sprite
	virtual void CreateEntity(Entity_Type entityType, SDL_Window* window, SDL_Renderer* renderer, int renderIndex, Uint32 renderFlags,
		ISprite* sprite, ICollider* collider, SDL_Surface* image, char* spriteFilePath, Size size, Circle circle, Position position, Movement movementInput) = 0; 
	virtual Size SetSize() = 0;
	virtual Position SetPosition() = 0;
	virtual Movement SetMovementInput() = 0;
	virtual void UpdateMovement() = 0;
	virtual ISprite* GetSprite() = 0;


	virtual void Update() = 0;
};
