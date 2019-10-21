#ifndef TAPLICATION_HEADER
#define TAPLICATION_HEADER

#include "Meteor.h"

class GameSet
{
	Image icon;
	unsigned int DoMain, iter;
	int width, height;
	Event event;

	StarShip *ship;
	BigMeteor *Bmeteor;
	MiddleMeteor *Mmeteor;
	SmallMeteor *Smeteor;

	Star Star[50];
	Planet Planet;

	RenderWindow * window;

	void GameEvent();

	void explosion_crash();

	void new_create();

	void Game();

public:

	GameSet(int wid, int hei);

	void menu();
	
	void Run();

	void end();
};




#endif
