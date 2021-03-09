#include "AsteroidSprite.h"
#include "SDL.h";
int AsteroidSprite::CreateSprite()
{
	return 0;
}

void AsteroidSprite::ModifyRects()
{
}

void AsteroidSprite::RenderSprite(SDL_Renderer* renderer, SDL_Texture* sprite)
{
}

SDL_Texture* AsteroidSprite::DrawSprite(SDL_Renderer* drawSprite)
{
	return nullptr;
}

const char* AsteroidSprite::GetFilepath()
{
	return filePath.c_str();
}

SDL_Texture* AsteroidSprite::GetSprite()
{
	return nullptr;
}
