#pragma once
#include "arenainterface.h"
#include <vector>

using namespace std;

class Arena :
	public ArenaInterface
{
public:
	Arena(void);
	~Arena(void);

	bool addFighter(string info);
	bool removeFighter(string name);
	FighterInterface* getFighter(string name);
	int getSize();

private:
	vector<FighterInterface*> vector;
};

