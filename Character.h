#pragma once
#include <string>
#include "Weapon.h"
class Character
{
public:
	Character();
	Character(std::string name, int health, int armor, int strength, int dexterity);
	Character(std::string name, int health, int armor, int strength, int dexterity, Weapon mainHand);

	std::string name;
	int health;
	int armor;
	int strength;
	int dexterity;
	Item inventory[10];
	Weapon mainHand;

	void attack(Character* target);
	void takeDamage(int damage);
	void die();
};

