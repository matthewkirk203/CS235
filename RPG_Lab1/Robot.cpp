#include "Robot.h"
#include <math.h>

Robot::Robot(string n, int HP, int str, int sp, int mag):Fighter(n, HP, str, sp, mag)
{
	maxEnergy = mag*2;
	currentEnergy = maxEnergy;
	bonusDamage = 0;
}


Robot::~Robot(void)
{
}

bool Robot::useAbility()
{
	bonusDamage = 0;
	if (currentEnergy >= ROBOT_ABILITY_COST)
	{
		bonusDamage = (strength*1.0  * (pow((currentEnergy*1.0/maxEnergy),4.0)));
		currentEnergy -= ROBOT_ABILITY_COST;
		return true;
	}
	else
	{
		return false;
	}
}

void Robot::reset()
{
	currentHP = maximumHP;
	currentEnergy = maxEnergy;
}

int Robot::getDamage()
{
	return strength + bonusDamage;
}