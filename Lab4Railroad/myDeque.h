#pragma once
#include "LinkedList.h"
class myDeque
{
public:
	myDeque(void);
	~myDeque(void);

	bool addLeft(int current);
	bool addRight(int current);
	bool removeLeft();
	bool removeRight();
	int getLeft();
	int getRight();
	int size();
	bool isPresent(int value);
private:
	LinkedList list;
};

