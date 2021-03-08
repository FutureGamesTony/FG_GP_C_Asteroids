#pragma once
struct SDL_Renderer;
struct SDL_Texture;
#include "ISprite.h"
class PlayerSprite : public ISprite //public so it can be cast to a vector in a sprite handeler;
{
public:
	PlayerSprite();
	~PlayerSprite();
	int CreateSprite(SDL_Window* window, SDL_Texture* texture, int pixelFormat, int textureAccess, int width, int height) override;
	void DrawPlayer(SDL_Renderer* drawPlayer);
private:

};

