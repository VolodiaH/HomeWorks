#pragma once

#include <vector>
#include <string>

#include "GameImpl.h"
#include "GameFileWork.h"
#include "GamePrinter.h"

class Game 
{
public:
	void startGame();

private:
	std::string getRandomWord();
	void handleGuess(const std::string &secretWord, size_t &countFails);

	std::vector<std::string> m_words = GameFileWork::instance().loadWords();
	size_t m_bestScore{ std::numeric_limits<size_t>::max() };
	bool m_wordOfDay{ false };
	GameImpl m_gameImp;
	GamePrinter m_printer;
	
};

