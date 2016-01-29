#include "BST.h"
#include <iostream>

using namespace std;

int main()
{
	BST thingy;
	thingy.add(5);
	thingy.add(5);
	thingy.remove(0);
	thingy.add(1);
	thingy.add(3);
	thingy.add(2);
	thingy.add(8);
	thingy.add(7);
	thingy.add(6);
	thingy.add(10);
	thingy.remove(5);
	thingy.remove(5);

	thingy.clear();

	thingy.add(8);
	thingy.add(4);
	thingy.add(2);
	thingy.add(1);
	thingy.add(8);
	thingy.add(4);
}