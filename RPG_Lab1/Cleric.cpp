#include "Cleric.h"


Cleric::Cleric(string n, int HP, int str, int sp, int mag):Fighter(n, HP, str, sp, mag)
{
	maxMana = mag*5;
	currentMana = maxMana;
}


Cleric::~Cleric(void)
{
}

bool Cleric::useAbility()
{
	if (currentMana >= CLERIC_ABILITY_COST)
	{
		if (magic >= 3)
		{
			currentHP += (magic/3);
			if(currentHP > maximumHP)
			{
				currentHP = maximumHP;
			}
		}
		else
		{
			currentHP += 1;
			if(currentHP > maximumHP)
			{
				currentHP = maximumHP;
			}
		}
		currentMana -= CLERIC_ABILITY_COST;
		return true;
	}
	else
	{
		return false;
	}
}

void Cleric::reset()
{
	currentHP = maximumHP;
	currentMana = maxMana;
}

void Cleric::regenerate()
{
	Fighter::regenerate();
	if (magic/5 >= 1)
	{
		currentMana += magic/5;
	}
	else 
	{
		currentMana += 1;
	}
	if (currentMana > maxMana)
	{
		currentMana = maxMana;
	}
}

int Cleric::getDamage()
{
	return magic;
}
