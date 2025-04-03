#pragma once
#include "Item.h"

enum SlotType {
	head,
	chest,
	mainHand,
	offHand,
	legs,
	feet,
	backpack
};

class EquippableItem : public Item
{
public:
	EquippableItem();
	EquippableItem(std::string name, int weight);
	
	virtual void Use(Character* User) override;
	virtual void Use(Character* User, Character* target) override;
};

class ItemSlot
{
public:
	ItemSlot();
	ItemSlot(Item* item, SlotType type = backpack, int quantity = 1);
	~ItemSlot();

	Item* GetItem();
	void SetItem(Item* Item);
	void SwapItems(ItemSlot* SlotToSwap);

private:
	Item* item;
	SlotType type;
	int quantity;
	
};