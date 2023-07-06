#pragma once

#include "HelperTypes.h"

class ConsolePrinter
{
public:
	ConsolePrinter();

	void showOutRangeMessage();
	void greetings();
	void userRangeChoice(int);
	void printHint(HintDistanceHelper, bool);
	void boringChoice();
	void eagerChoice();
	void eagerPlayer();
	void enterMinMax();
	void giveUp();
	void enterGuess();
	void startGame();
	void bravo(int, int);

private:
	void printOutRangeMessage();
	void incrementOutRangeCounter();

private:
	int m_countOfRange;

};

