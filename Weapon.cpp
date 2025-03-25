#include "Weapon.h"
#include "Character.h"

Weapon::Weapon() : EquippableItem("Weapon", 1), damage(1)
{
}

Weapon::Weapon(std::string name, int weight, int damage) : 
	EquippableItem(name, weight), damage(1)
{
}

int Weapon::getDamage()
{
	return this->damage;
}

void Weapon::Use(Character* User)
{
	printf("Equipped %s\n", getName().c_str());
}

void Weapon::Use(Character* User, Character* target)
{
	User->attack(target);
}