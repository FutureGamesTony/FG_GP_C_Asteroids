#pragma once
#include "ICollider.h"
class AsteroidCollider : public ICollider
{
	void CreateCollider(Entity_Type entity_type, Size size, Position setPosition, Movement setMovement, SDL_Rect* collider) override;
};

