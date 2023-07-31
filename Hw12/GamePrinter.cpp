#include "GamePrinter.h"

#include <iostream>

void GamePrinter::wordOfDayWarning() const
{
	std::cout << "Already found! Come back tommorow\n";
}

void GamePrinter::exit() const
{
	std::cout << "It's great that you are a person of focus, commitment, sheer will, and know when to stop!p!\n";
}

void GamePrinter::showResult(const std::vector<SymbolMatch> &result, const std::string &secretWord, const std::string &guess) const
{
	std::cout << "RESULT:  ";
    for (size_t i{}; i < secretWord.length(); ++i)
    {
        if (result[i] == SymbolMatch::FullMatch)
            std::cout << static_cast<char>(std::toupper(secretWord[i]));
        else if (result[i] == SymbolMatch::OtherPosition)
            std::cout << static_cast<char>(std::tolower(guess[i]));
        else
            std::cout << "*";
    }
	std::cout << "\n";
}

void GamePrinter::congrats() const
{
    std::cout << "That's right!\n";
}

void GamePrinter::showCountOfFails(size_t count) const
{
    std::cout << "You made " << count << " tries\n";
}

void GamePrinter::showBestScoreForSession(size_t count) const
{
    if (count)
        std::cout << "Your best score is " << count << " for this session\n";
    else
        std::cout << "Great job! You have a game with a perfect shot!\n";
}

void GamePrinter::greatCongratsCh() const
{
    std::cout << "You did it, cool!\n"
        << "We do not save statistics for using cheats\n";
}

void GamePrinter::joke() const
{
    std::cout << "For someone it's book, movie, game.\n"
        <<"I remember it as it was yesterday, Detroit, Sarif Industries, and that bloody lift!\n";
}

void GamePrinter::badFile() const
{
	std::court << "Bad File!\n";
}
