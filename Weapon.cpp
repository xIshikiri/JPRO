#include "Weapon.h"

Weapon::Weapon()
{
	this->name = "Weapon";
	this->weight = 1;
	this->damage = 1;
}

Weapon::Weapon(std::string name, int weight, int damage)
{
	this->name = name;
	this->weight = weight;
	this->damage = damage;
}

void Weapon::Use()
{
	printf("Equipped %s\n", this->name.c_str());
}
