#pragma once
#include "HelperTypes.h"

class ConsolePrinter
{
public:
	void showOutRangeMessage();
	void greetings() const;
	void userRangeChoice(int) const;
	void printHint(HintDistanceHelper, bool) const;
	void boringChoice() const;
	void eagerChoice() const;
	void eagerPlayer() const;
	void enterMinMax() const;
	void giveUp() const;
	void enterGuess() const;
	void startGame() const;
	void bravo(int, int) const;

private:
	void printOutRangeMessage() const;
	void incrementOutRangeCounter();

	size_t m_countOfRange{ 0 };
};
