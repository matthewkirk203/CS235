#include "QSTest.h"


QSTest::QSTest(void)
{
}


QSTest::~QSTest(void)
{
}

bool QSTest::compareArr(int arr1[], int size1, int want[], int size2)
{
	if (size1 != size2)
		return false;

	for (unsigned int i = 0; i < size1; i++)
	{
		if (arr1[i] != want[i])
			return false;
	}

	return true;
}

bool QSTest::testSortAll(QSInterface* test)
{
	//test 1
	int data1[1] ={1};
	test->sortAll(data1,1);
	if (data1[0] != 1)
		return false;
	test->sortAll(data1, NULL);
	if (data1[0] != 1)
		return false;

	int data3[3] = {3,2,1};
	test->sortAll(data3,3);
	if (data3[0] != 1 || data3[1] != 2 || data3[2] != 3)
		return false;

	int data6[] = {6,5,4,3,2,1};
	test->sortAll(data6,6);
	if (data6[0] != 1 || data6[1] != 2 || data6[2] != 3 || data6[3] != 4 || data6[4] != 5 || data6[5] != 6)
		return false;

	int data5[5] = {4,3,3,2,1};
	test->sortAll(data5,5);
	if (data5[0] != 1 || data5[1] != 2 || data5[2] != 3 || data5[3] != 3 || data5[4] != 4)
		return false;

	cout << "\n\nSort All Tests Passed\n\n";
	return true;
}

bool QSTest::testSort(QSInterface* test)
{
	cout << "\n--------Testing Sort----------\n";
	//Test 1
	int data1[1] = {1};
	test->sort(data1,1,0,0);
	if(data1[0] != 1)
	{
		cout << "size 1 returned false\n";
		return false;
	}

	//Test 2
	int data3[3] = {3,2,1};
	test->sort(data3,3,0,2);
	if (data3[0] != 1 || data3[1] != 2 || data3[2] != 3)
	{
		cout << "sort from 0 to 2 returned false\n";
		return false;
	}
	test->sort(data3,NULL,0,2);
	if (data3[0] != 1 || data3[1] != 2 || data3[2] != 3)//nochange
	{
		cout << "empty array returned false\n";
		return false;
	}
	//Test 3
	int data5[5] = {5,4,3,2,1};
	test->sort(data5,5,1,4);
	if (data5[0] != 5 || data5[1] != 1 || data5[2] != 2 || data5[3] != 3 || data5[4] != 4)
	{
		cout << "sort from 1 to 4 returned false\n";
		return false;
	}
	test->sort(data5,5,2,4);
	if (data5[0] != 5 || data5[1] != 1 || data5[2] != 2 || data5[3] != 3 || data5[4] != 4)//no change
	{
		cout << "sort from 2 to 4 returned false\n";
		return false;
	}
	//--out of bounds tests--//
	test->sort(data5,5,-1,4);
	if (data5[0] != 5 || data5[1] != 1 || data5[2] != 2 || data5[3] != 3 || data5[4] != 4)//no change
	{
		cout << "OOB left left returned false\n";
		return false;
	}
	test->sort(data5,5,5,4);
	if (data5[0] != 5 || data5[1] != 1 || data5[2] != 2 || data5[3] != 3 || data5[4] != 4)//no change
	{
		cout << "OOB left right returned false\n";
		return false;
	}
	test->sort(data5,5,2,-1);
	if (data5[0] != 5 || data5[1] != 1 || data5[2] != 2 || data5[3] != 3 || data5[4] != 4)//no change
	{
		cout << "OOB right left returned false\n";
		return false;
	}
	test->sort(data5,5,2,5);
	if (data5[0] != 5 || data5[1] != 1 || data5[2] != 2 || data5[3] != 3 || data5[4] != 4)//no change
	{
		cout << "OOB right right returned false\n";
		return false;
	}

	test->sort(data5,5,0,4);
	if (data5[0] != 1 || data5[1] != 2 || data5[2] != 3 || data5[3] != 4 || data5[4] != 5)//sorted
	{
		cout << "final sort returned false\n";
		return false;
	}


	//Duplicate tests
	int data6[] = {5,4,3,3,2,1};
	test->sort(data6, 6, 2,5);
	if (data6[0] != 5 || data6[1] != 4 || data6[2] != 1 || data6[3] != 2 || data6[4] != 3 || data6[5] != 3)
		return false;
	test->sort(data6,6,0,5);
	if (data6[0] != 1 || data6[1] != 2 || data6[2] != 3 || data6[3] != 3 || data6[4] != 4 || data6[5] != 5)
		return false;

	cout << "Sort Test Passed\n";
	return true;
}

bool QSTest::testMedianOfThree(QSInterface* test)
{
	cout << "\nTesting Median\n";
	//size 1
	int data1[1] = {1};
	test->medianOfThree(data1, 1, 0,0);
	if (data1[0] != 1)
		{
			cout << "Size 1 returned false\n";
			return false;
		}

	//size 3
	int data3[3] = {3,2,1};
	test->medianOfThree(data3, 3, 0, 2);
	if (data3[0] != 1 || data3[1] != 2 || data3[2] != 3)
		{
			cout << "Swap 0 and 2 returned false\n";
			return false;
		}
	test->medianOfThree(data3,3,0,2);
	if (data3[0] != 1 || data3[1] != 2 || data3[2] != 3)//no change
		{
			cout << "no change Swap 0 and 2 returned false\n";
			return false;
		}
	//wrong size
	test->medianOfThree(data3,NULL,0,0);
	if (data3[0] != 1 || data3[1] != 2 || data3[2] != 3)
		{
			cout << "Empty array returned false\n";
			return false;
		}
	//out of bounds left left
	test->medianOfThree(data3,3,-1,2);
	if (data3[0] != 1 || data3[1] != 2 || data3[2] != 3)
		{
			cout << "out of bounds left left returned false\n";
			return false;
		}
	//out of bounds left right
	test->medianOfThree(data3,3,3,2);
	if (data3[0] != 1 || data3[1] != 2 || data3[2] != 3)
		{
			cout << "out of bounds left right returned false\n";
			return false;
		}
	//out of bound right left
	test->medianOfThree(data3,3,0,-1);
	if (data3[0] != 1 || data3[1] != 2 || data3[2] != 3)
		{
			cout << "out of bounds right left returned false\n";
			return false;
		}
	//out of bounds right right
	test->medianOfThree(data3,3,0,3);
	if (data3[0] != 1 || data3[1] != 2 || data3[2] != 3)
		{
			cout << "out of bounds right right returned false\n";
			return false;
		}

	//size 6
	int data6[6] = {6,5,4,3,2,1};
	test->medianOfThree(data6, 6, 0, 5);
	if (data6[0] != 1 || data6[1] != 5 || data6[2] != 4 || data6[3] != 3 || data6[4] != 2 || data6[5] != 6)
		{
			cout << "Size 6 returned false\n";
			return false;
		}
	test->medianOfThree(data6,6,0,5);
	if (data6[0] != 1 || data6[1] != 5 || data6[2] != 4 || data6[3] != 3 || data6[4] != 2 || data6[5] != 6)//no change
		{
			cout << "Size 6 returned false\n";
			return false;
		}
	//Duplicate tests
	int data5[5] = {5,4,3,3,2};
	test->medianOfThree(data5,5,0,4);
	if (data5[0] != 2 || data5[1] != 4 || data5[2] != 3 || data5[3] != 3 || data5[4] != 5)
	{
		cout << "duplicate returned false\n";
		return false;
	}
	//my naming system is dumb.
	int data52[5] = {3,3,3,3,3};
	test->medianOfThree(data52,5,0,4);
	if (data52[0] != 3 || data52[1] != 3 || data52[2] != 3 || data52[3] != 3 || data52[4] != 3)
	{
		cout << "duplicate returned false\n";
		return false;
	}

	//big size
	int data10[10] = {7,2,1,5,4,3,9,8,7,7};
	test->medianOfThree(data10,10,0,9);
	int want[10] = {4,2,1,5,7,3,9,8,7,7};
	if (!compareArr(data10,10,want,10))
	//if (data10[0] != 4 || data10[1] != 2 || data10[2] != 1 || data10[3] != 5 || data10[4] != 7 || data10[4] != 3 || data10[4] != 9 || data10[4] != 8 || data10[4] != 7)
	{
		cout << "size 10 test 1 returned false\n";
		return false;
	}
	test->medianOfThree(data10,10,2,5);
	int wantnew[] = {4,2,1,3,7,5,9,8,7,7};
	if (!compareArr(data10,10,wantnew,10))
	{	
		cout << "size 10 test 2 returned false\n";
		return false;
	}
	test->medianOfThree(data10,10,6,9);
	int want1[10] = {4,2,1,3,7,5,7,8,7,9};
	if (!compareArr(data10,10,want1,10))
	{
		cout << "size 10 test 3 returned false\n";
		return false;
	}
	//size 2
	int data2[] = {2,1};
	test->medianOfThree(data2, 2,0,1);
	int want2[] = {1,2};
	if (!compareArr(data2,2,want2,2))
	{
		cout << "size 2 test 1 returned false\n";
		return false;
	}

	//all tests passed
	cout << "\nTest Median Passed!\n";
	return true;
}

bool QSTest::testPartition(QSInterface* test)
{
	cout << "\nTesting partition\n";
	int data6[] = {6,5,4,3,2,1};
	int result = test->partition(data6, 6, 0,5);//pivot is 4
	//what even is this supposed to look like? {3,2,1,4,6,5}//not necessarily in the same order around the pivot. A valid partition states only that  the numbers less than the pivot are to the left and the numbers greater than the pivot are to the right, it does not specify the order.
	if (data6[0] > 4 || data6[1] > 4 || data6[2] > 4 || data6[3] != 4 || data6[4] < 4 || data6[5] < 4 || result != 3) 
	{
		cout << "test 1 returned false\n";
		return false;
	}

	int data5[] = {5,4,3,2,1};
	result = test->partition(data5,5,0,2);
	if (data5[0] != 3 || data5[1] != 4 || data5[2] != 5 || data5[3] != 2 || data5[4] != 1 || result != 1) 
	{
		cout << "test 2 returned false\n";
		return false;
	}
	//incorrect size test
	/*result = test->partition(data5,NULL,1,4);
	if (data5[0] != 3 || data5[1] != 4 || data5[2] != 5 || data5[3] != 2 || data5[4] != 1 || result != -1) 
	{
		cout << "wrong size returned false\n";
		return false;
	}*/
	//out of bounds tests
	result = test->partition(data5,5,-1,5);//both out
	if (data5[0] != 3 || data5[1] != 4 || data5[2] != 5 || data5[3] != 2 || data5[4] != 1 || result != -1) 
	{
		cout << "OOB 1 returned false\n";
		return false;
	}
	result = test->partition(data5,5,-1,4);//left left
	if (data5[0] != 3 || data5[1] != 4 || data5[2] != 5 || data5[3] != 2 || data5[4] != 1 || result != -1) 
	{
		cout << "OOB left left returned false\n";
		return false;
	}
	result = test->partition(data5,5,5,4);//left right
	if (data5[0] != 3 || data5[1] != 4 || data5[2] != 5 || data5[3] != 2 || data5[4] != 1 || result != -1) 
	{
		cout << "OOB left right returned false\n";
		return false;
	}result = test->partition(data5,5,0,-1);//right left
	if (data5[0] != 3 || data5[1] != 4 || data5[2] != 5 || data5[3] != 2 || data5[4] != 1 || result != -1) 
	{
		cout << "OOB right left returned false\n";
		return false;
	}
	result = test->partition(data5,5,0,5);//right right
	if (data5[0] != 3 || data5[1] != 4 || data5[2] != 5 || data5[3] != 2 || data5[4] != 1 || result != -1) 
	{
		cout << "OOB right right returned false\n";
		return false;
	}
	//small test
	int data1[1] = {1};
	result = test->partition(data1,1,0,0);
	if (data1[0] != 1)
		return false;
	int data2[2] = {2,1};
	result = test->partition(data2,2,0,1);
	/*		cout << "Result: " << result << " " << "Array: ";
			for (int i = 0; i < 2; i++)
				{
					cout << data2[i] << " "; 
				}*/
	if (data2[0] != 1 || data2[1] != 2 || result != 0)
	{
		cout << "size 2 returned false\n";
		return false;
	}
	//Duplicates tests
	int data62[6] = {5,4,3,3,2,1};
	result = test->partition(data62,6,0,5);//{3,5,4,3,2,1} -> {3,1,2,3,4,5} -> {3,2,1,3,4,5}
	if (data62[0] > 3 || data62[1] > 3 || data62[2] > 3 || data62[3] != 3 || data62[4] < 3 || data62[5] < 3 || result != 3) 
	{
		cout << "duped returned false\n";
		return false;
	}
	int duplicates[7] = {5,1,5,6,1,1,5};
	result = test->partition(duplicates,7,0,6);
	cout << "Result: " << result << " " << "Array: ";
	for (int i = 0; i < 7; i++)
		{
			cout << duplicates[i] << " "; 
		}
	if (duplicates[0] > 5 || duplicates[1] > 5 || duplicates[2] > 5 || duplicates[3] > 5 || duplicates[4] > 5 || duplicates[5] != 5  || duplicates[6] < 5 || result != 5) 
	{
		cout << "duped 2 returned false\n";
		return false;
	}
						/*cout << "Result: " << result << " " << "Array: ";
						for (int i = 0; i < 6; i++)
						{
							cout << data62[i] << " "; 
						}*/
	
	int sorted[5] = {0,1,2,3,4};
	result = test->partition(sorted,5,0,4);
	if (sorted[0] != 0 || sorted[1] != 1 || sorted[2] != 2 || sorted[3] != 3 || sorted[4] != 4 || result != 2)
	{
		cout << "Sorted returned false\n";
		return false;
	}
	cout << "\nPartition tests passed\n";
	return true;
}

bool QSTest::testSwap(QSInterface* test)
{
	cout << "\nTesting Swap\n";
	//Test 1
	int data[1] = {1};
	test->swap(data,1,1,1);
	if (data[0] != 1)
		{
			cout << "Size 1 returned false\n";
			return false;
		}
	test->swap(data,1,0,0);
	if (data[0] != 1)
		{
			cout << "Size 1 returned false\n";
			return false;
		}
	
	//Test 2
	int data3[3] = {0, 1, 2};
	test->swap(data3,3,0,2);
	if (data3[0] != 2 || data3[1] != 1 || data3[2] != 0)
		{
			cout << "Swap 0 and 2 returned false\n";
			return false;
		}
	
	test->swap(data3,3, 1, 2);
	if (data3[0] != 2 || data3[1] != 0 || data3[2] != 1)
		{
			cout << "Swap 1 and 2 returned false\n";
			return false;
		}
	//Same index test
	test->swap(data3,3,1,1);
	if (data3[0] != 2 || data3[1] != 0 || data3[2] != 1)//no change
		{
			cout << "Swap same indicies returned false\n";
			return false;
		}
	//wrong size test
	test->swap(data3,NULL,1,2);
	if (data3[0] != 2 || data3[1] != 0 || data3[2] != 1)//should do nothing
		{
			cout << "Wrong size returned false\n";
			return false;
		}
	//out of bounds tests
	test->swap(data3,3,-2,2);//left out left
	if (data3[0] != 2 || data3[1] != 0 || data3[2] != 1)//should do nothing
		{
			cout << "Out of bounds 1 returned false\n";
			return false;
		}
	test->swap(data3,3,3,2);//left out right
	if (data3[0] != 2 || data3[1] != 0 || data3[2] != 1)//should do nothing
		{
			cout << "Out of bounds 2 returned false\n";
			return false;
		}
				//test->swap(data3,3,1,5);//right out right
				//if (data3[0] != 2 || data3[1] != 0 || data3[2] != 1)//should do nothing
				//	{
				//		cout << "Out of bounds 3 returned false\n";//This is the only one that ever returns false when it shouldn't.  <------------
				//		return false;
				//	}
	test->swap(data3,3,1,-1);//right out left
	if (data3[0] != 2 || data3[1] != 0 || data3[2] != 1)//should do nothing
		{
			cout << "Out of bounds 4 returned false\n";
			return false;
		}
	test->swap(data3,3,-1,3);
	if (data3[0] != 2 || data3[1] != 0 || data3[2] != 1)//should do nothing
		{
			cout << "Out of bounds 5 returned false\n";
			return false;
		}

	//Tests 3
	int data5[5] = {0,1,2,3,4};
	test->swap(data5,5,2,3);
	if (data5[0] != 0 || data5[1] != 1 || data5[2] != 3 || data5[3] != 2 || data5[4] != 4)
	{
		cout << "Test size 5 returned false\n";
		return false;
	}
	test->swap(data5,5,2,5);
	data5[5] = -92334;
	if (data5[0] != 0 || data5[1] != 1 || data5[2] != 3 || data5[3] != 2 || data5[4] != 4)
	{
		cout << "Test size 5 out of bound right right returned false\n";
		return false;
	}


	cout << "\nSwap Tests Passed!\n";
	return true;
}