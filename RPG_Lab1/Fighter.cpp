#include "Fighter.h"


Fighter::Fighter(string n, int HP, int str, int sp, int mag)
{
	name = n;
	maximumHP = HP;
	currentHP = HP;
	strength = str;
	speed = sp;
	magic = mag;
}


Fighter::~Fighter(void)
{
}

string Fighter::getName() 
{
	return name;
}

int Fighter::getMaximumHP()
{
	return maximumHP;
}

int Fighter::getCurrentHP()
{
	return currentHP;
}

int Fighter::getStrength()
{
	return strength;
}

int Fighter::getSpeed()
{
	return speed;
}

int Fighter::getMagic()
{
	return magic;
}

void Fighter::takeDamage(int damage)
{
	if (damage - (speed/4) > 0)
	{
		currentHP = currentHP - (damage - (speed/4));
	}
	else
	{
		currentHP -= 1;
	}
}

void Fighter::reset()
{
	currentHP = maximumHP;
}

void Fighter::regenerate()
{
	if (strength/6 >= 1)
	{
		currentHP += strength/6;
	}
	else 
	{
		currentHP += 1;
	}
	if (currentHP > maximumHP)
	{
		currentHP = maximumHP;
	}
}

