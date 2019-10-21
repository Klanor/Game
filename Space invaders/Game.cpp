#include "Game.h"
float game::time = 0;
Clock game::clock;
int game::NewRandom = 0;
int game::PastRandom = 0;

game::game()
{

	GameTime = 0;
	Img.loadFromFile("graphics/game.png");
	texture.loadFromImage(Img);
	sprite.setTexture(texture);
	font.loadFromFile("font/future.ttf");
	txt.setFont(font);
}

void game::timeset(float speed)
{
	time = clock.getElapsedTime().asMicroseconds();
	time = time / speed;
	//std::cout << time << std::endl;
	clock.restart();
}

sf::Text game::DrawText(String text, const Vector2f pos, unsigned int size)
{
	txt.setCharacterSize(size);
	txt.setFillColor(Color::Red);
	txt.setString(text);
	txt.setOrigin(txt.getLocalBounds().width / 2, size/2);
	txt.setPosition(pos);
	return txt;
}

sf::Text game::DrawText(String text, int posx, int posy, unsigned int size)
{
	txt.setCharacterSize(size);
	txt.setFillColor(Color::Red);
	txt.setString(text);
	txt.setOrigin(txt.getLocalBounds().width / 2, size / 2);
	txt.setPosition(posx, posy);
	return txt;
}

int game::Rnd(int start, int end, unsigned int width)
{
	if (width != 0)
	{
		NewRandom = start + rand() % (end - start);

		do
		{
			NewRandom = start + rand() % (end - start);
		} while (abs(PastRandom - NewRandom) < width);
		
		PastRandom = NewRandom;

		return NewRandom;
	}
	return start + rand() % (end - start);
}
