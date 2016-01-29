#include "Mimic.h"

using namespace std;

int main()
{
	Mimic thingy;
	thingy.createMap("See Spot Run!");
	while (true)
	{
		cout << thingy.generateText();
		system("pause");
	}
}