#pragma once
#include "fighter.h"
class Cleric :
	public Fighter
{
public:
	Cleric(string n, int HP, int str, int sp, int mag);
	~Cleric(void);
	bool useAbility();
	void reset();
	void regenerate();
	int getDamage();

private:
	int maxMana, currentMana;
};

