#pragma once
#include "BSTInterface.h"
#include "Node.h"
class BST :
	public BSTInterface
{
public:
	BST(void);
	~BST(void);
	NodeInterface* getRootNode();
	bool add(int data);
	Node* addRec(Node* subRoot, int data);
	bool remove(int data);
	Node* removeRec(Node* subRoot, int data);
	void clear();
	bool contains(int data);
	bool contains(NodeInterface* root, int data);
	Node* findIOP(Node* subRoot);
private:
	Node* root;
};

