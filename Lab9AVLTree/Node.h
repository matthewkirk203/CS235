#pragma once
#include "NodeInterface.h"
class Node :
	public NodeInterface
{
public:
	Node(int data);
	~Node(void);
	int getData();
	NodeInterface * getLeftChild();
	NodeInterface * getRightChild();
	int getHeight();
	int getHeightRec(Node* nodePtr);
	//void updateHeight();
	int getBalance();

	Node* leftChild;
	Node* rightChild;
	int data;
	int height;
};

