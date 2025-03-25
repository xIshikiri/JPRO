#include "Character.h"

#include <algorithm>
#include "Weapon.h"

Character::Character() : name("Character"), health(1), armor(1), strength(1), dexterity(1), inventorySize(10), mainHand(new Weapon("Fist", 0, 5))
{
	printf("Character::Character()\n");
	inventory = new ItemSlot*[inventorySize];
	for (int i = 0; i < inventorySize; ++i)
	{
		inventory[i] = new ItemSlot();
	}
}

Character::Character(std::string name, int health, int armor, int strength, int dexterity, int inventorySize, Weapon* mainHand) : 
	name(name), health(health), armor(armor), strength(strength), dexterity(dexterity), inventorySize(inventorySize), mainHand(mainHand)
{
	printf("Character::Character()\n");
	inventory = new ItemSlot*[inventorySize];
	for (int i = 0; i < inventorySize; ++i)
	{
		inventory[i] = new ItemSlot();
	}
}

Character::~Character()
{
	for (int i = 0; i < inventorySize; ++i)
	{
		delete inventory[i];
	}
	delete[] inventory;
	printf("%s object destroyed.\n", name.c_str());
}

void Character::takeDamage(int damage)
{
	int damageTaken = damage - armor;
	damageTaken = std::max(damageTaken, 0);
	health = health - damageTaken;
	printf("%s took %d damage!\n", name.c_str(), damageTaken);
	if (health < 0) {
		die();
	}
	else {
		printf("%s currently has %d health!\n", name.c_str(), health);
	}
}

void Character::die()
{
	printf("%s is dead!\n", name.c_str());
	delete this;
}

void Character::UseItem(Item* item, Character* target)
{
	if (target == nullptr)
	{
		item->Use(this);
		return;
	}
	item->Use(this, target);
}

void Character::UseItem(int inventoryIndex, Character* target)
{
	if (inventoryIndex >= inventorySize || inventoryIndex < 0)
	{
		printf("Invalid inventory index!");
		return;
	}
	UseItem(inventory[inventoryIndex]->item, target);
}

void Character::attack(Character* target)
{
	printf("%s attacks %s using %s!\n", name.c_str(), target->name.c_str(), mainHand->getName().c_str());
	int attackRoll = rand() % 20 + 1;
	int attackScore = attackRoll + (dexterity / 2) - 5;
	bool hit = attackScore > 10 + target->armor;
	printf("Attack rolled %d\n", attackRoll);
	printf("Attack score is %d\n", attackScore);
	int damage = mainHand->getDamage() + (strength / 2) - 5;
	if (hit)
	{
		if (attackRoll == 20)
		{
			printf("%s HITS A CRITICAL!!!!\n", name.c_str());
			target->takeDamage(damage * 2);
		}
		else
		{
			target->takeDamage(damage);
		}
	}
	else
	{
		printf("%s missed!\n", name.c_str());
	}

}
