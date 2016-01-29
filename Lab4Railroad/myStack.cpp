#include "myStack.h"
//#include <iostream>

myStack::myStack(void)
{
}


myStack::~myStack(void)
{
}

bool myStack::push(int current)
{
	/*if (list.size() < 5)
	{list.insertHead(current);
	return true;}

	else
	{return false;}*/
	//cout << "Stack.push(" << current << ")" << endl;
	list.insertHead(current);
	return true;
}

bool myStack::pop()
{
	/*if (list.size() > 0)
	{
		list.remove(list.at(0));
		return true;
	}
	else
	{return false;}*/
	//cout << "Pop\n";
	list.remove(list.at(0));
	return true;
}

int myStack::top()
{
	/*if(list.size() > 0)
	{return list.at(0);}
	else if (list.size() == 0)
	{return -1;}*/
	//cout << "Top\n";
	return list.at(0);

}

int myStack::size()
{
	//cout << "size\n";
	return list.size();
}

bool myStack::isPresent(int value)
{
	if (list.present(value))
	{return true;}
	else
	{return false;}
}
