#include "PlayerSprite.h"
#include "SDL.h"
PlayerSprite::PlayerSprite()
{
	
}

PlayerSprite::~PlayerSprite()
{
}

void PlayerSprite::DrawPlayer(SDL_Renderer* drawPlayer)
{

	SDL_RenderDrawLine(drawPlayer, 10, 100, 200, 300);
}
