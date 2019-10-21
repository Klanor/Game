#include "TAplication.h"
float X, Y;

bool crash(MiddleMeteor &m, StarShip &s)
{
	X = s.sprite.getPosition().x - m.sprite.getPosition().x;
	Y = s.sprite.getPosition().y - m.sprite.getPosition().y;

	if ((m.sprite.getPosition().y > 200)&(!m.DestroedMeteor))
	{
		if ((Y > ((-m.MeteorOrigin[1] * m.Scale)-20))&(Y < ((m.MeteorOrigin[1] * m.Scale)+20)))
		{
			if ((X > ((-m.MeteorOrigin[0] * m.Scale)-20))&(X < ((m.MeteorOrigin[0] * m.Scale)+20)))
			{
				s.sound.SoundExplBig();
				m.sprite.setPosition(-100,1000);
				return true;
			}
		}
	}
return false;
}

void shootkill(MiddleMeteor &m, StarShip &s)
{
	X = s.ShipShot.getPosition().x - m.sprite.getPosition().x;
	Y = s.ShipShot.getPosition().y - m.sprite.getPosition().y;
	if (s.shot)
	{
		if ((Y > -m.MeteorOrigin[1] * m.Scale)&(Y < m.MeteorOrigin[1] * m.Scale))
		{
			if ((X > -m.MeteorOrigin[0] * m.Scale)&(X < m.MeteorOrigin[0] * m.Scale))
			{
				if (!m.DestroedMeteor)
				{
					s.sound.SoundExpLSml();
					s.shot = false;
					m.DestroedMeteor = true;
					m.sprite.setTextureRect(IntRect(149, 70, 51, 32));
					s.Score++;
				}
			}
		}
	}
}
