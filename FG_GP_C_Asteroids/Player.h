#pragma once
#include "sEntity.h"

static class Player : sEntity
{
private:
//private stuff
public:

		/////////
		bool isDead;

		void Reset();
		void ApplyLeftRotation();
		void ApplyRightRotation();
		void ApplyAcceleration();
		void Draw();
		void Explode();
		void FireWeapon();

		Player() {}; // constructor play-time ship
		Player(int extraLifes) {}; //constructor for extra lifes
		~Player() {};

		/////////
};

