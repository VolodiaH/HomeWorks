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
            proceedSymbol(fullMatch, guess, secretWord[i]);
    }
    return fullMatch;
}

double GameImpl::levenshteinDistance(const std::string &secretWord, const std::string &guess)
{
    const std::size_t len1 = secretWord.size();
    const std::size_t len2 = guess.size();
    std::vector<std::vector<unsigned int>> d(len1 + 1, std::vector<unsigned int>(len2 + 1));

    d[0][0] = 0;

    for (unsigned int i = 1; i <= len1; ++i)
        d[i][0] = i;

    for (unsigned int i = 1; i <= len2; ++i)
        d[0][i] = i;

    for (unsigned int i = 1; i <= len1; ++i)
        for (unsigned int j = 1; j <= len2; ++j)
            d[i][j] = std::min(std::min(d[i - 1][j] + 1, d[i][j - 1] + 1), d[i - 1][j - 1] + (secretWord[i - 1] == guess[j - 1] ? 0 : 1));

    const double result = ((len1 - d[len1][len2]) / static_cast<double>(len1)) * 100;
    return result ;

}

void GameImpl::proceedSymbol(std::vector<SymbolMatch> &match, const std::string &guess, const char symbol) const
{
    for (size_t i{}; i < guess.length(); ++i)
    {
        if (match[i] == SymbolMatch::NoMatch && guess[i] == symbol)
        {
              match[i] = SymbolMatch::OtherPosition;
              break;
        }
            
    }
}

