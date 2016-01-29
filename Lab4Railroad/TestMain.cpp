#include "Station.h"

using namespace std;

int main()
{
	Station manager;
	/*manager.addToStation(1);
	manager.addToStation(2);
	//cout << manager.showCurrentCar() << endl;
	manager.addToStack();
	manager.addToStation(2);
	cout << manager.showCurrentCar() << endl;
	cout <<manager.showTopOfStack() << endl;
	manager.removeFromStation();
	manager.removeFromStack();
	cout << manager.showCurrentCar() << endl;
	cout << manager.showTopOfStack() << endl;
	cout << manager.showSizeOfStack() << endl;
	system ("pause");*/
	cout << "\n\n-----------------Testing Queue-------------------\n\n:";
	manager.removeFromStation();
	manager.addToStation(1);
	/*manager.addToQueue();
	cout << "Top of queue: " << manager.showTopOfQueue() << endl << "Size of Queue: " << manager.showSizeOfQueue() << endl;
	manager.removeFromQueue();
	cout << "Current Car: " << manager.showCurrentCar() << endl << "Top of Queue: " << manager.showTopOfQueue() << endl;
	system("pause");*/
	/*manager.addToDequeLeft();
	manager.addToStation(5);
	manager.addToDequeRight();
	manager.addToStation(2);
	manager.addToDequeLeft();
	manager.addToStation(-2);
	manager.addToDequeLeft();
	cout << "Top of Deque Left: " << manager.showTopOfDequeLeft() << endl << "Top of Deque Right " << manager.showTopOfDequeRight() << endl << "Deque size: " << manager.showSizeOfDeque() << endl;*/
	manager.addToIRDequeLeft();
	cout << "Top of IRDeque Left: " << manager.showTopOfIRDequeLeft() << endl << "Top of IRDeque Right " << manager.showTopOfIRDequeRight() << endl << "IRDeque size: " << manager.showSizeOfIRDeque() << endl;
	manager.addToStation(5);
	manager.addToIRDequeLeft();
	cout << "Top of IRDeque Left: " << manager.showTopOfIRDequeLeft() << endl << "Top of IRDeque Right " << manager.showTopOfIRDequeRight() << endl << "IRDeque size: " << manager.showSizeOfIRDeque() << endl;
	manager.addToStation(2);
	manager.addToIRDequeLeft();
	manager.removeFromIRDequeLeft();
	manager.removeFromIRDequeRight();
	cout << "Top of IRDeque Left: " << manager.showTopOfIRDequeLeft() << endl << "Top of IRDeque Right " << manager.showTopOfIRDequeRight() << endl << "IRDeque size: " << manager.showSizeOfIRDeque() << endl;
	system("pause");

	return 0;
}
