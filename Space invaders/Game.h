#ifndef GAME_HEADER
#define GAME_HEADER

#include "Header.h"

using namespace sf;

class game
{
	static int PastRandom, NewRandom;
	static Clock clock;
	Font font;
	Image Img;
	Texture texture;
	Text txt;

protected:
	Sprite sprite;
	static float time;
	float GameTime;

	static int Rnd(int start, int end, unsigned int width=0);
	
public:
	game();

	static void timeset(float speed);

	Text DrawText(String text, Vector2f pos, unsigned int size = 20);

	Text DrawText(String text, int posx, int posy, unsigned int size = 20);

	Sprite getSprite() { return sprite; }
};

#endif
