#include "Node.h"


Node::Node(int d)
{
	leftChild = NULL;
	rightChild = NULL;
	data = d;
}

Node::~Node(void)
{
}

int Node::getData()
{
	return data;
}

NodeInterface* Node::getLeftChild()
{
	return leftChild;
}

NodeInterface* Node::getRightChild()
{
	return rightChild;
}
