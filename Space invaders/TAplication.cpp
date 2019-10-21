#include "TAplication.h"

GameSet::GameSet(int wid, int hei)
{
	width = wid;
	height = hei;
	DoMain = 0;
	icon.loadFromFile("graphics/icon.png");
	if (window == nullptr)
	{
		window = new sf::RenderWindow(sf::VideoMode(width, height), "Spacer",Style::Close);	
		window->setVerticalSyncEnabled(true);
		window->setIcon(64, 64, icon.getPixelsPtr());
	}
}

void GameSet::GameEvent()
{
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
		{
			window->close();
			break;
		}
		case Event::KeyPressed:
		{
			if (event.key.code == Keyboard::Escape)
			{
				window->close();
				break;
			}
			else if ((event.key.code == Keyboard::Tab) & (DoMain == 0))
			{
				DoMain = 1;
				new_create();
			}
			else if ((event.key.code == Keyboard::Tab) & (DoMain != 0))
			{
				DoMain = 0;
			}
		}
		}
	}
}

void GameSet::Run()
{
	ship = new StarShip;
	Bmeteor = new BigMeteor[2];
	Mmeteor = new MiddleMeteor[8];
	Smeteor = new SmallMeteor[15];
	ship->sound.PlayMusic();

	while (window->isOpen())
	{
		game::timeset(600);

		GameEvent();

		window->clear(Color::Color(9, 2, 23, 0));

		for (iter = 0; iter < Star[0].getNum(); ++iter)
		{
			window->draw(Star[iter].getSprite());
		}

		window->draw(Planet.getSprite());

		switch (DoMain)
		{
		case 0: menu(); break;
		case 1: Game(); break;
		case 2: explosion_crash(); break;
		}
		window->display();
	}
}

void GameSet::Game()
{
	ship->animationShip();
	ship->ShipMove(window->getSize().x);
	ship->BulletAnim();

	for (iter = 0; iter < Star[0].getNum(); ++iter)
	{
		Star[iter].Move();
	}
	Planet.move();

	for (iter = 0; iter < 15; ++iter)
	{
		Smeteor[iter].MeteorMove();
		Smeteor[iter].MeteorRotate();
		window->draw(Smeteor[iter].getSprite());
	}

	for (iter = 0; iter < 8; iter++)
	{
		Mmeteor[iter].MeteorMove();
		shootkill(Mmeteor[iter], *ship);

		if (crash(Mmeteor[iter], *ship))
		{
			DoMain = 2;
		}
		Mmeteor[iter].MeteorRotate();
		window->draw(Mmeteor[iter].getSprite());
	}

	window->draw(ship->getBulet());
	window->draw(ship->getSprite());

	for (iter = 0; iter < 2; ++iter)
	{
		Bmeteor[iter].MeteorMove();
		Bmeteor[iter].MeteorRotate();
		window->draw(Bmeteor[iter].getSprite());
	}

	window->draw(ship->DrawText("SCORE: " + ship->gamescore(), 110, 50, 50));

}

void GameSet::menu()
{
	for (iter = 0; iter < 15; ++iter)
	{
		Smeteor[iter].MeteorRotate();
		Smeteor[iter].MeteorMove();
		window->draw(Smeteor[iter].getSprite());
	}

	for (iter = 0; iter < 8; iter++)
	{
		Mmeteor[iter].MeteorRotate();
		Mmeteor[iter].MeteorMove();
		window->draw(Mmeteor[iter].getSprite());
	}

	for (iter = 0; iter < 2; ++iter)
	{
		Bmeteor[iter].MeteorMove();
		Bmeteor[iter].MeteorRotate();
		window->draw(Bmeteor[iter].getSprite());
	}

	window->draw(ship->DrawText("PRESS TAB TO START", window->getView().getCenter(), 60));
	window->draw(ship->DrawText("USE LEFT, RIGHT TO MOVE", window->getView().getCenter().x, window->getView().getCenter().y+60, 60));
	window->draw(ship->DrawText("UP TO SHOOT", window->getView().getCenter().x, window->getView().getCenter().y+120, 60));
}

void GameSet::explosion_crash()
{
	for (iter = 0; iter < 15; ++iter)
	{
		Smeteor[iter].MeteorMove(false);
		Smeteor[iter].MeteorRotate();
		window->draw(Smeteor[iter].getSprite());
	}

	for (iter = 0; iter < 8; iter++)
	{
		Mmeteor[iter].MeteorRotate();
		Mmeteor[iter].MeteorMove(false);
		window->draw(Mmeteor[iter].getSprite());
	}

	window->draw(ship->getSprite());

	for (iter = 0; iter < 2; ++iter)
	{
		Bmeteor[iter].MeteorMove(false);
		Bmeteor[iter].MeteorRotate();
		window->draw(Bmeteor[iter].getSprite());
	}

	if (ship->Explosion())
	{
		window->draw(ship->DrawText("PRESS TAB TO RESTART", window->getView().getCenter().x, window->getView().getCenter().y+60, 60));
		window->draw(ship->DrawText("SCORE: " + ship->gamescore(), window->getView().getCenter().x, window->getView().getCenter().y + 120, 50));
	}	
}

void GameSet::new_create()
{
	delete ship;
	delete[] Bmeteor;
	delete[] Mmeteor;
	delete[] Smeteor;
	ship = new StarShip;
	Bmeteor = new BigMeteor[2];
	Mmeteor = new MiddleMeteor[8];
	Smeteor = new SmallMeteor[15];
}

void GameSet::end()
{
	if (window != nullptr)
	{
		delete window;
		window = nullptr;
	}
}

