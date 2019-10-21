#ifndef METEOR_HEADER
#define METEOR_HEADER

#include "Ship.h"

class StarShip;

class Meteor:public game
{
	const float SpriteSize[3][2] =
	{
	{50, 30},
	{37, 34},
	{55, 35},
	};

protected:
	static int Type;
	int Scale;
	float Rotate, MeteorOrigin[2], dy;
	
	void MeteorSetSprite();

public:

	virtual void MeteorRotate();

	virtual void MeteorMove(bool speed = true);
};

class BigMeteor :public Meteor
{
public:
	BigMeteor();
};

class MiddleMeteor :public Meteor
{
	bool DestroedMeteor;

public:
	MiddleMeteor();

	void MeteorMove(bool speed = true);

	friend bool crash(MiddleMeteor &m, StarShip &s);

	friend void shootkill(MiddleMeteor &m, StarShip &s);
};

class SmallMeteor :public Meteor
{

public:
	SmallMeteor();
};

#endif
