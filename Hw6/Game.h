#pragma once
#include <string>
#include "HelperTypes.h"
#include "ConsolePrinter.h"
class Game
{ 
public:
	Game();
	void start();

private:
	std::pair<HintDistanceHelper, bool> calculateDistanceOfGuess(int,int,int);

	void enterValueRange();
	void prepareMinMax();
	bool handleGuess(int input, int secretValue);

private:
	ConsolePrinter m_printer;
	
	const int m_defaultMaxValue{ 50 };

	int m_minValue{ -m_defaultMaxValue };
	int m_maxValue{ m_defaultMaxValue };

	int m_countFails;
	int m_highScore;
};

