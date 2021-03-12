#pragma once
#include <vector>
#include "ISprite.h"
class AsteroidSprite;
class PlayerSprite;
class EntityManager;
class Player;
class SpriteManager
{
public:
	SpriteManager(SDL_Renderer* renderer, Player* player);
	~SpriteManager();
	std::vector<ISprite*> GetSprites();
	ISprite* GetISprite();
	void SetSprite(ISprite* sprite);

private:

	void SetAsteroidSprite(SDL_Renderer* renderer);
	ISprite* sprite = nullptr;
	PlayerSprite* playerSprite = nullptr;
	EntityManager* m_entityManager;
	std::vector<AsteroidSprite*>s_asteroidSprites;
	std::vector<ISprite*> m_sprites;
};

