#include "GameFileWork.h"

#include <fstream>
#include <iostream>
#include <chrono>

namespace ch = std::chrono;

GameFileWork &GameFileWork::instance()
{
    static GameFileWork gfw;
    return gfw;
}

std::tuple<int, unsigned, unsigned> GameFileWork::getCurrentDate() const
{
    const ch::time_point now{ ch::system_clock::now() };

    const ch::year_month_day ymd{ ch::floor<ch::days>(now) };

    int year = static_cast<int>(ymd.year());
    auto month = static_cast<unsigned>(ymd.month());
    auto day = static_cast<unsigned>(ymd.day());

    return std::make_tuple(year, month, day);
}

void GameFileWork::makeImpossibleWordOfDay() const
{
    auto [year, month, day] = getCurrentDate();

    std::ofstream file("wordOfDay.txt", std::ios::trunc);
    if (file)
    {
        file << year;
        file << "\n";
        file << month;
        file << "\n";
        file << day;
    }
}

bool GameFileWork::isPossibleWordOfDay() const
{
    if (std::ifstream file("wordOfDay.txt"); file)
    {
        auto [year, month, day] = getCurrentDate();

        int fileYear{};
        unsigned fileMonth{};
        unsigned fileDay{};

        file >> fileYear;
        file >> fileMonth;
        file >> fileDay;

        if (fileYear == year && fileMonth == month && fileDay == day)
            return false;
    }
    return true;
}

std::vector<std::string> GameFileWork::loadWords() const
{
    std::vector<std::string> words;
    std::ifstream file("words.txt");
    if (file)
    {
        std::string word;
        while (!file.eof())
        {
            file >> word;
            words.push_back(word);
        }
    }
    
    return words;
}
