#pragma once
#include "Item.h"
class Weapon : public Item
{
public:
	Weapon();
	Weapon(std::string name, int weight, int damage);
	int damage;
};

