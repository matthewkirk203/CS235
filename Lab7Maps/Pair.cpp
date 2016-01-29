#include "Pair.h"

Pair::Pair(string k, string v)
{
	key = k;
	value.push_back(v);
	srand(time(NULL));
}


Pair::~Pair(void)
{
}

bool Pair::addValue(string newValue)
{
	value.push_back(newValue);
	return true;
}

string Pair::randomValue()
{
	int randValue = rand() % value.size();
	return value[randValue];
}