#include "Mimic.h"
#include <sstream>

Mimic::Mimic(void)
{
}


Mimic::~Mimic(void)
{
}

void Mimic::createMap(string input)
{
	stringstream ss;
	ss.str(input);
	string key1;
	string key2;
	string value;
	ss >> key1 >> key2 >> value;
	string finalKey = key1 + " " + key2;//Two word key
	myMap.push_back(Pair(finalKey, value));
	while (!ss.eof())//Iterate through the string
	{
		key1 = key2;
		key2 = value;
		finalKey = key1 + " " + key2;
		ss >> value;
		bool contains = false;
		for (unsigned int i = 0; i < myMap.size(); i++)
		{
			if (myMap[i].key == finalKey)
			{
				contains = myMap[i].addValue(value);
				break;
			}
		}

		if(!contains)
			myMap.push_back(Pair(finalKey, value));
	}
	//End of string reached, add the final map element "THE_END"
	key1 = key2;
	key2 = value;
	finalKey = key1 + " " + key2;
	value = "THE_END";
	myMap.push_back(Pair(finalKey, value));
}

vector<string> Mimic::getSuffixList(string prefix)
{
	for (unsigned int i = 0; i < myMap.size(); i++)
	{
		if (myMap[i].key == prefix)
		{
			return myMap[i].value;
		}
	}
	vector<string> suffixListEmpty;
	return suffixListEmpty;
}

string Mimic::generateText()
{
	stringstream ss;
	stringstream splitter;
	string key = myMap[0].key;
	splitter.str(key);
	string key1, key2;
	splitter >> key1 >> key2;
	string value = myMap[0].randomValue();
	ss << key << " " << value;
	//cout << "Adding " << key << " " << value << "to stream." << endl;
	//cout << "Current contents of stream: " << ss.str() << endl;
	while(value != "THE_END")
	{
		//int randomKeyIndex = rand() % myMap.size();
		//key2 = value;
		//string oldValue = value;//am trying to figure out how to have "I like to boat" and then the key becomes "to boat" etc. But I'm done for now.
		stringstream splitter1;
		splitter1.str(key);
		splitter1 >> key1 >> key2;
		key = key2 + " " + value;
		value = myMap[findKeyIndex(key)].randomValue();
		if (value == "THE_END")
			break;
		ss << " " << value;
		//cout << "Adding " << value << "to stream." << endl;
	}
	//cout << "This is what I am returning:" << ss.str();
	return ss.str();
	
}

int Mimic::findKeyIndex(string theKey)
{
	for (unsigned int i = 0; i < myMap.size(); i++)
	{
		if (myMap[i].key == theKey)
		{
			return i;
		}
	}
}
