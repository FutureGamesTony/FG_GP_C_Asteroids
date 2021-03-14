#include "BulletSprite.h"

int BulletSprite::CreateSprite()
{
    return 0;
}

void BulletSprite::ModifyRects(int rotation, int x, int y)
{
}

SDL_Texture* BulletSprite::DrawSprite(SDL_Renderer* drawSprite)
{
    return nullptr;
}

void BulletSprite::RenderSprite(SDL_Renderer* renderer, SDL_Texture* sprite)
{
}

const char* BulletSprite::GetFilepath()
{
    return nullptr;
}

SDL_Texture* BulletSprite::GetSprite()
{
    return nullptr;
}

Position BulletSprite::SetSpritePosition(Position destinationRect)
{
    m_destinationRect.x = destinationRect.x;
    m_destinationRect.y = destinationRect.y;
    return destinationRect;
}

SDL_Rect BulletSprite::GetSourceRect()
{
    return SDL_Rect();
}
