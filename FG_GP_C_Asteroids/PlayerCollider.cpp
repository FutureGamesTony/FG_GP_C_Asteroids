#include "PlayerCollider.h"

PlayerCollider::PlayerCollider(Entity_Type entity_type, Size size, Position setPosition, Movement setMovement, SDL_Rect* collider)
{
	cirle.r = 0;
	cirle.x = 0;
	cirle.y = 0;
	CreateCollider(entity_type, size, setPosition, setMovement, collider, cirle);
}

PlayerCollider::~PlayerCollider()
{
}

void PlayerCollider::CreateCollider(Entity_Type entity_type, Size size, Position setPosition, Movement setMovement, SDL_Rect* collider, Circle circleCollider)
{
}

void PlayerCollider::handle_input()
{
}

void PlayerCollider::move()
{
}

void PlayerCollider::show()
{
}

Size PlayerCollider::GetSize()
{
	return Size();
}

Size PlayerCollider::SetSize()
{
	return Size();
}

void PlayerCollider::DrawCollider()
{
}

Position PlayerCollider::SetColliderPosition(Position colliderPosition)
{
	return Position();
}

Size PlayerCollider::GetCollider()
{
	return Size();
}

Position PlayerCollider::GetPosition()
{
	return Position();
}

bool PlayerCollider::HasCollided()
{
	return false;
}

bool PlayerCollider::Collision(bool collision)
{
	return false;
}
