/*
	Matthew Kirk
	Section : 4
	CS 235 Fall 2013 Midterm
*/

#pragma once
#include "DoubleLinkedListInterface.h"
#include "Node.h"
#include <string>
#include <stdlib.h>
#include <time.h>
//#include <iostream>

using namespace std;


template <class T> class DoubleLinkedList : public DoubleLinkedListInterface<T>
{
public:
	DoubleLinkedList(void)
	{
		head = NULL;
		numItems = 0;
		srand (time(NULL)); //Seeding rand()
	}

	~DoubleLinkedList(void)
	{
		if (numItems == 0)
			return;
		Node<T>* nodePtr = head;
		Node<T>* current = head;
		while (nodePtr != NULL)
		{
			nodePtr = nodePtr->next;
			delete current;
			current = nodePtr;
			numItems--;
		}
		//cout << "clear done" << endl;
		head = NULL;
	}

	void addFront(T data);
	void addRear(T data);
	bool addAt(T data, int index);
	bool remove(int index);
	T at(int index);
	bool contains(T data);
	int size();
	bool swap(int index1, int index2);
	void shuffle();
	bool isPalindrome();
	T getKthFromRear(int k);
	void removeDuplicates();
	void reverse();
	int count(T data);
	//Plus extra credit
	void sort();
	int JosephusSafe(int m, int n);

private:
	Node<T>* head;
	int numItems;//Keep track of the number of nodes in the list
};

template <class T>
void DoubleLinkedList<T>::addFront(T data)
{
	head = new Node<T>(data, head, NULL); //Creates a new node that points to where head did. Sets head to point to it.
	if (numItems == 0) { //If it is empty, we wont try and set the next node's previous (because it doesn't exist)
		numItems++;
		return;}
	head->next->prev = head;
	numItems++;
}

template <class T>
void DoubleLinkedList<T>::addRear(T data)
{
	Node<T>* nodePtr = head;
	//Iterate until nodePtr points to last node

	if (head == NULL)
	{
		head = new Node<T>(data, NULL, NULL);
		numItems++;
		return;
	}
	while(nodePtr != NULL){
		if(nodePtr->next == NULL)
		{
			nodePtr->next = new Node<T>(data, NULL, nodePtr);
			numItems++;
			return;
		}
		nodePtr = nodePtr->next;
	}
}

template <class T>
bool DoubleLinkedList<T>::addAt(T data, int index) //Can add to front or rear (i.e. index 0 or numItems)
{
	Node<T>* nodePtr = head;
	if (index < 0 || index > numItems)
		return false;
	else if (index == 0)
		addFront(data);
	else if (index == numItems)//numItems incrementing is taken care of by addFront and addRear.
		addRear(data);
	else
	{
		for (size_t i = 0; i < index; i++)
		{
			nodePtr = nodePtr->next;
		}
		nodePtr->prev->next = new Node<T>(data, nodePtr, nodePtr->prev);//These lines are making sure the adjacent nodes point to the new one. (both next and prev)
		nodePtr->prev = nodePtr->prev->next;
		numItems++;
		return true;
	}
}

template <class T>
bool DoubleLinkedList<T>::remove(int index)
{
	Node<T>* nodePtr = head;
	Node<T>* temp = NULL;
	if (index < 0 || index >= numItems)
	{
		//cout << "Passed in negative value" << endl;
		return false;
	}
	if (index == 0)//Boundry case so we don't access NULL
	{
		if (numItems == 1)//If there is only one thing in the list, we will just delete it.
		{
			delete head;
			head = NULL;
			numItems--;
			return true;
		}
		temp = nodePtr;
		head = nodePtr->next;
		head->prev = NULL;
		delete temp;
		numItems--;
		return true;
	}

	for (size_t i = 0; i < index; i++)
	{
		nodePtr = nodePtr->next;
	}
	temp = nodePtr;
	if (index != numItems - 1) //If we are removing the last item, we don't change the prev of the next item because it is NULL.
		nodePtr->next->prev = nodePtr->prev;
	nodePtr->prev->next = nodePtr->next;
	/*temp = nodePtr->next;
	nodePtr->next = nodePtr->next->next;*/
	delete temp;
	numItems--;
	return true;
}

template <class T>
T DoubleLinkedList<T>::at(int index)//Will be valid index.
{
	Node<T>* nodePtr = head;
	/*if (index >= numItems || index < 0)
	{
	cout << "Out of bounds\n";
	return -1;
	}*/
	for (size_t i = 0; i < index; i++)
	{
		nodePtr = nodePtr->next;
	}
	return nodePtr->data;
}

template <class T>
bool DoubleLinkedList<T>::contains(T data)
{
	Node<T>* nodePtr = head;
	while (nodePtr != NULL)
	{
		if (data == nodePtr->data)//Iterate through the whole list, if any of the nodes contain data, return true
		{
			return true;
		}

		nodePtr = nodePtr->next;
	}
	return false;
}

template <class T>
int DoubleLinkedList<T>::size()//The size has been kept track of.
{	
	return numItems;
}

template <class T>
bool DoubleLinkedList<T>::swap(int index1, int index2) //Is it valid for index1 and index2 to be equal? Yes
{
	Node<T>* nodePtr = head;
	if (index1 < 0 || index1 >= numItems || index2 < 0 || index2 >= numItems)//It is valid for index1 and index2 to be equal. It will return true
	{
		return false;
	}
	T index1to2;//What will be placed in the 2nd index
	T index2to1;//What will be placed in the 1st index
	for (size_t i = 0; i < index1; i++)//interate to index position
	{
		nodePtr = nodePtr->next;
	}
	index1to2 = nodePtr->data;
	nodePtr = head;//To start over
	for (size_t i = 0; i < index2; i++)//interate to index position
	{
		nodePtr = nodePtr->next;
	}
	index2to1 = nodePtr->data;
	nodePtr = head;//To start over
	//The swap values have been determined, so now we insert them in their proper positions.
	for (size_t i = 0; i < index1; i++)//interate to index position
	{
		nodePtr = nodePtr->next;
	}
	nodePtr->data = index2to1;
	nodePtr = head;//To start over
	for (size_t i = 0; i < index2; i++)//interate to index position
	{
		nodePtr = nodePtr->next;
	}
	nodePtr->data = index1to2;
	nodePtr = head;//Just because
	return true;
}


template <class T>
void DoubleLinkedList<T>::shuffle()//There is a chance that a place will have the same value, but every position is affected.
{
	for (size_t i = 0; i < numItems; i++)
	{
		int num = rand() % numItems;
		while (num == i)//This is to ensure every number is changed. i.e. the same indexes are not switched with one another. It is still possible for a number to be switched out and then switched in.
			num = rand() % numItems;
		swap(i, num);
	}
	return;
}

template <class T>
bool DoubleLinkedList<T>::isPalindrome()//If it is a string, does each word have to be a palindrome? I'll assume that's impossible to account for.
{
	DoubleLinkedList<T> tempDLL;
	Node<T>* nodePtr = head;
	/*
	Copy the contents into the tempDLL. Call reverse. Compare each data field. if they are equal, it is a Palindrome.
	*/
	while (nodePtr != NULL)
	{
		tempDLL.addRear(nodePtr->data);
		nodePtr = nodePtr->next;
	}
	tempDLL.reverse();
	nodePtr = head;
	for (size_t i = 0; i < numItems; i++)
	{
		if (nodePtr->data != tempDLL.at(i))
			return false;
		nodePtr = nodePtr->next;
	}
	return true; //Will return true if it makes it entirely through each list, ensuring it is a Palindrome.
}

template <class T>
T DoubleLinkedList<T>::getKthFromRear(int k)
{
	return at(numItems - 1 - k);//This just evaluates the index from the back, then counts normally. Same result.
}

template <class T>
void DoubleLinkedList<T>::removeDuplicates()
{
	//Count number of nodes containing data of first node. delete until there is 1. then second, etc.
	Node<T>* nodePtr = head;
	for (size_t i = 0; i < numItems; i++)
	{
		T duplicatedItem = at(i);
		int numToDelete = count(duplicatedItem) -1;

		int j = i+1; //To interate from the first location it was found.
		while (numToDelete > 0)
		{
			if (duplicatedItem == at(j))//We don't increment j here because it is effectivly incremented by deleting the current item.
			{
				remove(j);
				numToDelete--;
			}
			else
				j++;
		}
	}
	return;
}

template <class T>
void DoubleLinkedList<T>::reverse()//Swap first and last, then 2nd and 2nd to last, etc.
{
	for (size_t i = 0; i < numItems/2; i++)
	{
		swap(i, numItems -1 - i);
	}
	return;
}

template <class T>
int DoubleLinkedList<T>::count(T data)//Iterate through and add to currentCount for each instance of the data found.
{
	Node<T>* nodePtr = head;
	int currentCount = 0;
	while (nodePtr != NULL)
	{
		if (nodePtr->data == data)
			currentCount++;
		nodePtr = nodePtr->next;
	}

	return currentCount;
}



//Extra Credit

template <class T>
void DoubleLinkedList<T>::sort()
{
	return;
}

template <class T>
int DoubleLinkedList<T>::JosephusSafe(int m, int n)
{
	return -1;
}