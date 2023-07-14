#include "Game.h"
#include "Randomizer.h"
#include <iostream>

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
				return;
			}

			if (handleGuess(guess, secretValue))
				break;
		}
	}
}

void Game::prepareMinMax()
{
	int userValueChoice{};
	std::cin >> userValueChoice;

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	auto choice = static_cast<ValueChoice>(userValueChoice);
	if (choice == ValueChoice::Custom)
		enterValueRange();
	else if (choice == ValueChoice::Default)
		m_printer.boringChoice();
	else
	{
		m_printer.eagerChoice();
		int min{ 1 };
		int max{ 0 };
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

void Game::enterValueRange()
{
	int min{ 1 };
	int max{ 0 };
	while (min >= max)
	{
		m_printer.enterMinMax();
		std::cin >> min >> max;
	}

	m_minValue = min;
	m_maxValue = max;
}

bool Game::handleGuess(int guess, int secretValue)
{
	if (guess == secretValue)
	{
		m_printer.bravo(m_countFails, m_highScore);

		m_highScore = std::min(m_countFails, m_highScore);

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

std::pair<HintDistanceHelper, bool> Game::calculateDistanceOfGuess(int guess, int secretValue, int distance) const
{
	const int posDelta = std::abs(guess - secretValue);

	const int percents40{ distance * 40 / 100 };
	const int percents20{ distance * 20 / 100 };

	HintDistanceHelper hint;
	if (percents40 < posDelta && posDelta <= distance)
		hint = HintDistanceHelper::BigDistance;
	else if (percents20 <= posDelta && posDelta < percents40)
		hint = HintDistanceHelper::AveregeDistance;
	else
		hint = HintDistanceHelper::CloseDistance;

	return std::make_pair(hint, (guess > secretValue));
}
