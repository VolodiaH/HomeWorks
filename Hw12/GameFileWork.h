#pragma once

#include <tuple>
#include <vector>
#include <string>

class GameFileWork
{
public:	
	static GameFileWork &instance();

	void makeImpossibleWordOfDay() const;
	bool isPossibleWordOfDay() const;
	std::vector<std::string> loadWords() const;
private:

	GameFileWork() = default;
	std::tuple<int, unsigned, unsigned> getCurrentDate() const;
};

