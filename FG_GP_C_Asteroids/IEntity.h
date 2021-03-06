#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "ICollider.h"
class ISprite;
struct Size // Just wanted an easier way to set size
{
	int sizeX;
	int sizeY;
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
	Enemy_Asteroid,

};
class IEntity { //class inherited by every entity created, must be public,
public:
	virtual void CreateEntity(Entity_Type entityType, SDL_Window* window, SDL_Renderer* renderer, int renderIndex, Uint32 renderFlags, //TODO: Remove comments 
		ISprite* sprite, ICollider* collider, SDL_Surface* image, char& spriteFilePath, Size size, Position position, Movement movementInput) = 0; // This is an attempt to get everything in the SpriteClass 
																											 // that's needed to create a sprite including collider and sprite
	virtual void Update() = 0;
};
