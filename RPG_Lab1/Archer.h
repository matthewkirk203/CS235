#pragma once
#include "fighter.h"
class Archer :
	public Fighter
{
public:
	Archer(string n, int HP, int str, int sp, int mag);
	~Archer(void);
	bool useAbility();
	void reset();
	int getDamage();
	int getSpeed();
	void takeDamage(int damage);
private:
	int currentSpeed;
};

