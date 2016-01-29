#pragma once
#include "LinkedList.h"
class myQueue
{
public:
	myQueue(void);
	~myQueue(void);

	bool insert(int current);
	bool remove();
	int size();
	int top();
	bool isPresent(int value);
private:
	LinkedList list;
};

