#include <iostream>
#include "Character.h"
#include <thread>
#include <stdlib.h>
#include <time.h>

Weapon* createWeapon()
{
    static const std::string names[] = {"Sword", "Axe", "Bow"};
    return new Weapon(names[rand() % 3], rand() % 3 + 1, rand() % 9 + 3);
}

int main()
{
    srand(time(NULL));
    Character* character = new Character("Player", 10, 1, 36, 12, 10, createWeapon());
    Character* enemy = new Character("Enemy", 10, 1, 14, 10, 10, createWeapon());
    while (true) {
        char d;
        std::cout << "Co chcesz zrobic?" << "\n";
        std::cout << "a - atakuj" << "\n";
        std::cout << "i - uzyj przedmiotu" << "\n";
        std::cout << "cokolwiek innego - pomin ture" << "\n";
        std::cin >> d;
        system("cls");
        switch (d)
        {
        case 'a':
            character->attack(enemy);
            std::this_thread::sleep_for(std::chrono::milliseconds(3000));
            if (enemy->health <= 0) {
                system("cls");
                delete enemy;
                delete character;
                printf("You win!\n");
                return 1;
            }
            break;
        case 'i':
            character->inventory[0] = new ItemSlot(createWeapon());
            character->inventory[1] = new ItemSlot(new Item("Potion", 1));
            for (int i = 0; i < character->inventorySize; ++i) {
                if (character->inventory[i] != nullptr &&  character->inventory[i]->item != nullptr) {
                    Item* item = character->inventory[i]->item;
                    printf("%d: %s - weight: %d ", i, item->getName().c_str(), item->getWeight());
                    if (dynamic_cast<Weapon*>(item) != nullptr) {
                        printf("damage: %d\n", dynamic_cast<Weapon*>(item)->getDamage());
                    }
                    else {
                        printf("\n");
                    }
                }
            }
            int x;
            std::cin >> x;
            character->UseItem(x);
            std::this_thread::sleep_for(std::chrono::milliseconds(3000));
            break;
        default:
            printf("%s did nothing. Really?\n", character->name.c_str());
            std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        }
        system("cls");
        enemy->attack(character);
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        system("cls");
        if (character->health <= 0) {
            printf("You lose!\n");
            delete character;
            delete enemy;
            return 1;
        }
    }
}