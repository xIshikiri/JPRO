// JPRO.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Character.h"
#include <thread>
#include <stdlib.h>
#include <time.h>

Weapon weapons[] = {Weapon("Sword", 3, 5), Weapon("Axe", 5, 7), Weapon("Bow", 2, 3)};

int main()
{
	srand(time(NULL));
    Character character = Character("Player", 50, 3, 12, 18, weapons[rand() % 3]);
    Character enemy = Character("Enemy", 50, 2, 13, 14, weapons[rand() % 3]);
    while (true) {
		character.attack(&enemy);
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        system("cls");
        if (enemy.health <= 0) {
            printf("You win!\n");
            return 1;
        }
		enemy.attack(&character);
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        system("cls");
		if (character.health <= 0) {
			printf("You lose!\n");
			return 1;
		}

    }
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
