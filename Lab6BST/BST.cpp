#include "BST.h"
#include <iostream>

BST::BST(void)
{
	root = NULL;
}


BST::~BST(void)
{
	clear();
}

NodeInterface* BST::getRootNode()
{
	return root;
}

bool BST::add(int data)
{
	cout << "add(" << data << ")" << endl;
	if (root == NULL)//If the tree is empty
	{
		root = new Node(data);
		return true;
	}
	else if (contains(data))
	{
		cout << "contains(" << data << ") is true" << endl;
		return false;
	}
	else
	{
		root = addRec(root, data);
		return true;
	}

}

Node* BST::addRec(Node* subRoot, int data)
{
	if (data < subRoot->getData())//go left
	{
		if (subRoot->getLeftChild() == NULL)
		{
			subRoot->leftChild = new Node(data);
			return subRoot;
		}
		else
		{
			subRoot->leftChild = addRec(subRoot->leftChild, data);
			return subRoot;
		}
	}
	else if (data > subRoot->getData())//go right
	{
		if (subRoot->getRightChild() == NULL)
		{
			subRoot->rightChild = new Node(data);
			return subRoot;
		}
		else
		{
			subRoot->rightChild = addRec(subRoot->rightChild, data);
			return subRoot;
		}
	}
}

bool BST::remove(int data)
{
	cout << "remove(" << data << ")" << endl;
	if (!contains(data))
	{
		cout << "contains(" << data << ") is false" << endl;
		return false;
	}
	else
	{
		root = removeRec(root, data);
		return true;
	}
}

Node* BST::removeRec(Node* subRoot, int data)
{
	if (data < subRoot->data)//Go left
	{
		subRoot->leftChild = removeRec(subRoot->leftChild, data);
		return subRoot;
	}

	else if (data > subRoot->data)//Go right
	{
		subRoot->rightChild = removeRec(subRoot->rightChild, data);
		return subRoot;
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
			return subRoot;
		}

		else if(subRoot->leftChild != NULL && subRoot->leftChild->rightChild == NULL)
		{
			Node* toReturn = subRoot->leftChild;
			subRoot->leftChild->rightChild = subRoot->rightChild;
			delete subRoot;
			return toReturn;
		}

		else
		{
			Node* toReturn = subRoot->rightChild;
			delete subRoot;
			return toReturn;
		}
	}

}

void BST::clear()
{
	cout << "clear" << endl;
	while (root != NULL)
	{
		remove(root->data);
	}
}

bool BST::contains(int data)
{	
	cout << "contains(" << data << ")" << endl;
	return contains(root, data);
}

bool BST::contains(NodeInterface* subRoot, int data)
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

Node* BST::findIOP(Node* subRoot)
{
	while (subRoot->rightChild != NULL)
	{
		subRoot = subRoot->rightChild;
	}

	return subRoot;
}