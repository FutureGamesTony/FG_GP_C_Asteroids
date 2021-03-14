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
	PlayerSprite(SDL_Renderer* renderer);
	~PlayerSprite();

	SDL_Rect m_sourceRect { 640, 640, 32, 32 };
	SDL_Rect m_destinationRect ;

	int CreateSprite() override;
	SDL_Texture* DrawSprite(SDL_Renderer* renderer) override;
	SDL_Texture* GetSprite() override;
	void RenderSprite(SDL_Renderer* renderer, SDL_Texture* sprite);
	void ModifyRects(int rotation, int x, int y) override;
	void ModifyDegrees(int degrees);
	SDL_Rect GetSourceRect() override;
	SDL_Rect* GetDestRect();
	void SetDestinationRect(float x, float y);
	const char* GetFilepath() override;
	Position SetSpritePosition(Position destinationRect) override;
	EngineConfig::EntityType GetEntityType() override;
private:
	std::string m_playerPath = "assets/AsteroidShip.png";
	SDL_Texture* playerTex = nullptr;
	int degrees = 0;
	EngineConfig::EntityType m_playerEntity = EngineConfig::EntityType::Player_Entity;
	// Inherited via ISprite
};

