#pragma once
#include "StationInterface.h"
#include "StationInterfaceExtra.h"
#include "myStack.h"
#include "myQueue.h"
#include "myDeque.h"
#include "IRDeque.h"
#include "ORDeque.h"

class Station :
	public StationInterfaceExtra
{
public:
	Station(void);
	~Station(void);

	bool addToStation(int car);
	int showCurrentCar();
	bool removeFromStation();

	bool addToStack();
	bool removeFromStack();
	int showTopOfStack();
	int showSizeOfStack();

	bool addToQueue();
	bool removeFromQueue();
	int showTopOfQueue();
	int showSizeOfQueue();

	bool addToDequeLeft();
	bool addToDequeRight();
	bool removeFromDequeLeft();
	bool removeFromDequeRight();
	int showTopOfDequeLeft();
	int showTopOfDequeRight();
	int showSizeOfDeque();

	bool addToIRDequeLeft();
	bool removeFromIRDequeLeft();
	bool removeFromIRDequeRight();
	int showTopOfIRDequeLeft();
	int showTopOfIRDequeRight();
	int showSizeOfIRDeque();

	bool addToORDequeLeft();
	bool addToORDequeRight();
	bool removeFromORDequeLeft();
	int showTopOfORDequeLeft();
	int showSizeOfORDeque();

private:
	int currentCar;
	myStack stack;
	myQueue queue;
	myDeque deque;
	IRDeque IRDeque;
	ORDeque ORDeque;
};

