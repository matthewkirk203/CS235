#pragma once
#include "QSTestInterface.h"
class QSTest :
	public QSTestInterface
{
public:
	QSTest(void);
	~QSTest(void);
	bool testSortAll(QSInterface* test);
	bool testSort(QSInterface* test);
	bool testMedianOfThree(QSInterface* test);
	bool testPartition(QSInterface* test);
	bool testSwap(QSInterface* test);

	bool compareArr(int arr1[], int size1,  int want[], int size2);
};

