#pragma once
#include "LinkedList.h"
class myStack
{
public:
	myStack(void);
	~myStack(void);

	bool push(int current);
	bool pop();
	int top();
	int size();
	bool isPresent(int value);

private:
	LinkedList list;
};

