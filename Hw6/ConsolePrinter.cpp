#include "ConsolePrinter.h"
#include <vector>
#include <iostream>
#include <format>

static const std::vector<std::string> Madness = { "Let me tell you buddy! You're out of range!",
"Are those masks? Are we in the jungle?",
"Most people hate long lines",
"Did I ever tell you what the definition of insanity is?",
"Insanity is doing the exact... same damn thing... over and over again expecting... thing to change...",
"That. Is. Crazy." };

ConsolePrinter::ConsolePrinter() :m_countOfRange(0) {}

void ConsolePrinter::showOutRangeMessage()
{
	printOutRangeMessage();
	incrementOutRangeCounter();
}

void ConsolePrinter::printOutRangeMessage()
{
	std::cout << Madness[m_countOfRange] << "\n";
}

void ConsolePrinter::incrementOutRangeCounter()
{
	if (Madness.size() - 1 > m_countOfRange)
		++m_countOfRange;
}

void ConsolePrinter::greetings() 
{
	std::cout << "Welcome to the BIG GAME\n"
			  << "You have a chance to become billionere! HERE AND NOW!!!!\n"
			  << "Leave hope everyone who enters...\n";
}

void ConsolePrinter::userRangeChoice(int m_defaultMaxValue)
{
	std::cout << std::format("\nDou wish to use default value(from {} to {}) or custom?\n", -m_defaultMaxValue, m_defaultMaxValue)
			  << "1 - default value\n"
	          << "2 - custom value\n"
			  << "3 - House's choice\n";
}

void ConsolePrinter::printHint(HintDistanceHelper hint, bool lower)
{
	switch (hint)
	{
	case HintDistanceHelper::BigDistance:
		std::cout << "You are far away from target!\n";
		break;
	case HintDistanceHelper::AveregeDistance:
		std::cout << "You are close to target!\n";
		break;
	case HintDistanceHelper::CloseDistance:
		std::cout << "Hot damn, it's like Christmas!\n";
		break;
	}		

	std::cout << "Value is " << ((lower) ? "lower" : "higher") << '\n';
}

void ConsolePrinter::boringChoice() 
{
	std::cout << "Nothing interesting...\n";
}

void ConsolePrinter::eagerChoice() 
{
	std::cout << "You are a player, don't you? \n";
}

void ConsolePrinter::eagerPlayer()
{
	std::cout << "Wake the **** up samurai! We have the number to burn!\n";
}

void ConsolePrinter::enterMinMax()
{
	std::cout << "Enter min and max value(min should be lower than max)\n";
}

void ConsolePrinter::giveUp()
{
	std::cout << "Persons like you - are afraid of 'Souls like' games\n";
}

void ConsolePrinter::enterGuess()
{
	std::cout << "Your guess(to give up enter any thing except numbers): ";
}

void ConsolePrinter::startGame()
{
	std::cout << "\n\n### GAME STARTS!!!!###\n\n";
}

void ConsolePrinter::bravo(int countFails, int highScore)
{
	std::cout << "\nCongrats!!!\n";

	if (countFails)
		std::cout << "Current score: " << countFails << '\n';
	else
		std::cout << "You are the lightsaber, with no fails\n";

	if (highScore != std::numeric_limits<int>::max())
		std::cout << "Your best score for this session is: " << highScore << "\n";
}
