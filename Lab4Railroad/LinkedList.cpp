#include "LinkedList.h"
#include <iostream>

using namespace std;


LinkedList::LinkedList(void)
{
	head = NULL;
	count = 0;
}


LinkedList::~LinkedList(void)
{
	clear();
	head = NULL;
}

void LinkedList::insertHead(int value)
{
	if (!present(value))
	{
		head = new Node(value, head);
		count++;
	}
}

void LinkedList::insertTail(int value)
{
	Node* nodePtr = head;
	if (!present(value))
	{
		//Iterate until nodePtr points to last node
		/*for (size_t i = 1; i < count; i++) 
		{
			nodePtr = nodePtr->next;
		}*/
		
		if (head == NULL)
		{
			head = new Node(value, NULL);
			count++;
			return;
		}
		while(nodePtr != NULL){
			if(nodePtr->next == NULL){
				nodePtr->next = new Node(value, NULL);
				count++;
				return;
			}
			nodePtr = nodePtr->next;
		}

	}
}

void LinkedList::insertAfter(int value, int insertionNode)
{
	Node* nodePtr = head;
	if (insertionNode < 0) {return;}
	if (!present(value))
	{
		if (present(insertionNode))
		{
			while (insertionNode != nodePtr->data)
			{
				/* Iterate until nodePtr points to the Node after which
					we want to insert. Then insert Node */
				nodePtr = nodePtr->next;
			}

		nodePtr->next = new Node(value, nodePtr->next);
		count++;

		}
	}
}

void LinkedList::remove(int value)
{
	Node* nodePtr = head;
	Node* temp = NULL;
	if (value < 0){
		cout << "Passed in negative value" << endl;
		return;}
	if (present(value))
	{
		if (value == nodePtr->data)
		{
			temp = nodePtr;
			head = nodePtr->next;
			delete temp;
			count--;
			return;
		}
		while (value != nodePtr->next->data)
		{
			nodePtr = nodePtr->next;
		}
		temp = nodePtr->next;
		nodePtr->next = nodePtr->next->next;
		delete temp;
		count--;
	}
}

void LinkedList::clear()
{
	Node* nodePtr = head;
	Node* current = head;
	while (nodePtr != NULL)
	{
		nodePtr = nodePtr->next;
		delete current;
		current = nodePtr;
		count--;
	}
	cout << "clear done" << endl;
	head = NULL;
}

int LinkedList::at(int index)
{
	Node* nodePtr = head;
	if (index >= count || index < 0)
	{
		return -1;
	}
	for (size_t i = 0; i < index; i++)
	{
		nodePtr = nodePtr->next;
	}
	return nodePtr->data;

}

int LinkedList::size()
{
	return count;
}

bool LinkedList::present(int value)
{
	Node* nodePtr = head;
	//This will check to see if the value is negative.
	if (value < 0)
	{
		return true;
	}
	//Check to see if the value already exists in the list.
	while (nodePtr != NULL)
	{
		if (value == nodePtr->data)
		{
			return true;
		}

		nodePtr = nodePtr->next;
	}
	return false;
}
