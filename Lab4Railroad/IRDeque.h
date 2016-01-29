#pragma once
#include "LinkedList.h"

class IRDeque
{
public:
	IRDeque(void);
	~IRDeque(void);
	bool addLeft(int current);
	bool removeLeft();
	bool removeRight();
	int getLeft();
	int getRight();
	int size();
	bool isPresent(int value);
private:
	LinkedList list;
};

