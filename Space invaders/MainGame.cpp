#ifndef MAINGAME_FUNC
#define MAINGAME_FUNC

#include "TAplication.h"



GameSet Game(1200,900);

int main()
{
	try
	{
		Game.Run();
	}
	catch (int i)
	{
		return i;
	}
	Game.end();
}




#endif // !MAINGAME_FUNC
