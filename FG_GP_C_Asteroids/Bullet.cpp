#include "Bullet.h"
#include "BulletSprite.h"
Bullet::Bullet()
{
}
Bullet::~Bullet()
{
    delete m_bulletSprite;
    m_bulletSprite = nullptr;
}
int Bullet::getXpos()
{
    return 0;
}

int Bullet::getYpos()
{
    return 0;
}

int Bullet::getXvelocity()
{
    return 0;
}

int Bullet::getYvelocity()
{
    return 0;
}

int Bullet::getSize()
{
    return 0;
}

void Bullet::CreateEntity(Entity_Type entityType, SDL_Window* window, SDL_Renderer* renderer, int renderIndex, Uint32 renderFlags, ISprite* sprite, ICollider* collider, SDL_Surface* image, char* spriteFilePath, Size size, Circle circle, Position position, Movement movementInput)
{
    m_bulletSprite = dynamic_cast<BulletSprite*>(sprite);
    entityType = m_bulletEntity;
}



ICollider* Bullet::GetCollider()
{
    return nullptr;
}

ISprite* Bullet::GetSprite()
{
    return nullptr;
}

Size Bullet::SetSize()
{
    return Size();
}

Position Bullet::SetPosition()
{
    return Position();
}

void Bullet::Update()
{
}

void Bullet::CreateSprite(SDL_Renderer* renderer)
{
}
