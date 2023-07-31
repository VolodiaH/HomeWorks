#pragma once

#include <vector>
#include "GameImpl.h"

class GamePrinter
{
public:
	void wordOfDayWarning() const;
	void exit() const;
	void showResult(const std::vector<SymbolMatch> &result, const std::string &secretWord, const std::string &guess) const;
	void congrats() const;
	void showCountOfFails(size_t count) const;
	void showBestScoreForSession(size_t count) const;
	void greatCongratsCh() const;
	void joke() const;
	void badFile() const;
	void badSize() const;
};

