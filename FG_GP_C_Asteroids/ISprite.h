#pragma once
#include "SDL_image.h"
#include "IEntity.h"
#include "EngingConfig.h"
class IEntity;
class  ISprite { 
public:
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