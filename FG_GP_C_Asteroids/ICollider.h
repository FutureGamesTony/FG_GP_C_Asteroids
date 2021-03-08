#pragma once
#include "IEntity.h"
#include "SDL.h"
#include "SDL_image.h"
enum Entity_Type;
struct Size;
struct Position;
struct Movement;
class ICollider
{
	virtual void CreateCollider(Entity_Type entity_type, Size size, Position setPosition, Movement setMovement, SDL_Rect* collider) = 0;
};