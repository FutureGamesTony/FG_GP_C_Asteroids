#pragma once
static class Player
{
private:
//private stuff
public:

		/////////

		float xPos;
		float yPos;
		float velocityX;
		float velocityY;
		float angle;
		float roatationSpeed;
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

