#pragma once
#include "fighter.h"
class Robot :
	public Fighter
{
public:
	Robot(string n, int HP, int str, int sp, int mag);
	~Robot(void);

	bool useAbility();
	void reset();
	int getDamage();

private:
	int maxEnergy;
	int currentEnergy;
	int bonusDamage;
};

