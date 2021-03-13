#pragma once
#include "ISprite.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
struct SDL_Renderer;
struct SDL_Texture;

class AsteroidSprite : public ISprite
{
public:
	AsteroidSprite(SDL_Renderer* renderer);
	~AsteroidSprite();
	int CreateSprite() override;
	void ModifyRects() override;
	void RenderSprite(SDL_Renderer* renderer, SDL_Texture* sprite) override;
	SDL_Texture* DrawSprite(SDL_Renderer* drawSprite) override;
	const char* GetFilepath() override;
	SDL_Rect* GetDestRect();
private:
	std::string filePath = "assets/AsteroidLarge.png";
	SDL_Texture* m_enemyTex;
	// Inherited via ISprite
	SDL_Texture* GetSprite() override;
	SDL_Rect sourceRect{ 0,0,32,32 };
	SDL_Rect destinationRect{ 1,1,64,64 };
};

