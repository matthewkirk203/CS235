#include "Pathfinder.h"
#include <iostream>
using namespace std;

int main()
{
	Pathfinder thingy;

	while (true)
	{
		cout << "First Maze:\n\n";
		//thingy.createRandomMaze();
		cout << "File Name pl0x: ";
		string fileName1 ="";
		cin >> fileName1;
		bool a = thingy.importMaze(fileName1);
		if (a)
		{
			cout << "True\n";
		}
		else
		{
			cout << "False\n";
		}
		cout << thingy.getMaze();
		vector<string> path = thingy.solveMaze();
		for (size_t i = 0; i < path.size(); i++)
		{
			cout << path[i] << endl;
		}
		//system("pause");
	}
	//cout << "Second Maze:\n\n";
	//thingy.createRandomMaze();
	//cout << thingy.getMaze();
	system("pause");

	return 0;
}
