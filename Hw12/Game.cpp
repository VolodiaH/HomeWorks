#include "Game.h"
#include "GameMenu.h"
#include "Randomizer.h"
#include "GamePrinter.h"

#include <algorithm>
#include <iostream>

const std::string Cheat = "HESOYAM";
const std::string Joke = "0451";

void toUpperCase(std::string &str)
{
    std::ranges::transform(str.begin(), str.end(), str.begin(), ::toupper);
}

void Game::startGame() 
{
    if (m_words.empty())
    {
        m_printer.badFile();
        std::exit(-1);
    }
    
    size_t countFails{};
    
    while (true)
    {
        if(m_bestScore != std::numeric_limits<size_t>::max())
            m_printer.showBestScoreForSession(m_bestScore);

        GameMenu menu;
        auto choice = menu.showMenuGetChoice();

        if (choice == GameMode::WordOfDay) 
        {
            if (GameFileWork::instance().isPossibleWordOfDay())
                m_wordOfDay = true;
            else
            {
                m_printer.wordOfDayWarning();
                continue;
            }
        }
        else if(choice == GameMode::Exit)
        {
            m_printer.exit();
            return;
        }

        std::string secretWord = getRandomWord();
        toUpperCase(secretWord);

        handleGuess(secretWord, countFails);
        
        countFails = 0;
    }
}

std::string Game::getRandomWord() 
{
    return m_words[ Randomizer::getRandomValue(0, m_words.size() - 1) ];
}

void Game::handleGuess(const std::string &secretWord, size_t &countFails)
{
    while (true)
    {
        std::cout << "ENTER:  ";
        std::string guess;
        std::cin >> guess;
        toUpperCase(guess);

        if (guess == secretWord)
        {
            m_printer.congrats();
            if(countFails)
                m_printer.showCountOfFails(countFails);

            if (m_wordOfDay)
            {
                GameFileWork::instance().makeImpossibleWordOfDay();
                m_wordOfDay = false;
            }
            m_bestScore = std::min(m_bestScore, countFails);
            return;
        }
        else if (guess == Cheat)
        {
            m_printer.greatCongratsCh();
            return;
        }
        else if (guess == Joke)
        {
            m_printer.joke();
            return;
        }
        else
        {
            auto result = m_gameImp.compare2Strings(secretWord, guess);
            m_printer.showResult(result, secretWord, guess);
            ++countFails;
        }

    }
}
