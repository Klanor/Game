#include "GameSound.h"

GameSound::GameSound()
{
	Shoot.loadFromFile("sound/shot.ogg");
	BigExpl.loadFromFile("sound/explosion.ogg");
	SmallExpl.loadFromFile("sound/small_explosion.ogg");
	Music.openFromFile("sound/main.ogg");
}

void GameSound::SoundShoot()
{
	Sound.setBuffer(Shoot);
	Sound.play();
}

void GameSound::SoundExplBig()
{
	Sound.setBuffer(BigExpl);
	Sound.play();
}

void GameSound::SoundExpLSml()
{
	Sound.setBuffer(SmallExpl);
	Sound.play();
}

void GameSound::PlayMusic()
{
	Music.play();
	Music.setLoop(true);
}