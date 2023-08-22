#include "GameMenu.h"
#include <iostream>

GameMode GameMenu::showMenuGetChoice() const
{
	m_printer.showMenu();

	unsigned choice{};
	std::cin >> choice;

	auto userChoice = static_cast<GameMode>(choice);
	return userChoice;
}

void GameMenuPrinter::showMenu() const
{
	std::cout << "\n1 - Wordle of the day\n"
		<< "2 - Random Wordle\n"
		<< "0 - Exit\n"
		<< "Enter: ";
}
