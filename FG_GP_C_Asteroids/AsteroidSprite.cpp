#include "AsteroidSprite.h"
#include "SDL.h";
AsteroidSprite::AsteroidSprite(SDL_Renderer* renderer)
{
	sourceRect = { 0, 0, 32, 32 };
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

void AsteroidSprite::ModifyRects(int rotation, int x, int y)
{

}

void AsteroidSprite::RenderSprite(SDL_Renderer* renderer, SDL_Texture* sprite)
{
	SDL_RenderCopy(renderer, sprite, NULL, GetDestRect());
}

SDL_Texture* AsteroidSprite::DrawSprite(SDL_Renderer* drawSprite)
{
	if (m_enemyTex != SDL_CreateTextureFromSurface(drawSprite, IMG_Load(GetFilepath()))) 
	{
		m_enemyTex = SDL_CreateTextureFromSurface(drawSprite, IMG_Load(GetFilepath()));
		SDL_FreeSurface(IMG_Load(GetFilepath()));
	}
	return m_enemyTex;
}

const char* AsteroidSprite::GetFilepath()
{
	return filePath.c_str();
}

SDL_Rect* AsteroidSprite::GetDestRect()
{
	return &m_destinationRect;
}

SDL_Texture* AsteroidSprite::GetSprite()
{
	return m_enemyTex;
}

Position AsteroidSprite::SetSpritePosition(Position destinationRect)
{
	m_destinationRect.x = destinationRect.x;
	m_destinationRect.y = destinationRect.y;
	return destinationRect;
}

EngineConfig::EntityType AsteroidSprite::GetEntityType()
{
	return m_asteroidEntity;
}

SDL_Rect AsteroidSprite::GetSourceRect()
{
	return sourceRect;
}
