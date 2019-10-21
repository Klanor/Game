#include "Ship.h"

GameSound StarShip::sound;

void StarShip::border(unsigned int& x)
{
	if (sprite.getPosition().x < 22)
	{
		sprite.setPosition(22, sprite.getPosition().y);
	}
	else if (sprite.getPosition().x > x-22)
	{
		sprite.setPosition(x-22, sprite.getPosition().y);
	}
}

StarShip::StarShip()
{
	Score = dx = 0;
	shot = true;
		
		sprite.setTextureRect(IntRect(0, 0, 45, 62));
		sprite.setScale(2.5, 2.5);
		sprite.setPosition(700, 1100);

		ShipShot = sprite;
		ShipShot.setTextureRect(IntRect(138, 0, 3, 4));
		ShipShot.setScale(5, 5);
		ShipShot.setPosition(-20, -20);

		sprite.setOrigin(22.5, 30);
		ShipShot.setOrigin(1.5, 2);
}

String StarShip::gamescore()
{
	TextScore = std::to_string(Score);
	return TextScore;
}

void StarShip::animationShip()
{
	GameTime = GameTime + game::time;
	//std::cout << anim << std::endl;
	if (GameTime < 100)
	{
		sprite.setTextureRect(IntRect(0, 0, 45, 62));
	}
	else if ((GameTime > 100)&(GameTime < 200))
	{
		sprite.setTextureRect(IntRect(46, 0, 45, 62));
	}
	else if ((GameTime > 200)&(GameTime < 300))
	{
		sprite.setTextureRect(IntRect(92, 0, 45, 62));
	}
	else if (GameTime > 300)GameTime = 0;
	//std::cout << Score << std::endl;
}

bool StarShip::Explosion()
{
	GameTime = GameTime + game::time;
	sprite.setScale(5, 5);
	if (GameTime < 400)
	{
		sprite.setTextureRect(IntRect(0, 110, 62, 55));//big
		sprite.move(0, -0.3*game::time);
		return false;
	}
	else if ((GameTime > 400)&(GameTime < 800))
	{
		sprite.setTextureRect(IntRect(65, 110, 68, 57));//mid
		sprite.move(0, -0.2*game::time);
		return false;
	}
	else if ((GameTime > 800)&(GameTime < 1200))
	{
		sprite.setTextureRect(IntRect(141, 110, 54, 48));//sml
		sprite.move(0, -0.1*game::time);
		return false;
	}
	else if (GameTime > 1200)
	{
		sprite.setPosition(-100, -100);
		return true;
	}
}

void StarShip::ShipMove(unsigned int x)
{
	if (sprite.getPosition().y > 700)
	{
		sprite.move(0, -0.2*game::time);
	}
	else if (dx > 0)
	{
		dx = dx - 0.007;
		if (dx < 0)dx = 0;
	}

	border(x);

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			GoRight = false;
			dx = 0.4;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			GoRight = true;
			dx = 0.4;
		}
		
		switch (GoRight)
		{
		case false:sprite.move(-dx*game::time, 0); break;
		case true:sprite.move(dx*game::time, 0); break;
		default:
			break;
		}
	  //  std::cout << dx << std::endl;
}

void StarShip::BulletAnim()
{
	if (Keyboard::isKeyPressed(Keyboard::Up) & MakeShot)
	{
		sound.SoundShoot();
		MakeShot = false;
		shot = true;
		ShipShot.setPosition(sprite.getPosition().x, sprite.getPosition().y);
	}
	ShipShot.move(0, -0.6*time);
	if (ShipShot.getPosition().y < 0)
	{
		MakeShot = true;
		shot = false;
		ShipShot.setPosition(-10, -10);
		//std::cout << ShipShot->getPosition().y << std::endl;
	}
}

