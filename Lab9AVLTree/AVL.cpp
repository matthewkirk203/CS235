#include "AVL.h"
#include <iostream>

AVL::AVL(void)
{
	root = NULL;
}


AVL::~AVL(void)
{
	clear();
}

NodeInterface * AVL::getRootNode()
{
	return root;
}

bool AVL::add(int data)
{
	//cout << "add(" << data << ")" << endl;
	if (root == NULL)//If the tree is empty
	{
		root = new Node(data);
		return true;
	}
	else if (contains(data))
	{
		//cout << "contains(" << data << ") is true" << endl;
		return false;
	}
	else
	{
		root = addRec(root, data);
		return true;
	}
}

Node* AVL::addRec(Node* subRoot, int data)
{
	if (data < subRoot->getData())//go left
	{
		if (subRoot->getLeftChild() == NULL)
		{
			subRoot->leftChild = new Node(data);
			if (subRoot->rightChild == NULL)//If it is Null, we are making a new level
			{
				subRoot->height++;
			}
			return rebalance(subRoot);
		}
		else
		{
			subRoot->leftChild = addRec(subRoot->leftChild, data);
			return rebalance(subRoot);
		}
	}
	else if (data > subRoot->getData())//go right
	{
		if (subRoot->getRightChild() == NULL)
		{
			subRoot->rightChild = new Node(data);
			if (subRoot->leftChild == NULL)//If it is Null, we are making a new level
			{
				subRoot->height++;
			}
			return rebalance(subRoot);
		}
		else
		{
			subRoot->rightChild = addRec(subRoot->rightChild, data);
			return rebalance(subRoot);
		}
	}
}

bool AVL::remove(int data)
{
	//cout << "remove(" << data << ")" << endl;
	if (!contains(data))
	{
		//cout << "contains(" << data << ") is false" << endl;
		return false;
	}
	else
	{
		root = removeRec(root, data);
		return true;
	}
}

Node* AVL::removeRec(Node* subRoot, int data)
{
	if (data < subRoot->data)//Go left
	{
		subRoot->leftChild = removeRec(subRoot->leftChild, data);
		return rebalance(subRoot);
	}

	else if (data > subRoot->data)//Go right
	{
		subRoot->rightChild = removeRec(subRoot->rightChild, data);
		return rebalance(subRoot);
	}

	else if (data == subRoot->data)//Is found
	{
		if (subRoot->leftChild == NULL && subRoot->rightChild == NULL)//Leaf node
		{
			delete subRoot;
			return NULL;
		}

		else if (subRoot->leftChild != NULL && subRoot->leftChild->rightChild != NULL)
		{
			Node* IOP = findIOP(subRoot->leftChild);//findIOP just iterates all the way to the right of the left subtree when called like this.
			/*IOP->leftChild = subRoot->leftChild;
			IOP->rightChild = subRoot->rightChild;*/
			subRoot->data = IOP->data;//swap data
			subRoot->leftChild = removeRec(subRoot->leftChild, subRoot->data);
			return rebalance(subRoot);
		}

		else if(subRoot->leftChild != NULL && subRoot->leftChild->rightChild == NULL)
		{
			Node* toReturn = subRoot->leftChild;
			subRoot->leftChild->rightChild = subRoot->rightChild;
			delete subRoot;
			return rebalance(toReturn);
		}

		else
		{
			Node* toReturn = subRoot->rightChild;
			delete subRoot;
			return rebalance(toReturn);
		}
	}
}

void AVL::clear()
{
	//cout << "clear" << endl;
	while (root != NULL)
	{
		remove(root->data);
	}
}

bool AVL::contains(int data)
{
	//cout << "contains(" << data << ")" << endl;
	return contains(root, data);
}

bool AVL::contains(NodeInterface* subRoot, int data)
{
	if (subRoot == NULL)
		return false;
	else if (subRoot->getData() == data)
		return true;
	else if (subRoot->getLeftChild() == NULL && subRoot->getRightChild() == NULL)
		return false;
	else if (subRoot->getData() > data)
		return contains(subRoot->getLeftChild(), data);
	else if (subRoot->getData() < data)
		return contains(subRoot->getRightChild(), data);
}

Node* AVL::findIOP(Node* subRoot)
{
	while (subRoot->rightChild != NULL)
	{
		subRoot = subRoot->rightChild;
	}

	return subRoot;
}

//AVL Stuff

Node* AVL::rotateLeft(Node* subRoot)
{
	Node* temp = subRoot->rightChild;
	subRoot->rightChild = temp->leftChild;
	temp->leftChild = subRoot;
	subRoot = temp;
	return subRoot;
}

Node* AVL::rotateRight(Node* subRoot)
{
	Node* temp = subRoot->leftChild;
	subRoot->leftChild = temp->rightChild;
	temp->rightChild = subRoot;
	subRoot = temp;
	return subRoot;
}

Node* AVL::rebalance(Node* subRoot)
{
	int currentBalance = subRoot->getBalance();
	if (currentBalance < -1) //left heavy
	{
		if (subRoot->leftChild->getBalance() > 0)//left-right tree
		{
			subRoot->leftChild = rotateLeft(subRoot->leftChild);
		}
		subRoot = rotateRight(subRoot);
	}
	else if(currentBalance > 1) //right heavy
	{
		if (subRoot->rightChild->getBalance() < 0)//right-left tree
		{
			subRoot->rightChild = rotateRight(subRoot->rightChild);
		}
		subRoot = rotateLeft(subRoot);
	}
	return subRoot;
}