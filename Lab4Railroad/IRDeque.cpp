#include "IRDeque.h"
//#include <iostream>

IRDeque::IRDeque(void)
{
}


IRDeque::~IRDeque(void)
{
}

bool IRDeque::addLeft(int current)
{
	//cout << "IRDeque: addLeft " << current << endl;
	list.insertHead(current);
	return true;
}
bool IRDeque::removeLeft()
{
	//cout << "IRDeque: removeLeft " << endl;
	list.remove(list.at(0));
	return true;
}
bool IRDeque::removeRight()
{
	//cout << "IRDeque: removeRight " << endl;
	list.remove(list.at(list.size() - 1));
	return true;
}
int IRDeque::getLeft()
{
	//cout << "IRDeque: getLeft " << endl;
	return list.at(0);
}
int IRDeque::getRight()
{
	//cout << "IRDeque: getRight " << endl;
	return list.at(list.size() - 1);
}
int IRDeque::size()
{
	//cout << "IRDeque: size " << endl;
	return list.size();
}
bool IRDeque::isPresent(int value)
{
	//cout << "IRDeque: present " << endl;
	return list.present(value);
}