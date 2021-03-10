#include "SpriteManager.h"
#include "PlayerSprite.h"
#include "AsteroidSprite.h"
using std::vector;
SpriteManager::SpriteManager(SDL_Renderer* renderer)
{
	SetPlayerSprite(renderer);
	SetAsteroidSprite(renderer);
}

SpriteManager::~SpriteManager()
{
}

std::vector<ISprite*> SpriteManager::GetSprites()
{
	return m_sprites;
}

ISprite* SpriteManager::GetISprite()
{
	return sprite;
}

void SpriteManager::SetPlayerSprite(SDL_Renderer* renderer)
{

	playerSprite = new PlayerSprite(renderer);
	sprite = dynamic_cast<ISprite*>(playerSprite);
	m_sprites.push_back(sprite);
	
}

void SpriteManager::SetAsteroidSprite(SDL_Renderer* renderer)
{
	s_asteroidSprites.push_back(new AsteroidSprite(renderer));
	m_sprites.push_back(s_asteroidSprites[s_asteroidSprites.size() - 1]);
}
