#ifndef SHIP_HEADER
#define SHIP_HEADER

#include "BackGround.h"

class MiddleMeteor;

class StarShip :public game
{
	Sprite ShipShot;
	int Score;
	String TextScore;
	bool shot, GoRight, MakeShot;
	float dx;

	void border(unsigned int& x);

public:
	static GameSound sound;

	StarShip();

	Sprite getBulet()
	{
		return ShipShot;
	}

	String gamescore();

	void animationShip();

	bool Explosion();

	void ShipMove(unsigned int win);

	void BulletAnim();

	friend bool crash(MiddleMeteor &m, StarShip &s);

	friend void shootkill(MiddleMeteor &m, StarShip &s);
};


#endif // !SHIP_HEADER

