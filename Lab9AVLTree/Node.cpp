#include "Node.h"


Node::Node(int d)
{
	leftChild = NULL;
	rightChild = NULL;
	data = d;
	height = 0;
}

Node::~Node(void)
{
}

int Node::getData()
{
	return data;
}

NodeInterface * Node::getLeftChild()
{
	return leftChild;
}

NodeInterface * Node::getRightChild()
{
	return rightChild;
}

int Node::getHeight()
{
	Node* nodePtr = this;
	height = getHeightRec(nodePtr);
	return height;
}

int Node::getHeightRec(Node* nodePtr)
{
	if (nodePtr == NULL)
		return -1;
	return max(getHeightRec(nodePtr->leftChild), getHeightRec(nodePtr->rightChild)) + 1;
}

int Node::getBalance()
{
	int leftHeight, rightHeight;
	if (leftChild == NULL)
		leftHeight = -1;
	else
		leftHeight = leftChild->getHeight();

	if (rightChild == NULL)
		rightHeight = -1;
	else
		rightHeight = rightChild->getHeight();

	return rightHeight - leftHeight;
}
