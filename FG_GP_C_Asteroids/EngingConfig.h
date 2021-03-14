#pragma once
struct Size
{
	int width;
	int height;
};
struct Position 
{
	int x;
	int y;
};

struct Movement 
{
	double x;
	double y;
};
struct Circle
{
	int x, y;
	int r;
};

class EngineConfig 
{
public:
	static const int WIDTH = 1280;
	static const int HEIGHT = 720;
	enum class EntityType 
	{
		Player_Entity,
		Bullet_Entity,
		Asteroid_Entity,

	};
	enum class PlayerInput
	{
		NoKeyPressed,
		PlayerForward,
		PlayerRotateLeft,
		PlayerRotateRight,
		PlayerBreak,
		PlayerFireWeapon,
		PlayerQuit,
	};
};


