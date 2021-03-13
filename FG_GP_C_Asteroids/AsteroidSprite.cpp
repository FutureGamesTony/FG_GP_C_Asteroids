#include "AsteroidSprite.h"
#include "SDL.h";
AsteroidSprite::AsteroidSprite(SDL_Renderer* renderer)
{
	DrawSprite(renderer);
}
AsteroidSprite::~AsteroidSprite()
{
}
int AsteroidSprite::CreateSprite()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
		return 3;
	}
}

void AsteroidSprite::ModifyRects()
{
}

void AsteroidSprite::RenderSprite(SDL_Renderer* renderer, SDL_Texture* sprite)
{
	SDL_RenderCopy(renderer, sprite, NULL, GetDestRect());
}

SDL_Texture* AsteroidSprite::DrawSprite(SDL_Renderer* drawSprite)
{
	SDL_Surface* tempSurface = IMG_Load(GetFilepath());
	m_enemyTex = SDL_CreateTextureFromSurface(drawSprite, tempSurface);
	SDL_FreeSurface(tempSurface);
	
	return m_enemyTex;
}

const char* AsteroidSprite::GetFilepath()
{
	return filePath.c_str();
}

SDL_Rect* AsteroidSprite::GetDestRect()
{
	return &destinationRect;
}

SDL_Texture* AsteroidSprite::GetSprite()
{
	return m_enemyTex;
}
