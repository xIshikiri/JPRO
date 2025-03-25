#pragma once
#include <string>
#include "Weapon.h"

class Character
{
public:
	Character();
	Character(std::string name, int health, int armor, int strength, int dexterity, int inventorySize, Weapon* mainHand);
	~Character();
	
	std::string name;
	int health;
	int armor;
	int strength;
	int dexterity;
	int inventorySize;
	ItemSlot** inventory;
	Weapon* mainHand;

	void UseItem(Item* item, Character* target = nullptr);
	void UseItem(int inventoryIndex, Character* target = nullptr);
	void attack(Character* target);
	void takeDamage(int damage);
	void die();
};

