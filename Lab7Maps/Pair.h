#pragma once
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

class Pair
{
public:
	Pair(string key, string value);
	~Pair(void);
	bool addValue(string newValue);
	string randomValue();

	string key;
	vector<string> value;
};

