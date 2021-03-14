#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "EngingConfig.h"
class EntityType;
struct Size;
struct Position;
struct Movement;
struct SDL_Rect;
struct Circle;
class ICollider
{
	virtual void CreateCollider(EngineConfig::EntityType entity_type, Size size, Position setPosition, Movement setMovement, SDL_Rect* collider, Circle circleCollider) = 0;

    virtual Position SetColliderPosition(Position colliderPosition) = 0;
    virtual Size GetCollider() = 0;
    virtual Position GetPosition() = 0;
    virtual bool HasCollided() = 0;
    virtual bool Collision(bool collision) = 0;
};