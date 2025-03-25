#include "Item.h"
#include "Character.h"

Item::Item() : name("Item"), weight(1)
{
}

Item::Item(std::string name, int weight) :
	name(name), weight(weight)
{
}

Item::~Item()
{
}

std::string Item::getName()
{
	return name;
}

void Item::setName(std::string name)
{
	this->name = name;
}

int Item::getWeight()
{
	return weight;
}

void Item::setWeight()
{
	this->weight = weight;
}

void Item::Use(Character* User)
{
	printf("Used %s\n", this->name.c_str());
}

void Item::Use(Character* User, Character* target)
{
	printf("Used %s\n", this->name.c_str());
}