#include "Arena.h"
#include "Robot.h"
#include "Archer.h"
#include "Cleric.h"
#include <sstream>
#include <vector>

using namespace std;

Arena::Arena(void)
{
}


Arena::~Arena(void)
{
}


bool Arena::addFighter(string info) //(name) (type) (maximum hit points) (strength) (speed) (magic)
{
	string name, type;
	int maximumHP, strength, speed, magic;
	stringstream scan;
	scan << info;
	scan >> name >> type >> maximumHP >> strength >> speed >> magic;

	//Tests for validity
	if(scan.fail() || !scan.eof()){return false;}
	if(maximumHP < 1 || strength < 1 || speed < 1 || magic < 1)
	{return false;}

	for (unsigned int i=0; i < vector.size(); i++)
	{
		if (vector[i]->getName() == name)
		{
			return false;
		}
	}


	if (type=="C")
	{
		vector.push_back(new Cleric(name, maximumHP, strength, speed, magic));
	}
	else if (type=="A")
	{
		vector.push_back(new Archer(name, maximumHP, strength, speed, magic));
	}
	else if (type=="R")
	{
		vector.push_back(new Robot(name, maximumHP, strength, speed, magic));
	}
	else
	{
		return false;
	}
	return true;
}

bool Arena::removeFighter(string name)
{
	for (unsigned int i=0; i < vector.size(); i++)
	{
		if (vector[i]->getName() == name)
		{
			vector.erase(vector.begin() + (i));
			return true;
		}
	}
	return false;
}

FighterInterface* Arena::getFighter(string name)
{
	for (unsigned int i=0; i < vector.size(); i++)
	{
		if (vector[i]->getName() == name)
		{
			return vector[i];
		}
	}
	//If not found
	return NULL;
}

int Arena::getSize()
{
	return vector.size();
}
