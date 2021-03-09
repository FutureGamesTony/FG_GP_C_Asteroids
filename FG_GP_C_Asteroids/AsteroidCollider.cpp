#include "AsteroidCollider.h"
#include "EngingConfig.h"


void AsteroidCollider::CreateCollider(Entity_Type entity_type, Size size, Position setPosition, Movement setMovement, SDL_Rect* collider, Circle cricleCollider)
{
    isCoolided = false;
}

AsteroidCollider::AsteroidCollider(int x, int y)
{
    //Initialize the offsets
    mPosX = x;
    mPosY = y;

    //Set collision circle size
    m_Collider.r = DOT_WIDTH / 2;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;

    //Move collider relative to the circle
    ShiftColliders();
}

void AsteroidCollider::HandleEvent(SDL_Event& e)
{
}

void AsteroidCollider::Move()
{
    //Move the dot left or right
    mPosX += mVelX;
    ShiftColliders();

}

void AsteroidCollider::Render()
{
}

Circle& AsteroidCollider::GetCollider()
{
	// TODO: insert return statement here
	return m_Collider;
}

void AsteroidCollider::IsCollided(bool collision)
{
    isCoolided = collision;
}

void AsteroidCollider::ShiftColliders()
{
}
