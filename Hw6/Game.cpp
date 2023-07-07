#include "Game.h"
#include <iostream>
#include "Randomizer.h"

Game::Game() :
	m_countFails(0),
	m_highScore(std::numeric_limits<int>::max())
{
}

void Game::start() 
{
	m_printer.greetings();
	m_printer.userRangeChoice(m_defaultMaxValue);

	prepareMinMax();

	while (true)
	{
		const int secretValue = Randomizer::getRandomValue(m_minValue, m_maxValue);

		m_printer.startGame();

		m_countFails = 0;

		for (; true; ++m_countFails)
		{
			m_printer.enterGuess();

			int guess{};
			std::cin >> guess;

			if (!std::cin.good())
			{
				m_printer.giveUp();
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return;
			}

			if (handleGuess(guess, secretValue))
				break;
		}
	}
}

void Game::enterValueRange()
{
	int min{ 1 }, max{ 0 };
	while (min >= max)
	{
		m_printer.enterMinMax();
		std::cin >> min >> max;
	}
	
	m_minValue = min;
	m_maxValue = max;

}

std::pair<HintDistanceHelper, bool> Game::calculateDistanceOfGuess(int guess, int secretValue, int distance)
{
	const int posDelta = std::abs(guess - secretValue);

	const int percents40{ distance / 40 };
	const int percents20{ distance / 20 };

	HintDistanceHelper hint;
	if (percents40 < posDelta && posDelta <= distance)
		hint = HintDistanceHelper::BigDistance;
	else if (percents20 <= posDelta && posDelta < percents40)
		hint = HintDistanceHelper::AveregeDistance;
	else
		hint = HintDistanceHelper::CloseDistance;

	return std::make_pair(hint, (guess > secretValue));
}

void Game::prepareMinMax()
{
	int userValueChoice{};
	std::cin >> userValueChoice;

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	ValueChoice choice = static_cast<ValueChoice>(userValueChoice);
	if (choice == ValueChoice::Custom)
		enterValueRange();
	else if (choice == ValueChoice::Default)
		m_printer.boringChoice();
	else
	{
		m_printer.eagerChoice();
		int min{ 1 }, max{ 0 };
		while (min >= max)
		{
			min = Randomizer::getRandomValue(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
			max = Randomizer::getRandomValue(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

			if (min > max)
				std::swap(min, max);

		}
		m_minValue = min;
		m_maxValue = max;
	}
}

bool Game::handleGuess(int guess, int secretValue)
{
	if (guess == secretValue)
	{
		m_printer.bravo(m_countFails, m_highScore);

		if (m_countFails < m_highScore)
			m_highScore = m_countFails;

		return true;
	}

	if (m_minValue <= guess && guess <= m_maxValue)
	{
		auto [hint, lower] = calculateDistanceOfGuess(guess, secretValue, m_maxValue - m_minValue);
		m_printer.printHint(hint, lower);
		if (m_countFails & 1)
			m_printer.eagerPlayer();
	}
	else
		m_printer.showOutRangeMessage();

	return false;
}
