#include "Pathfinder.h"
#include <time.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
Pathfinder::Pathfinder(void)
{

	//unsigned int i = 0, j = 0, k = 0;
	for(unsigned int k = 0; k < ARRAYSIZE; k++)//iterate through each array
	{
		for(unsigned int j = 0; j < ARRAYSIZE; j++)
		{
			for(unsigned int i = 0; i < ARRAYSIZE; i++)
			{
				maze[i][j][k] = "1";
			}
		}
	}
	//path[0] = "(0, 0, 0)";
	//path.push_back("(0, 0, 0)");
	path.clear();
}


Pathfinder::~Pathfinder(void)
{
}

string Pathfinder::getMaze()
{
	string currentMaze = "";
	string sp = " ";
	string newline = "\n";
	for(unsigned int k = 0; k < ARRAYSIZE; k++)
	{
		for(unsigned int j = 0; j < ARRAYSIZE; j++)
		{
			for(unsigned int i = 0; i < ARRAYSIZE; i++)
			{
				currentMaze += maze[i][j][k] + sp;
				if (i == ARRAYSIZE - 1)
				{
					currentMaze += newline;

					if (j == ARRAYSIZE - 1)
					{currentMaze += newline;}
				}
			}
		}
	}

	return currentMaze;
}
void Pathfinder::createRandomMaze()
{
	for(unsigned int k = 0; k < ARRAYSIZE; k++)//iterate through each array
	{
		for(unsigned int j = 0; j < ARRAYSIZE; j++)
		{
			for(unsigned int i = 0; i < ARRAYSIZE; i++)
			{
				ostringstream convert;
				int randValue = rand() % 2;
				convert << randValue;
				string toInsert = convert.str();
				maze[i][j][k] = toInsert;
			}
		}
	}
	maze[0][0][0] = "1";
	maze[ARRAYSIZE-1][ARRAYSIZE-1][ARRAYSIZE-1] = "1";//so we have and entrance and exit.
}
bool Pathfinder::importMaze(string fileName)
{
	ifstream fs;
	//string tempMaze[ARRAYSIZE][ARRAYSIZE][ARRAYSIZE];
	fs.open(fileName);
	if (fs.is_open())
	{
		while (!fs.eof())
		{
			for(unsigned int k = 0; k < ARRAYSIZE; k++)//iterate through each array
			{
				for(unsigned int j = 0; j < ARRAYSIZE; j++)
				{
					for(unsigned int i = 0; i < ARRAYSIZE; i++)
					{
						fs >> tempMaze[i][j][k];
						if (fs.fail())
						{return false;}
						if (tempMaze[i][j][k] != "1" && tempMaze[i][j][k] != "0")
						{return false;}
					}
				}
			}
		}
	}
	else
	{return false;}
	if (tempMaze[0][0][0] != "1" || tempMaze[ARRAYSIZE-1][ARRAYSIZE-1][ARRAYSIZE-1] != "1")
	{return false;}
	//Copy into actual maze
	for(unsigned int k = 0; k < ARRAYSIZE; k++)//iterate through each array
	{
		for(unsigned int j = 0; j < ARRAYSIZE; j++)
		{
			for(unsigned int i = 0; i < ARRAYSIZE; i++)
			{
				maze[i][j][k] = tempMaze[i][j][k];
			}
		}
	}
	return true;
}
vector<string> Pathfinder::solveMaze()
{
	//Copy the maze into the temp maze for solving
	path.clear();
	for(unsigned int k = 0; k < ARRAYSIZE; k++)//iterate through each array
	{
		for(unsigned int j = 0; j < ARRAYSIZE; j++)
		{
			for(unsigned int i = 0; i < ARRAYSIZE; i++)
			{
				tempMaze[i][j][k] = maze[i][j][k];
			}
		}
	}
	if (findExit(0, 0, 0))
	{
		return path;
	}
	else
	{
		path.clear();
		return path;
	}
}

bool Pathfinder::findExit(int x, int y, int z)
{
	string currentPosition = "";
	string sp = " ", leftp = "(", rightp = ")", comma = ", ";
	ostringstream convert;
		convert << leftp << x << comma << y << comma << z << rightp;
		path.push_back(convert.str());

	if (x == ARRAYSIZE - 1 && y == ARRAYSIZE - 1 && z == ARRAYSIZE - 1) 
	{
		return true;
	}

	if (x == ARRAYSIZE || x < 0 || y == ARRAYSIZE || y < 0 || z == ARRAYSIZE || z < 0 || tempMaze[x][y][z] == "0")
	{
		path.pop_back();
		return false;
	}

	tempMaze[x][y][z] = "0";

	if (findExit(x+1, y, z))
	{
		return true;
	}
	else if (findExit(x,y+1,z))
	{
		return true;
	}
	else if (findExit(x,y,z+1))
	{
		return true;
	}
	else if (findExit(x-1,y,z))
	{
		return true;
	}
	else if (findExit(x,y-1,z))
	{
		return true;
	}
	else if (findExit(x,y,z-1))
	{
		return true;
	}
	else
	{
		
		path.pop_back();
		return false;
	}
}