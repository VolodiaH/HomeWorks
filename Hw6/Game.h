#pragma once
#include <string>
#include <limits>

#include "HelperTypes.h"
#include "ConsolePrinter.h"

class Game
{
public:
	void start();

private:
	std::pair<HintDistanceHelper, bool> calculateDistanceOfGuess(int, int, int) const;

	void enterValueRange();
	void prepareMinMax();
	bool handleGuess(int input, int secretValue);

	const int m_defaultMaxValue{ 50 };

	int m_minValue{ -m_defaultMaxValue };
	int m_maxValue{ m_defaultMaxValue };

	int m_countFails{ 0 };
	int m_highScore{ std::numeric_limits<int>::max() };

	ConsolePrinter m_printer;
};
