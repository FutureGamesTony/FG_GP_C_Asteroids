#pragma once
#include "IEntity.h"
#include "SDL.h"
#include "SDL_image.h"
enum Entity_Type;
struct Size;
struct Position;
struct Movement;
struct Circle
{
    int x, y;
    int r;
};
class ICollider
{
	virtual void CreateCollider(Entity_Type entity_type, Size size, Position setPosition, Movement setMovement, SDL_Rect* collider, Circle circleCollider) = 0;
    virtual void DrawCollider() = 0;
    virtual Position SetColliderPosition(Position colliderPosition) = 0;
    virtual Size GetCollider() = 0;
    virtual Position GetPosition() = 0;
    virtual bool HasCollided() = 0;
    virtual bool Collision(bool collision) = 0;
};