#include "myDeque.h"
//#include <iostream>

myDeque::myDeque(void)
{
}


myDeque::~myDeque(void)
{
}

bool myDeque::addLeft(int current)
{
	//cout << "Deque: addLeft " << current << endl;
	list.insertHead(current);
	return true;
}
bool myDeque::addRight(int current)
{
	//cout << "Deque: addRight " << current << endl;
	list.insertTail(current);
	return true;
}
bool myDeque::removeLeft()
{
	//cout << "Deque: removeLeft " << endl;
	list.remove(list.at(0));
	return true;
}
bool myDeque::removeRight()
{
	//cout << "Deque: removeRight " << endl;
	list.remove(list.at(list.size() - 1));
	return true;
}
int myDeque::getLeft()
{
	//cout << "Deque: getLeft " << endl;
	return list.at(0);
}
int myDeque::getRight()
{
	//cout << "Deque: getRight " << endl;
	return list.at(list.size() - 1);
}
int myDeque::size()
{
	//cout << "Deque: size " << endl;
	return list.size();
}
bool myDeque::isPresent(int value)
{
	//cout << "Deque: present " << endl;
	return list.present(value);
}