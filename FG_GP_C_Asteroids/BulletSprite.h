#pragma once
#include "ISprite.h"
#include "SDL.h"
#include "SDL_image.h"

class BulletSprite : public ISprite
{
	// Inherited via ISprite
	int CreateSprite() override;
	void ModifyRects(int rotation, int x, int y) override;
	SDL_Texture* DrawSprite(SDL_Renderer* drawSprite) override;
	void RenderSprite(SDL_Renderer* renderer, SDL_Texture* sprite) override;
	const char* GetFilepath() override;
	SDL_Texture* GetSprite() override;
	SDL_Rect m_destinationRect;
	// Inherited via ISprite
	Position SetSpritePosition(Position destinationRect) override;
	SDL_Rect GetSourceRect() override;
};

