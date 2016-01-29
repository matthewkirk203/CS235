#include "myQueue.h"
//#include <iostream>

myQueue::myQueue(void)
{
}


myQueue::~myQueue(void)
{
}

bool myQueue::insert(int current)
{
	/*if (list.size() < 5)
	{
		list.insertHead(current);
		return true;
	}
	else
	{
		return false;
	}*/
	//cout << "Queue: insert " << current << endl;
	//list.insertHead(current);
	list.insertTail(current);
	return true;
}

bool myQueue::remove()
{
	/*if (list.size() > 0)
	{list.remove(list.at(list.size()));
	return true;}
	else
	{
		return false;
	}*/
	//cout << "Queue: remove " << endl;
	//list.remove(list.at(list.size()));
	list.remove(list.at(0));
	return true;

}

int myQueue::size()
{
	//cout << "Queue: size" << endl;
	return list.size();
}

int myQueue::top()
{
	/*if (list.size() > 0)
	{return list.at(list.size());}
	else
	{return -1;}*/
	//cout << "Queue: top" << endl;
	//return list.at(list.size());
	return list.at(0);
}

bool myQueue::isPresent(int value)
{
	if (list.present(value))
	{return true;}
	else
	{return false;}
}