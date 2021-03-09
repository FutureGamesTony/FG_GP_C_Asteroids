#pragma once
#include "ISprite.h"
#include "SDL.h"

struct SDL_Renderer;
struct SDL_Texture;
struct SDL_Surface;
class PlayerSprite : public ISprite //public so it can be cast to a vector in a sprite handeler;
{
public:
	PlayerSprite();
	~PlayerSprite();

	SDL_Rect sourceRect{ 1,1,16,16 };
	SDL_Rect destinationRect{ 1,1,16,16 };

	int CreateSprite(SDL_Window* window, SDL_Texture* texture, int pixelFormat, int textureAccess, int width, int height) override;
	SDL_Texture* DrawPlayer(SDL_Renderer* drawPlayer);
	void RenderPlayer(SDL_Renderer* renderer, SDL_Texture* sprite);
	void ModifyRects() override;
	SDL_Rect* GetSourceRect();
	SDL_Rect* GetDestRect();
private:

};

