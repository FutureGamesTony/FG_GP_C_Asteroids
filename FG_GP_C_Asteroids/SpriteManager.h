#pragma once
#include <vector>
#include "ISprite.h"
class AsteroidSprite;
class PlayerSprite;
class SpriteManager
{
public:
	SpriteManager(SDL_Renderer* renderer);
	~SpriteManager();
	std::vector<ISprite*> GetSprites();
	ISprite* GetISprite();

private:
	void SetPlayerSprite(SDL_Renderer* renderer);
	void SetAsteroidSprite();
	ISprite* sprite = nullptr;
	PlayerSprite* playerSprite = nullptr;
	std::vector<AsteroidSprite*>s_asteroidSprites;
	std::vector<ISprite*> m_sprites;
};

