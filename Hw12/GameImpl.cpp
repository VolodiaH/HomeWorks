#include "GameImpl.h"

std::vector<SymbolMatch> GameImpl::compare2Strings(const std::string &secretWord, const std::string &guess) const
{
    const size_t size = std::max(secretWord.length(), guess.length());

    std::vector<SymbolMatch> fullMatch(size, SymbolMatch::NoMatch);
    for (size_t i{}; i < secretWord.length() && i < guess.length(); ++i)
    {
        if (secretWord[i] == guess[i])
            fullMatch[i] = SymbolMatch::FullMatch;
    }

    for (size_t i{}; i < secretWord.length(); ++i)
    {
        if (fullMatch[i] == SymbolMatch::NoMatch)
            PrcoceedSymbol(fullMatch, guess, secretWord[i]);
    }
    return fullMatch;
}

void GameImpl::proceedSymbol(std::vector<SymbolMatch> &match, const std::string &guess, char symbol) const
{
    for (size_t i{}; i < guess.length(); ++i)
    {
        if (match[i] == SymbolMatch::NoMatch && guess[i] == symbol)
            match[i] = SymbolMatch::OtherPosition;
    }
}

