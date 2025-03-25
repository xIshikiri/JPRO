#pragma once
#include <string>

class Character;

class Item
{
public:
	Item();
	Item(std::string name, int weight);
	virtual ~Item();

	std::string getName();
	void setName(std::string name);

	int getWeight();
	void setWeight();

	virtual void Use(Character* User);
	virtual void Use(Character* User, Character* target);
private:
	std::string name;
	int weight;
};

