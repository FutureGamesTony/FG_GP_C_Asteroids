#pragma once
#include "ISprite.h"
class AsteroidSprite : public ISprite
{
public:
	int CreateSprite(SDL_Window* window, SDL_Texture* texture, int pixelFormat, int textureAccess, int width, int height) override;
};

