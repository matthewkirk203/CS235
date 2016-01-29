#pragma once
#include "LinkedListInterface.h"
#include "Node.h"

using namespace std;

class LinkedList :
	public LinkedListInterface
{
public:
	LinkedList(void);
	~LinkedList(void);

	void insertHead(int value);
	void insertTail(int value);
	void insertAfter(int value, int insertionNode);
	void remove(int value);
	void clear();
	int at(int index);
	int size();
	bool present(int value);
private:
	Node* head;
	int count; //Keeps track of how many items are in the list.
};

