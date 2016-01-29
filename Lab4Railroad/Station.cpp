#include "Station.h"


Station::Station(void)
{
	currentCar = -1;
}


Station::~Station(void)
{
}

bool Station::addToStation(int car)
{
	if(car < 0)
	{return false;}

	else if(stack.isPresent(car) || queue.isPresent(car) || deque.isPresent(car) || IRDeque.isPresent(car) || ORDeque.isPresent(car))
	{return false;}

	else if(currentCar == -1)
	{currentCar = car;
	return true;}

	else
	{return false;}

}
int Station::showCurrentCar()
{
	return currentCar;
}
bool Station::removeFromStation()
{
	if (currentCar != -1)
	{currentCar = -1;
	return true;}
	else
	{return false;}
}
//-----------------------------------------------------------------------//
bool Station::addToStack() 
{
	/*if (stack.push(currentCar)) //Stack checks for size on its own and returns false if it is at 5
	{currentCar = -1;
	return true;}
	else
	{return false;}*/
	if (stack.size() < 5 && currentCar != -1)
	{
		stack.push(currentCar);
		currentCar = -1;
		return true;
	}

	else
	{return false;}
}
bool Station::removeFromStack()
{
	/*if (currentCar == -1)
	{
		currentCar = stack.top();
		stack.pop();
		return true;
	}
	else
	{return false;}*/
	if (stack.size() > 0 && currentCar == -1)
	{
		currentCar = stack.top();
		stack.pop();
		return true;
	}
	else
	{return false;}
}
int Station::showTopOfStack()
{
	if (stack.size() > 0)
	{return stack.top();}
	else
	{return -1;}
}
int Station::showSizeOfStack()
{
	return stack.size();
}
//-----------------------------------------------------------------------//
bool Station::addToQueue()
{
	/*if (queue.insert(currentCar)) //Queue checks for size on its own and returns false if it is at 5
	{currentCar = -1;
	return true;}

	else
	{return false;}*/
		if (queue.size() < 5 && currentCar != -1)
	{
		queue.insert(currentCar);
		currentCar = -1;
		return true;
	}

	else
	{return false;}
}
bool Station::removeFromQueue()
{
	/*if (currentCar == -1)
	{
		currentCar = queue.top();
		queue.remove();
		return true;
	}
	else
	{return false;}*/
	if (queue.size() > 0 && currentCar == -1)
	{
		currentCar = queue.top();
		queue.remove();
		return true;
	}
	else
	{return false;}
}
int Station::showTopOfQueue()
{
	if (queue.size() > 0)
	{return queue.top();}
	else
	{return -1;}
}
int Station::showSizeOfQueue()
{
	return queue.size();
}
//---------------------------------------------------------------------//
bool Station::addToDequeLeft()
{
		if (deque.size() < 5 && currentCar != -1)
	{
		deque.addLeft(currentCar);
		currentCar = -1;
		return true;
	}

	else
	{return false;}
}
bool Station::addToDequeRight()
{
		if (deque.size() < 5 && currentCar != -1)
	{
		deque.addRight(currentCar);
		currentCar = -1;
		return true;
	}

	else
	{return false;}
}
bool Station::removeFromDequeLeft()
{
	if (deque.size() > 0 && currentCar == -1)
	{
		currentCar = deque.getLeft();
		deque.removeLeft();
		return true;
	}
	else
	{return false;}
}
bool Station::removeFromDequeRight()
{
		if (deque.size() > 0 && currentCar == -1)
	{
		currentCar = deque.getRight();
		deque.removeRight();
		return true;
	}
	else
	{return false;}
}
int Station::showTopOfDequeLeft()
{
	if (deque.size() > 0)
	{return deque.getLeft();}
	else
	{return -1;}
}
int Station::showTopOfDequeRight()
{
	if (deque.size() > 0)
	{return deque.getRight();}
	else
	{return -1;}
}
int Station::showSizeOfDeque()
{
	return deque.size();
}
//---------------------------------------------------------------------//
bool Station::addToIRDequeLeft()
{
	if (IRDeque.size() < 5 && currentCar != -1)
	{
		IRDeque.addLeft(currentCar);
		currentCar = -1;
		return true;
	}

	else
	{return false;}
}
bool Station::removeFromIRDequeLeft()
{
	if (IRDeque.size() > 0 && currentCar == -1)
	{
		currentCar = IRDeque.getLeft();
		IRDeque.removeLeft();
		return true;
	}
	else
	{return false;}
}
bool Station::removeFromIRDequeRight()
{
	if (IRDeque.size() > 0 && currentCar == -1)
	{
		currentCar = IRDeque.getRight();
		IRDeque.removeRight();
		return true;
	}
	else
	{return false;}
}
int Station::showTopOfIRDequeLeft()
{
	if (IRDeque.size() > 0)
	{return IRDeque.getLeft();}
	else
	{return -1;}
}
int Station::showTopOfIRDequeRight()
{
	if (IRDeque.size() > 0)
	{return IRDeque.getRight();}
	else
	{return -1;}
}
int Station::showSizeOfIRDeque()
{
	return IRDeque.size();
}
//---------------------------------------------------------------------//
bool Station::addToORDequeLeft()
{
	if (ORDeque.size() < 5 && currentCar != -1)
	{
		ORDeque.addLeft(currentCar);
		currentCar = -1;
		return true;
	}

	else
	{return false;}
}
bool Station::addToORDequeRight()
{
	if (ORDeque.size() < 5 && currentCar != -1)
	{
		ORDeque.addRight(currentCar);
		currentCar = -1;
		return true;
	}

	else
	{return false;}
}
bool Station::removeFromORDequeLeft()
{
	if (ORDeque.size() > 0 && currentCar == -1)
	{
		currentCar = ORDeque.getLeft();
		ORDeque.removeLeft();
		return true;
	}
	else
	{return false;}
}
int Station::showTopOfORDequeLeft()
{
	if (ORDeque.size() > 0)
	{return ORDeque.getLeft();}
	else
	{return -1;}
}
int Station::showSizeOfORDeque()
{
	return ORDeque.size();
}