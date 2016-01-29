#pragma once
#include "PathfinderInterface.h"
//#include <array>
const int ARRAYSIZE = 5;
class Pathfinder :
	public PathfinderInterface
{
public:
	Pathfinder(void);
	~Pathfinder(void);
	string getMaze();
	void createRandomMaze();
	bool importMaze(string fileName);
	vector<string> solveMaze();
	bool findExit(int x, int y, int z);
private:
	vector<string> path;
	string maze[ARRAYSIZE][ARRAYSIZE][ARRAYSIZE];
	string tempMaze[ARRAYSIZE][ARRAYSIZE][ARRAYSIZE];

	//array<int,ARRAYSIZE> x, y, z;

};

