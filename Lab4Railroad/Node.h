#pragma once
class Node
{
public:
	Node(int data, Node* next);
	~Node(void);
	int data;
	Node* next;
};

