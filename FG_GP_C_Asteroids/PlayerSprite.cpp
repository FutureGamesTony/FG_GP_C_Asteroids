#include "PlayerSprite.h"
#include "SpriteManager.h"
#include "SDL.h"
#include "SDL_image.h"
PlayerSprite::PlayerSprite()
{

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
	SDL_Surface* tempSurface = IMG_Load(GetFilepath());
	playerTex = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	return playerTex;
}

SDL_Texture* PlayerSprite::GetSprite()
{
	return playerTex;
}
//int i = 0;
void PlayerSprite::RenderSprite(SDL_Renderer* renderer, SDL_Texture* sprite)
{
	//SDL_RenderCopy(renderer, sprite, NULL, GetDestRect());
	//i++;
	SDL_RenderCopyEx(renderer, sprite, NULL, GetDestRect(), degrees, NULL, SDL_FLIP_VERTICAL);

}
//int i = 0;
void PlayerSprite::ModifyRects()
{
	//i++;
	//sourceRect.h = 16;
	//sourceRect.w = 16;
	//destinationRect.h = 32;
	//destinationRect.w = 32;
	//destinationRect.x = i;
	//destinationRect.y = i;
}

void PlayerSprite::ModifyDegrees(int newValue)
{
	degrees = newValue;
}

SDL_Rect* PlayerSprite::GetSourceRect()
{
	return &sourceRect;
}

SDL_Rect* PlayerSprite::GetDestRect()
{
	return &destinationRect;
}


const char* PlayerSprite::GetFilepath()
{
	return m_playerPath.c_str();
}


