#include "SpriteManager.h"
#include "PlayerSprite.h"
#include "AsteroidSprite.h"
#include "Player.h"
#include "EntityManager.h"
using std::vector;
SpriteManager::SpriteManager(SDL_Renderer* renderer, Player* player)
{
	SetSprite(player->GetSprite());
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

void SpriteManager::SetSprite(ISprite* sprite)
{
	ISprite* temp;
	temp = dynamic_cast<ISprite*>(sprite);
	m_sprites.push_back(temp);
	
}

void SpriteManager::SetAsteroidSprite(SDL_Renderer* renderer)
{
	s_asteroidSprites.push_back(new AsteroidSprite(renderer));
	m_sprites.push_back(s_asteroidSprites[s_asteroidSprites.size() - 1]);
}
