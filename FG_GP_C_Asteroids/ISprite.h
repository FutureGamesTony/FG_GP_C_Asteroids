#pragma once
#include "SDL_image.h"
#include "IEntity.h"
#include "EngingConfig.h"
class IEntity;
class  ISprite { 
public: // By creating an abstract class, we can ensure all functions that inherits this class has everything needed, or it will give compilation error
		// so if more or less things are needed, this is the first place to adjust. 
	virtual int CreateSprite() = 0;
	virtual void ModifyRects(int rotation, int x, int y) = 0;
	virtual SDL_Texture* DrawSprite(SDL_Renderer* drawSprite) = 0;
	virtual void RenderSprite(SDL_Renderer* renderer, SDL_Texture* sprite) = 0;
	virtual Position SetSpritePosition(Position destinationRect) = 0;
	virtual const char* GetFilepath() = 0;
	virtual SDL_Texture* GetSprite() = 0;
	virtual SDL_Rect GetSourceRect() = 0;
	virtual EngineConfig::EntityType GetEntityType() = 0;
};