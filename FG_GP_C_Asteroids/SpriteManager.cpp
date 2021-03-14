#include "SpriteManager.h"
#include "PlayerSprite.h"
#include "AsteroidSprite.h"
#include "Player.h"
#include "EntityManager.h"
using std::vector;
SpriteManager::SpriteManager(SDL_Renderer* renderer, Player* player)
{
	SetPlayerSprite(renderer);
	SetAsteroidSprite(renderer);
}

SpriteManager::~SpriteManager()
{
	delete playerSprite;
	playerSprite = nullptr;
	for (AsteroidSprite* asteroidSprite : s_asteroidSprites)
	{
		delete asteroidSprite;
		asteroidSprite = nullptr;
	}
	s_asteroidSprites.clear();
	s_asteroidSprites.resize(0);
	
}

std::vector<ISprite*> SpriteManager::GetSprites()
{
	return m_sprites;
}

ISprite* SpriteManager::GetISprite()
{
	return sprite;
}

void SpriteManager::SetSprite(ISprite* sprite)
{
	
	m_sprites.push_back(dynamic_cast<ISprite*>(sprite));
	
}

void SpriteManager::SetAsteroidSprite(SDL_Renderer* renderer)
{
	s_asteroidSprites.push_back(new AsteroidSprite(renderer));
	m_sprites.push_back(s_asteroidSprites[s_asteroidSprites.size() - 1]);
}

void SpriteManager::SetPlayerSprite(SDL_Renderer* renderer)
{
	playerSprite = new PlayerSprite(renderer);
	m_sprites.push_back(playerSprite);
}

void SpriteManager::SetPlayerSpriteRotationPosition(int rotation, int x, int y)
{
	playerSprite->ModifyRects(rotation, x, y);
}
