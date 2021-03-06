#include "SpriteManager.h"
#include "PlayerSprite.h"
#include "AsteroidSprite.h"
using std::vector;
SpriteManager::SpriteManager()
{
}

SpriteManager::~SpriteManager()
{
}

std::vector<ISprite*> SpriteManager::GetSprites()
{
	return m_sprites;
}

void SpriteManager::SetSprites()
{

	playerSprite = new PlayerSprite();
	sprite = dynamic_cast<ISprite*>(playerSprite);
	m_sprites.push_back(sprite);
	
}
