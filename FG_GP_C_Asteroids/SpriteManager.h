#pragma once
#include <vector>
#include "ISprite.h"
class AsteroidSprite;
class PlayerSprite;
class EntityManager;
class SpriteManager
{
public:
	SpriteManager(SDL_Renderer* renderer, EntityManager* entityManager);
	~SpriteManager();
	std::vector<ISprite*> GetSprites();
	ISprite* GetISprite();

private:
	void SetSprite(SDL_Renderer* renderer);
	void SetAsteroidSprite(SDL_Renderer* renderer);
	ISprite* sprite = nullptr;
	PlayerSprite* playerSprite = nullptr;
	EntityManager* m_entityManager;
	std::vector<AsteroidSprite*>s_asteroidSprites;
	std::vector<ISprite*> m_sprites;
};

