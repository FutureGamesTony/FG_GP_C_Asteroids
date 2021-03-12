#include "AsteroidCollider.h"
#include "EngingConfig.h"

#include "CollisionManager.h"
AsteroidCollider::AsteroidCollider(Entity_Type entity_type, CollisionManager* collisionManager, Size size, Position setPosition, Movement setMovement, Circle circleCollider)
{
    CreateCollider(entity_type, size, setPosition, setMovement, nullptr, circleCollider);
    for(AsteroidCollider* asteroid  :  s_asteroidColliders)
    {
        collisionManager->SetColliders(asteroid);
    }
    
}
void AsteroidCollider::CreateCollider(Entity_Type entity_type, Size size, Position setPosition, Movement setMovement, SDL_Rect* collider, Circle circleCollider)
{
    m_collider = circleCollider;

    
    
    size.height = circleCollider.r * 2;
    size.width = circleCollider.r * 2;
    hasCollided = false;
}



Position AsteroidCollider::SetColliderPosition(Position colliderPosition)
{
    m_collider.x = colliderPosition.xPosition;
    m_collider.y = colliderPosition.yPosition;
    position = colliderPosition;
    return colliderPosition;
}

Size AsteroidCollider::GetCollider()
{
	return size;
}

bool AsteroidCollider::HasCollided()
{
    return hasCollided;
}

bool AsteroidCollider::Collision(bool collision)
{
    hasCollided = collision;
    return hasCollided;
}

Position AsteroidCollider::GetPosition()
{
    return position;
}
