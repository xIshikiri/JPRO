#pragma once
#include "EquippableItem.h"

class Weapon : public EquippableItem
{
public:
	Weapon();
	Weapon(std::string name, int weight, int damage);

	int getDamage();
	void setDamage(int damage);

	// Equip the weapon
	virtual void Use(Character* User) override;

	// Attack the target without equipping the weapon
	// Only deals weapon damage without additional modifiers/effects
	virtual void Use(Character* User, Character* target) override;

private:

	// Damage dealt by this weapon
	int damage;
};

