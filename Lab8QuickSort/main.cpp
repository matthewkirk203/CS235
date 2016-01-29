#include "QSTest.h"


int main()
{
	int arr1[] = {1,2,3,4,5};
	int arr2[] = {1,2,3,4,5};
	QSTest thingy;
	if (thingy.compareArr(arr1,5,arr2,5))
		cout << "Equal works\n";
	else
		cout << "Equal does not work\n";

	int arr3[] = {1,4,2,3,2};
	if (!thingy.compareArr(arr1,5,arr3,5))
		cout << "Not equal works\n";
	else
		cout << "Not equal does not work\n";

	if (!thingy.compareArr(arr1,5,arr2,3))
		cout << "Unequal size works\n";
	else
		cout << "unequal size does not work\n";

	system("pause");
	return 0;
}