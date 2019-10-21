#include "Meteor.h"
#define X Rnd(0, 1200, 300)
#define Y -Rnd(100, 1000, 300)

int Meteor::Type = 0;

void Meteor::MeteorSetSprite()
{
	switch (Type)
	{
	case 0:
	{
		Type++;
		sprite.setTextureRect(IntRect(0, 70, SpriteSize[0][0], SpriteSize[0][1]));
		MeteorOrigin[0] = SpriteSize[0][0] / 2;
		MeteorOrigin[1] = SpriteSize[0][1] / 2;
		break;
	}
	case 1:
	{
		Type++;
		sprite.setTextureRect(IntRect(50, 70, SpriteSize[1][0], SpriteSize[1][1]));
		MeteorOrigin[0] = SpriteSize[1][0] / 2;
		MeteorOrigin[1] = SpriteSize[1][1] / 2;
		break;
	}
	case 2:
	{
		Type = 0;
		sprite.setTextureRect(IntRect(93, 70, SpriteSize[2][0], SpriteSize[2][1]));
		MeteorOrigin[0] = SpriteSize[2][0] / 2;
		MeteorOrigin[1] = SpriteSize[2][1] / 2;
		break;
	}
	default: throw 1;
	}
}

void Meteor::MeteorRotate()
{
	Rotate = Rotate + time / 100;
	if (Rotate > 360)Rotate = 0;
	//std::cout << Rotate << std::endl;
	sprite.setRotation(Rotate);
}

void Meteor::MeteorMove(bool speed)
{
	switch (speed)
	{
	case true:dy = dy + 0.00006; break;
	case false:
	{
		if (dy > 0.005)
		{
			dy = dy - 0.001;
			if (dy < 0.005)dy = 0.005;
		}
		break;
	}
	default: throw 1;
	}
	//std::cout << dy << std::endl;
	sprite.move(0, dy*game::time);

	if (sprite.getPosition().y > 1150)
	{
		sprite.setScale(Scale, Scale);
		sprite.setPosition(X, Y);
		//std::cout << MeteorCreate('x') << "  V  "<<MeteorCreate('y') << std::endl;
	}
}

//////////////BIG_METEOR/////////////////////////////

BigMeteor::BigMeteor()
{
	Scale = Rnd(5, 7);
	Rotate = Rnd(1, 360);

	dy = 0.5;

	Rotate = Rnd(0, 360);

	sprite.setTextureRect(IntRect(207, 73, 52, 30));
	sprite.setScale(Scale, Scale);
	sprite.setPosition(X, Y);
	sprite.setOrigin(26,15);
}


/////////////MIDLE_METEOR///////////////////////////

MiddleMeteor::MiddleMeteor()
{
	DestroedMeteor = false;
	Scale = Rnd(2, 4);
	Rotate = Rnd(1, 360);

	dy = 0.3;

	Rotate = Rnd(0, 360);

	MeteorSetSprite();
	sprite.setScale(Scale, Scale);
	sprite.setPosition(X, Y);
	sprite.setOrigin(MeteorOrigin[0], MeteorOrigin[1]);
}

void MiddleMeteor::MeteorMove(bool speed)
{	
    switch (speed)
	{
	case true:dy = dy + 0.00006; break;
	case false:
	{
		if (dy > 0.005)
		{
			dy = dy - 0.001;
			if (dy < 0.005)dy = 0.005;
		}
		break;
	}
	default: throw 1;
	}

	sprite.move(0, dy*game::time);

	//std::cout << dy << std::endl;
	if (sprite.getPosition().y > 1000)
	{
		if (DestroedMeteor)
		{
			DestroedMeteor = false;
			MeteorSetSprite();
		}
		sprite.setScale(Scale, Scale);
		sprite.setPosition(X, Y);
		//std::cout << MeteorCreate('x') << "  V  "<<MeteorCreate('y') << std::endl;
	}
}

/////////////SMALL_METEOR/////////////////////////////

SmallMeteor::SmallMeteor()
{
	dy = 0.2;
	Scale = Rnd(1, 2);
	Rotate = Rnd(1, 360);

	MeteorSetSprite();
	sprite.setColor(Color::Color(105, 105, 105, 255));
	sprite.setScale(Scale, Scale);
	sprite.setPosition(X, Y);
	sprite.setOrigin(MeteorOrigin[0], MeteorOrigin[1]);
}