#pragma once
#include "fighterinterface.h"
class Fighter :
	public FighterInterface
{
public:
	Fighter(string n, int HP, int str, int sp, int mag);
	~Fighter(void);

	virtual string getName();
	virtual int getMaximumHP();
	virtual int getCurrentHP();
	virtual int getStrength();
	virtual int getSpeed();
	virtual int getMagic();
	virtual int getDamage() = 0;
	virtual void takeDamage(int damage);
	virtual void reset();
	virtual void regenerate();
	virtual bool useAbility() = 0;

protected:
	string name;
	int maximumHP, currentHP, strength, speed, magic; 

};

