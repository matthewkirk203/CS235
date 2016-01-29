#include "Archer.h"


Archer::Archer(string n, int HP, int str, int sp, int mag):Fighter(n, HP, str, sp, mag)
{
	currentSpeed = speed;
}


Archer::~Archer(void)
{
}

bool Archer::useAbility()
{
	currentSpeed += 1;
	return true;
}

void Archer::reset()
{
	currentHP = maximumHP;
	currentSpeed = speed;
}

int Archer::getDamage()
{
	return currentSpeed;
}

int Archer::getSpeed()
{
	return currentSpeed;
}

void Archer::takeDamage(int damage)
{
	if (damage - (currentSpeed/4) > 0)
	{
		currentHP = currentHP - (damage - (currentSpeed/4));
	}
	else
	{
		currentHP -= 1;
	}
}