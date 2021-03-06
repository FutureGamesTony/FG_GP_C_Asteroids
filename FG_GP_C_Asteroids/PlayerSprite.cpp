#include "PlayerSprite.h"
#include "SDL.h"
#include "SDL_image.h"
PlayerSprite::PlayerSprite()
{
	
}

PlayerSprite::~PlayerSprite()
{
}

int PlayerSprite::CreateSprite(SDL_Window* window, int pixelFormat, int textureAccess, int width, int height)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
		return 3;
	}

}

void PlayerSprite::DrawPlayer(SDL_Renderer* drawPlayer)
{

	SDL_RenderDrawLine(drawPlayer, 10, 100, 200, 300);
}
