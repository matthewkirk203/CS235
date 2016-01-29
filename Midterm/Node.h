/*
	Matthew Kirk
	Section : 4
	CS 235 Fall 2013 Midterm
*/
#pragma once

using namespace std;

template <class Type> class Node
{
public:
	Node<Type>(Type d, Node<Type>* n, Node<Type>* p)
	{
		data = d;
		next = n;
		prev = p;
	}
	//~Node<Type>(void);
	Type data;
	Node<Type>* next;
	Node<Type>* prev;
};