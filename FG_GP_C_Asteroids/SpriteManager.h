#pragma once
#include <vector>
#include "ISprite.h"
class AsteroidSprite;
class PlayerSprite;
class SpriteManager
{
public:
	SpriteManager();
	~SpriteManager();
	int CreateSprite(SDL_Window* window, SDL_Texture* texture, int pixelFormat, int textureAccess, int width, int height);
	std::vector<ISprite*> GetSprites();
	ISprite* GetISprite();
private:
	void SetPlayerSprite();
	void SetAsteroidSprite();
	ISprite* sprite = nullptr;
	PlayerSprite* playerSprite = nullptr;
	std::vector<AsteroidSprite*>s_asteroidSprites;
	std::vector<ISprite*> m_sprites;
};

