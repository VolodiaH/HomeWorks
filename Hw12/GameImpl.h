#pragma once

#include <vector>
#include <string>

enum class SymbolMatch
{
    NoMatch,
    FullMatch,
    OtherPosition,
};

class GameImpl
{
public:
    std::vector<SymbolMatch> compare2Strings(const std::string &secretWord, const std::string &guess) const;

private:
    void proceedSymbol(std::vector<SymbolMatch> &match, const std::string &guess, const char symbol) const;
};

