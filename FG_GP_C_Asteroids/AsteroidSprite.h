#pragma once
#include "ISprite.h"
#include "SDL.h"
#include "SDL_image.h"
#include "IEntity.h"
#include <iostream>
struct SDL_Renderer;
struct SDL_Texture;
class IEntity;
class AsteroidSprite : public ISprite
{
public:
	AsteroidSprite(SDL_Renderer* renderer);
	~AsteroidSprite();
	int CreateSprite() override;
	void ModifyRects(int rotation, int x, int y) override;
	void RenderSprite(SDL_Renderer* renderer, SDL_Texture* sprite) override;
	SDL_Texture* DrawSprite(SDL_Renderer* drawSprite) override;
	const char* GetFilepath() override;
	SDL_Rect* GetDestRect();
	virtual SDL_Rect GetSourceRect() override;
	Position SetSpritePosition(Position destinationRect) override;
	EngineConfig::EntityType GetEntityType() override;
private:
	std::string filePath = "assets/AsteroidLarge.png";
	SDL_Texture* m_enemyTex;
	// Inherited via ISprite
	SDL_Texture* GetSprite() override;
	SDL_Rect sourceRect;//{ 0,0,32,32 };
	SDL_Rect m_destinationRect/*{ 1,1,64,64 }*/;

	EngineConfig::EntityType m_asteroidEntity = EngineConfig::EntityType::Asteroid_Entity;
	// Inherited via ISprite

	// Inherited via ISprite
};

