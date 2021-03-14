#include "PlayerSprite.h"
#include "SpriteManager.h"
#include "SDL.h"
#include "SDL_image.h"

PlayerSprite::PlayerSprite(SDL_Renderer* renderer)
{
	m_destinationRect = { 640,360,32,32 };
	
	DrawSprite(renderer);
}

PlayerSprite::~PlayerSprite()
{
}

int PlayerSprite::CreateSprite()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
		return 3;
	}
}

SDL_Texture* PlayerSprite::DrawSprite(SDL_Renderer* renderer)
{

	if (playerTex != SDL_CreateTextureFromSurface(renderer, IMG_Load(GetFilepath())))
	{
		playerTex = SDL_CreateTextureFromSurface(renderer, IMG_Load(GetFilepath()));
		SDL_FreeSurface(IMG_Load(GetFilepath()));
	}
	return playerTex;
}

SDL_Texture* PlayerSprite::GetSprite()
{
	return playerTex;
}
//int i = 0;
void PlayerSprite::RenderSprite(SDL_Renderer* renderer, SDL_Texture* sprite)
{

	SDL_RenderCopyEx(renderer, sprite, NULL, GetDestRect(), degrees, NULL, SDL_FLIP_NONE);

}
//int i = 0;
void PlayerSprite::ModifyRects(int rotation, int x, int y)
{
	ModifyDegrees(rotation);
	SetDestinationRect(x, y);
}

void PlayerSprite::ModifyDegrees(int newValue)
{
	degrees = newValue;
}

SDL_Rect PlayerSprite::GetSourceRect()
{
	return m_sourceRect;
}

SDL_Rect* PlayerSprite::GetDestRect()
{
	return &m_destinationRect;
}

void PlayerSprite::SetDestinationRect(float x, float y)
{
	m_destinationRect.x = x;
	m_destinationRect.y = y;
}


const char* PlayerSprite::GetFilepath()
{
	return m_playerPath.c_str();
}

Position PlayerSprite::SetSpritePosition(Position destinationRect)
{
	m_destinationRect.x = destinationRect.x;
	m_destinationRect.y = destinationRect.y;
	return destinationRect;
}

EngineConfig::EntityType PlayerSprite::GetEntityType()
{
	return m_playerEntity;
}


