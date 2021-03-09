#pragma once
#include "ISprite.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
struct SDL_Renderer;


class AsteroidSprite : public ISprite
{
public:
	int CreateSprite() override;
	void ModifyRects() override;
	void RenderSprite(SDL_Renderer* renderer, SDL_Texture* sprite) override;
	SDL_Texture* DrawSprite(SDL_Renderer* drawSprite) override;
	const char* GetFilepath() override;
private:
	std::string filePath = "../assets/AsteroidLarge.png";

	// Inherited via ISprite
	SDL_Texture* GetSprite() override;
};

