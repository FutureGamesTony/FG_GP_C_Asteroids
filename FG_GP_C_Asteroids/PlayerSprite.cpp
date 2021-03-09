#include "PlayerSprite.h"
#include "SDL.h"
#include "SDL_image.h"
PlayerSprite::PlayerSprite()
{
	sourceRect.h = 16;
	sourceRect.w = 16;
	destinationRect.h = 50;
	destinationRect.w = 50;
}

PlayerSprite::~PlayerSprite()
{
}

int PlayerSprite::CreateSprite(SDL_Window* window, SDL_Texture* texture, int pixelFormat, int textureAccess, int width, int height)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
		return 3;
	}
}

SDL_Texture* PlayerSprite::DrawPlayer(SDL_Renderer* drawPlayer)
{
	//SDL_RenderDrawLine(drawPlayer, 10, 100, 200, 300);
	SDL_Surface* tempSurface = IMG_Load("assets/AsteroidShip.png"); //()
	SDL_Texture* playerTex = SDL_CreateTextureFromSurface(drawPlayer, tempSurface);
	SDL_FreeSurface(tempSurface);
	return playerTex;
}

void PlayerSprite::RenderPlayer(SDL_Renderer* renderer, SDL_Texture* sprite)
{
	SDL_RenderCopy(renderer, sprite, NULL, GetDestRect());
}

void PlayerSprite::ModifyRects()
{
	sourceRect.h = 16;
	sourceRect.w = 16;
	destinationRect.h = 50;
	destinationRect.w = 50;
}

SDL_Rect* PlayerSprite::GetSourceRect()
{
	return &sourceRect;
}

SDL_Rect* PlayerSprite::GetDestRect()
{
	return &destinationRect;
}


