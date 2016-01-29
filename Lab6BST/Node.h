#pragma once
#include "NodeInterface.h"
class Node :
	public NodeInterface
{
public:
	Node(int data);
	~Node(void);
	int getData();
	NodeInterface* getLeftChild();
	NodeInterface* getRightChild();

	Node* leftChild;
	Node* rightChild;
	int data;
};

