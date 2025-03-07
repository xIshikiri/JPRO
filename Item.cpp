#include "Item.h"

Item::Item()
{
	this->name = "Item";
	this->weight = 1;
}

Item::Item(std::string name, int weight)
{
	this->name = name;
	this->weight = weight;
}
