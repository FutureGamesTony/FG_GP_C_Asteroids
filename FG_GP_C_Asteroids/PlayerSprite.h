#pragma once
#include "ISprite.h"
#include "SDL.h"
#include <iostream>
struct SDL_Renderer;
struct SDL_Texture;
struct SDL_Surface;
class PlayerSprite : public ISprite //public so it can be cast to a vector in a sprite handeler;
{
public:
	PlayerSprite();
	~PlayerSprite();

	SDL_Rect sourceRect{ 640,640,32,32 };
	SDL_Rect destinationRect{ 640,360,32,32 };

	int CreateSprite() override;
	SDL_Texture* DrawSprite(SDL_Renderer* renderer) override;
	SDL_Texture* GetSprite() override;
	void RenderSprite(SDL_Renderer* renderer, SDL_Texture* sprite);
	void ModifyRects() override;
	void ModifyDegrees(int degrees);
	SDL_Rect* GetSourceRect();
	SDL_Rect* GetDestRect();
	PlayerSprite* GetThis();
	const char* GetFilepath() override;

private:
	std::string m_playerPath = "assets/AsteroidShip.png";
	SDL_Texture* playerTex;
	int degrees = 180;
	// Inherited via ISprite

};

