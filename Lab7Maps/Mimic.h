#pragma once
#include "MimicInterface.h"
#include "Pair.h"

class Mimic :
	public MimicInterface
{
public:
	Mimic(void);
	~Mimic(void);
	void createMap(string input);
	vector<string> getSuffixList(string prefix);
	string generateText();
	int findKeyIndex(string theKey);

private:
	vector<Pair> myMap;
};

