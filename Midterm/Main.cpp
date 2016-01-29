/*
Matthew Kirk
Section : 4
CS 235 Fall 2013 Midterm
*/
#include "DoubleLinkedList.h"
#include <iostream>
#include <string>

int menu()
{
	//	cout << "This is the menu:\n";
	//	cout << "0.PrintDLL\n1.addFront\n2.addRear\n3.addAt\n4.remove\n5.at\n\n6.contains\n7.size\n8.swap\n9.shuffle\n10.isPalidrome\n11.getkthFromRear\n12.removeDuplicates\n13.reverse\n14.count\n\n";
	int choice = 0;
	//	cin >> choice;
	return choice;
}
int main()
{
	//DoubleLinkedList<double> DLL;
	/*cout << "This is my Double Linked List. Please kill me.\n\n";
	while (true)
	{
	int choice = menu();
	if (choice == 0)
	{
	for (size_t i = 0; i < DLL.size(); i++)//Print DLL
	{
	cout << DLL.at(i) << " ";
	}
	cout << endl;
	}

	else if (choice == 1)
	{
	cout << "Addwhat?: ";
	int toAdd;
	cin >> toAdd;
	DLL.addFront(toAdd);
	}

	else if (choice == 2)
	{
	cout << "Addwhat?: ";
	int toAdd;
	cin >> toAdd;
	DLL.addRear(toAdd);
	}

	else if (choice == 3)
	{
	cout << "What: ";
	int what, index;
	cin >> what;
	cout << "Where: ";
	cin >>index;
	DLL.addAt(what,index);
	} 

	else if (choice == 4)
	{
	}

	else if (choice == 5)
	{
	}

	else if (choice == 6)
	{
	}

	else if (choice == 7)
	{
	}

	else if (choice == 8)
	{
	}

	else if (choice == 9)
	{
	}

	else if (choice == 10)
	{
	}

	else if (choice == 11)
	{
	}
	else if (choice == 12)
	{
	}
	else if (choice == 13)
	{
	}
	else if (choice == 14)
	{
	}*/


	//for (size_t i = 0; i < 5; i++)
	//{
	//	DLL.addFront(rand()%3);
	//	DLL.addRear(rand()%3);
	//	if (!DLL.addAt(rand()%3, (rand() % DLL.size()*2)-DLL.size()))
	//		cout << "\nDidn't add something\n\n";
	//}
	//for (size_t i = 0; i < DLL.size(); i++)//Print DLL
	//{
	//	cout << DLL.at(i) << " ";
	//}
	//cout << endl << "Size: " << DLL.size() << endl;
	//cout << DLL.at(5) <<endl;
	//if (DLL.contains(99))
	//	cout << "Got Item!\n";
	//else
	//	cout << "whuah whuah whuah...\n";
	//int swap1 = (rand() % DLL.size()*2-DLL.size()); 
	//int swap2 = (rand() % DLL.size()*2-DLL.size());
	//cout << "Swap1: " << swap1 << " Swap2: " << swap2 << endl;
	//if (!DLL.swap(swap1,swap2))
	//	cout << "Didn't swap\n\n";
	//for (size_t i = 0; i < DLL.size(); i++)//Print DLL
	//{
	//	cout << DLL.at(i) << " ";
	//}
	//cout << endl;
	//cout << "Shuffle:\n";
	//DLL.shuffle();
	//for (size_t i = 0; i < DLL.size(); i++)//Print DLL
	//{
	//	cout << DLL.at(i) << " ";
	//}
	//cout << endl;
	//cout << "GetkthFromRear:\n";
	//int backindex = rand()%DLL.size();
	//cout << "Backindex = " << backindex << endl << "The number there is: " << DLL.getKthFromRear(backindex) << endl;
	//for (size_t i = 0; i < DLL.size(); i++)//Print DLL
	//{
	//	cout << DLL.at(i) << " ";
	//}
	//cout << endl;
	//cout << "Remove Duplicates\n";
	//DLL.removeDuplicates();
	//for (size_t i = 0; i < DLL.size(); i++)//Print DLL
	//{
	//	cout << DLL.at(i) << " ";
	//}
	//cout << endl;
	//cout << "Reverse:\n";
	//DLL.reverse();
	//for (size_t i = 0; i < DLL.size(); i++)//Print DLL
	//{
	//	cout << DLL.at(i) << " ";
	//}
	//cout << endl;



	//while (DLL.size() > 0)
	//{
	//	DLL.remove(rand()%DLL.size());
	//	for (size_t i = 0; i < DLL.size(); i++)//Print DLL
	//	{
	//		cout << DLL.at(i) << " ";
	//	}
	//	cout << endl;
	//}

	//for (size_t i = 0; i < 4; i++)
	//DLL.addRear(2);
	//for (size_t i = 0; i < 2; i++)
	//DLL.addRear(3);
	//for (size_t i = 0; i < DLL.size(); i++)//Print DLL
	//{
	//cout << DLL.at(i) << " ";
	//}
	//cout << endl;
	//for (size_t i = 0; i < 10; i++)
	//{
	//DLL.addRear(i);
	//DLL.addFront(i*2);
	//}
	//for (size_t i = 0; i < DLL.size(); i++)
	//{
	//cout << DLL.at(i) << " ";
	//}
	//cout << endl;
	//DLL.remove(5);
	//DLL.remove(3);
	//DLL.remove(0);
	//DLL.remove(DLL.size() - 1);
	//DLL.remove(-1);
	//DLL.remove(DLL.size());
	//for (size_t i = 0; i < DLL.size(); i++)//Print DLL
	//{
	//cout << DLL.at(i) << " ";
	//}
	//cout << endl;
	//if (DLL.contains(1))
	//cout << "Contains 1 \n";
	//else
	//cout << "Does not contain 1 \n";
	//if (DLL.contains(8))
	//cout <<"Contains 8 \n";
	//else
	//cout << "Does not contain 8 \n";
	//if (DLL.contains(15))
	//cout << "Contains 15 \n";
	//else
	//cout << "Does not contain 15 \n";

	//DLL.swap(0,DLL.size()-1);
	//for (size_t i = 0; i < DLL.size(); i++)//Print DLL
	//{
	//cout << DLL.at(i) << " ";
	//}
	//cout << endl;
	//DLL.shuffle();
	//for (size_t i = 0; i < DLL.size(); i++)//Print DLL
	//{
	//cout << DLL.at(i) << " ";
	//}
	//cout << endl;
	//DLL.shuffle();
	//for (size_t i = 0; i < DLL.size(); i++)//Print DLL
	//{
	//cout << DLL.at(i) << " ";
	//}
	//cout << endl;
	//DLL.shuffle();
	//for (size_t i = 0; i < DLL.size(); i++)//Print DLL
	//{
	//cout << DLL.at(i) << " ";
	//}
	//cout << endl;
	//cout << DLL.getKthFromRear(0) << endl << DLL.getKthFromRear(DLL.size() -1) << endl << DLL.getKthFromRear(DLL.size() / 2) << endl;
	//DLL.reverse();
	//for (size_t i = 0; i < DLL.size(); i++)//Print DLL
	//{
	//cout << DLL.at(i) << " ";
	//}
	//cout << endl;
	//DLL.reverse();
	//for (size_t i = 0; i < DLL.size(); i++)//Print DLL
	//{
	//cout << DLL.at(i) << " ";
	//}
	//cout << endl;
	//DLL.remove(DLL.size()/2);
	//for (size_t i = 0; i < DLL.size(); i++)//Print DLL
	//{
	//cout << DLL.at(i) << " ";
	//}
	//cout << endl;
	//DLL.reverse();
	//for (size_t i = 0; i < DLL.size(); i++)//Print DLL
	//{
	//cout << DLL.at(i) << " ";
	//}
	//cout << endl;
	//DLL.reverse();
	//for (size_t i = 0; i < DLL.size(); i++)//Print DLL
	//{
	//cout << DLL.at(i) << " ";
	//}
	//cout << endl;
	//DLL.addRear(1);
	//DLL.addRear(1);
	//DLL.addRear(1);
	//cout << DLL.count(1) << endl;
	//for (size_t i = 0; i < DLL.size(); i++)//Print DLL
	//{
	//cout << DLL.at(i) << " ";
	//}
	//cout << endl;
	//cout << "\nTesting: addAt\n\n";
	//DLL.addAt(69,0);
	//DLL.addAt(69,DLL.size()-1);
	//DLL.addAt(69,DLL.size()/2);
	//DLL.addAt(69,DLL.size());
	//for (size_t i = 0; i < DLL.size(); i++)//Print DLL
	//{
	//cout << DLL.at(i) << " ";
	//}
	//cout << endl;
	//cout << "size: " << DLL.size() << endl;
	//DLL.removeDuplicates();
	//for (size_t i = 0; i < DLL.size(); i++)//Print DLL
	//{
	//cout << DLL.at(i) << " ";
	//}
	//cout << endl;

	//Palindrome Test
	cout << "So you wanted to use my main. Well I was upset at this point. So enjoy my immaturity.\n";
	DoubleLinkedList<string> DLLS;
	DLLS.addRear("poop");
	DLLS.addRear("is");
	DLLS.addRear("good");
	DLLS.addRear("good");
	DLLS.addRear("good");
	DLLS.addRear("is");
	DLLS.addRear("poop");
	DLLS.addRear("good");
	DLLS.addFront("dino");
	DLLS.addAt("monkeybrain",rand()%DLLS.size());
	if (DLLS.contains("poop"))
		cout << "Has poop\n";
	cout << "Number of poops it has: " << DLLS.count("poop") << endl;

	for (size_t i = 0; i < DLLS.size(); i++)//Print DLL
	{
		cout << DLLS.at(i) << " ";
	}
	cout << endl;
	DLLS.removeDuplicates();
	for (size_t i = 0; i < DLLS.size(); i++)//Print DLL
	{
		cout << DLLS.at(i) << " ";
	}
	cout << endl;
	if (DLLS.isPalindrome())
		cout << "Sure is\n";
	else 
		cout << "Sure isn't\n";
	DLLS.shuffle();
	for (size_t i = 0; i < DLLS.size(); i++)//Print DLL
	{
	cout << DLLS.at(i) << " ";
	}
	cout << endl;
	DLLS.reverse();
	for (size_t i = 0; i < DLLS.size(); i++)//Print DLL
	{
	cout << DLLS.at(i) << " ";
	}
	cout << endl;
	while (DLLS.size() > 0)
	{
		DLLS.remove(rand()%DLLS.size());
		for (size_t i = 0; i < DLLS.size(); i++)//Print DLL
		{
			cout << DLLS.at(i) << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}