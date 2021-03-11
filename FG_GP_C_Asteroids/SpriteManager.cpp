#include "SpriteManager.h"
#include "PlayerSprite.h"
#include "AsteroidSprite.h"
#include "EntityManager.h"
using std::vector;
SpriteManager::SpriteManager(SDL_Renderer* renderer, EntityManager* entityManager)
{
	SetPlayerSprite(renderer);
	SetAsteroidSprite(renderer);
	m_entityManager = entityManager;
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

void SpriteManager::SetSprite(SDL_Renderer* renderer)
{

	//playerSprite = (PlayerSprite*)m_entityManager->GetEntity()->GetSprite();
	//sprite = dynamic_cast<ISprite*>(playerSprite);
	//m_sprites.push_back(sprite);
	
}

void SpriteManager::SetAsteroidSprite(SDL_Renderer* renderer)
{
	s_asteroidSprites.push_back(new AsteroidSprite(renderer));
	m_sprites.push_back(s_asteroidSprites[s_asteroidSprites.size() - 1]);
}
