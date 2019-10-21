
#ifndef GAME_SOUND
#define GAME_SOUND

#include "Game.h"

class GameSound
{
	SoundBuffer Shoot, BigExpl, SmallExpl;
	Sound Sound;
	Music Music;

public:
	GameSound();

	void SoundShoot();

	void SoundExplBig();

	void SoundExpLSml();

	void PlayMusic();

};

#endif // !GAME_SOUND

