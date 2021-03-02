#include "PlayerSprite.h"
#include "SDL.h"
PlayerSprite::PlayerSprite(SDL_Renderer* renderer)
{

}

PlayerSprite::~PlayerSprite()
{
}

void PlayerSprite::DrawPlayer(SDL_Renderer* drawPlayer)
{
	SDL_RenderDrawLine(drawPlayer, 0, 1, 2, 3);
}
