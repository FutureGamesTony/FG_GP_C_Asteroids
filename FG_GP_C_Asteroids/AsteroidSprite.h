#pragma once
#include "ISprite.h"
struct SDL_Renderer;

class AsteroidSprite : public ISprite
{
public:
	int CreateSprite(SDL_Window* window, SDL_Texture* texture, int pixelFormat, int textureAccess, int width, int height) override;
	void ModifyRects() override;
	void RenderSprite(SDL_Renderer* renderer, SDL_Texture* sprite) override;
	SDL_Texture* DrawSprite(SDL_Renderer* drawSprite) override;
};

