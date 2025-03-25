// JPRO.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Character.h"
#include <thread>
#include <stdlib.h>
#include <time.h>

Weapon* weapons[] = {new Weapon("Sword", 3, 5), new Weapon("Axe", 5, 7), new Weapon("Bow", 2, 3)};

int main()
{
    srand(time(NULL));
    Character* character = new Character("Player", 10, 1, 14, 12, 10, weapons[rand() % 3]);
    Character* enemy = new Character("Enemy", 10, 1, 14, 10, 10, weapons[rand() % 3]);
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
                printf("You win!\n");
                delete enemy;
                return 1;
            }
            break;
        case 'i':
            character->inventory[0] = new ItemSlot(weapons[0]);
            for (int i = 0; i < character->inventorySize; ++i) {
                if (character->inventory[i] != nullptr &&  character->inventory[i]->item != nullptr) {
                    printf("%s\n", character->inventory[i]->item->getName().c_str());
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
            return 1;
        }
    }
}