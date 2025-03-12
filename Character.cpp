#include "Character.h"

Character::Character()
{
	this->name = "Character";
	this->health = 1;
	this->armor = 1;
	this->mainHand = Weapon("Fist", 0, 5);
	for (int i = 0; i < 10; i++) {
		this->inventory[i] = new Item("Empty", 0);
	}
}

Character::Character(std::string name, int health, int armor, int strength, int dexterity)
{
	this->name = name;
	this->health = health;
	this->armor = armor;
	this->strength = strength;
	this->dexterity = dexterity;
	this->mainHand = Weapon("Fist", 0, 5);
	for (int i = 0; i < 10; i++) {
		this->inventory[i] = new Item("Empty", 0);
	}
}

Character::Character(std::string name, int health, int armor, int strength, int dexterity, Weapon mainHand)
{
	this->name = name;
	this->health = health;
	this->armor = armor;
	this->strength = strength;
	this->dexterity = dexterity;
	this->mainHand = mainHand;
	for (int i = 0; i < 10; i++) {
		this->inventory[i] = new Item("Empty", 0);
	}
}



void Character::takeDamage(int damage)
{
	int damageTaken = damage - armor;
	if (damageTaken < 0) {
		damageTaken = 0;
	}
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
}

void Character::attack(Character* target)
{
	printf("%s attacks %s using %s!\n", name.c_str(), target->name.c_str(), mainHand.name.c_str());
	int attackRoll = rand() % 20 + 1;
	int attackScore = attackRoll + (dexterity / 2) - 5;
	bool hit = attackScore > 10 + target->armor;
	printf("Attack rolled %d\n", attackRoll);
	printf("Attack score is %d\n", attackScore);
	int damage = mainHand.damage + (strength / 2) - 5;
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
