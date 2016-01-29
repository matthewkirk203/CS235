#pragma once
#include "LinkedList.h"

class ORDeque
{
public:
	ORDeque(void);
	~ORDeque(void);
	bool addLeft(int current);
	bool addRight(int current);
	bool removeLeft();
	int getLeft();
	int getRight();
	int size();
	bool isPresent(int value);
private:
	LinkedList list;
};

