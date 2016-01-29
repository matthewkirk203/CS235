#pragma once
#include "AVLInterface.h"
#include "Node.h"
class AVL :
	public AVLInterface
{
public:
	AVL(void);
	~AVL(void);
	//BST Stuff
	NodeInterface * getRootNode();
	bool add(int data);
	Node* addRec(Node* subRoot, int data);
	bool remove(int data);
	Node* removeRec(Node* subRoot, int data);
	void clear();
	bool contains(int data);
	bool contains(NodeInterface* root, int data);
	Node* findIOP(Node* subRoot);

	//AVL stuff
	Node* rotateLeft(Node* subRoot);
	Node* rotateRight(Node* subRoot);
	Node* rebalance(Node* subRoot);
private:
	Node* root;
};

