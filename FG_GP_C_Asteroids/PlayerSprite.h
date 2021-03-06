#pragma once
struct SDL_Renderer;
#include "ISprite.h"
class PlayerSprite : ISprite
{
public:
	PlayerSprite();
	~PlayerSprite();
	int CreateSprite(SDL_Window* window, int pixelFormat, int textureAccess, int width, int height) override;
	void DrawPlayer(SDL_Renderer* drawPlayer);
private:
};

