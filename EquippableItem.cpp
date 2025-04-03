#include "EquippableItem.h"
#include <cassert>

ItemSlot::ItemSlot() : item(nullptr), type(backpack), quantity(0)
{
	printf("Created ItemSlot!\n");
}

ItemSlot::ItemSlot(Item* item, SlotType type, int quantity) : item(item), type(type), quantity(quantity)
{
}

ItemSlot::~ItemSlot()
{
	delete item;
}

Item* ItemSlot::GetItem()
{
	return item;
}

void ItemSlot::SetItem(Item* inItem)
{
	item = inItem;
}

void ItemSlot::SwapItems(ItemSlot* SlotToSwap)
{
	Item* temp = item;
	item = SlotToSwap->GetItem();
	SlotToSwap->SetItem(temp);
}

EquippableItem::EquippableItem() = default;

EquippableItem::EquippableItem(std::string name, int weight) : Item(name, weight)
{
}

void EquippableItem::Use(Character* User)
{
	printf("Equipped %s\n", getName().c_str());
}

void EquippableItem::Use(Character* User, Character* target)
{
	printf("Equipped %s on %s\n", getName().c_str());
}
