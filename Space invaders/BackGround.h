#ifndef BACKGROUND_HEADER
#define BACKGROUND_HEADER

#include "GameSound.h"

class Star:public game
{
	static int StaticObjNum;
	unsigned int scale;

public:
	Star();

	void Move();

	int getNum() { return StaticObjNum; }
};

class Planet :public game
{
	unsigned int scale, type;

	void PlanetType();
public:
	Planet();

	void move();
};

#endif
