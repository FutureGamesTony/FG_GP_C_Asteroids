#pragma once
struct Size // Just wanted an easier way to set size
{
	int width;
	int height;
};
struct Position // Just wanted an easier way to set position
{
	int x;
	int y;
};

struct Movement // Just wanted an easier way to set movement
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
	enum class EntityType//to easy identify what entity for an entity handler, without having to compare objects. 
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


