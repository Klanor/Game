#include "BackGround.h"

#define X Rnd(0,1200,50)

int Star::StaticObjNum = 0;

Star::Star()
{
	StaticObjNum++;
	scale = game::Rnd(1, 3);

	sprite.setTextureRect(IntRect(145, 0, 8, 9));
	sprite.setScale(scale, scale);
	sprite.setPosition(Rnd(0,1200,50), Rnd(0,900,50));
}

void Star::Move()
{
	sprite.move(0, 0.005*game::time);
	if (sprite.getPosition().y > 900)
	{
		sprite.setPosition(Rnd(0,1200,50), -10);
	}
}

////////////////////////////////////////////////////////////

Planet::Planet()
{
	type = 0;
	PlanetType();
	sprite.setPosition(X, Rnd(200, 700));
}

void Planet::PlanetType()
{
	switch (type)
	{
	case 0:
	{
		type++;
		sprite.setTextureRect(IntRect(0, 190, 36, 36));
		sprite.setScale(3, 3);
		break;
	}
	case 1:
	{
		type++;
		sprite.setTextureRect(IntRect(37, 190, 36, 36));
		sprite.setScale(4, 4);
		break;
	}
	case 2:
	{
		type++;
		sprite.setTextureRect(IntRect(74, 190, 36, 36));
		sprite.setScale(2, 2);
		break;
	}
	case 3:
	{
		type++;
		sprite.setTextureRect(IntRect(111, 190, 36, 36));
		sprite.setScale(4, 4);
		break;
	}
	case 4:
	{
		type = 0;
		sprite.setTextureRect(IntRect(0, 230, 107, 107));
		sprite.setScale(6, 6);
		sprite.setPosition(X, -600);
		break;
	}
	default: throw 10;
	}
}

void Planet::move()
{
	sprite.move(0, 0.01 * game::time);
	if (sprite.getPosition().y > 850)
	{
		sprite.setPosition(X, -300);
		PlanetType();
	}
}