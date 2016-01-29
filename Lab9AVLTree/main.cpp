#include "AVL.h"
#include <stdlib.h>
#include <time.h>


int main()
{
	srand(time(NULL));
	AVL thingy;
	/*for (int i = 0; i < 100; i++)
	{
		thingy.add(rand() % 100);
	}*/
	thingy.add(9);
	thingy.add(5);
	thingy.add(6);
	thingy.add(4);
	thingy.add(1);
	thingy.add(2);
	thingy.add(3);
	thingy.add(7);

	thingy.remove(6);
}