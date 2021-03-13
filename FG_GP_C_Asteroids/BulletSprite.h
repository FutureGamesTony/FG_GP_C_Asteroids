#pragma once
#include "ISprite.h"
class BulletSprite : public ISprite
{
	// Inherited via ISprite
	int CreateSprite() override;
	void ModifyRects() override;
	SDL_Texture* DrawSprite(SDL_Renderer* drawSprite) override;
	void RenderSprite(SDL_Renderer* renderer, SDL_Texture* sprite) override;
	const char* GetFilepath() override;
	SDL_Texture* GetSprite() override;
};

