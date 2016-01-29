#include "ORDeque.h"
//#include <iostream>

ORDeque::ORDeque(void)
{
}


ORDeque::~ORDeque(void)
{
}

bool ORDeque::addLeft(int current)
{
	//cout << "ORDeque: addLeft " << current << endl;
	list.insertHead(current);
	return true;
}
bool ORDeque::addRight(int current)
{
	//cout << "ORDeque: addRight " << current << endl;
	list.insertTail(current);
	return true;
}
bool ORDeque::removeLeft()
{
	//cout << "ORDeque: removeLeft " << endl;
	list.remove(list.at(0));
	return true;
}
int ORDeque::getLeft()
{
	//cout << "ORDeque: getLeft " << endl;
	return list.at(0);
}
int ORDeque::getRight()
{
	//cout << "ORDeque: getRight " << endl;
	return list.at(list.size() - 1);
}
int ORDeque::size()
{
	//cout << "ORDeque: size " << endl;
	return list.size();
}
bool ORDeque::isPresent(int value)
{
	//cout << "ORDeque: present " << endl;
	return list.present(value);
}