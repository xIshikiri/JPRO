#pragma once
#include <string>

class Item
{
public:
	Item();
	Item(std::string name, int weight);
	std::string name;
	int weight;
	virtual void Use();
};

