
#include "MyAlgorithm.h"

#include <random>

std::vector<std::string> algorithm::split(std::string &str, const std::string &delimiter)
{
    std::vector<std::string> res;

    size_t pos = 0;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        res.emplace_back(str.substr(0, pos));
        str.erase(0, pos + delimiter.length());
    }

    if (!str.empty())
        res.emplace_back(str);

    return res;
}

int algorithm::randomNumber(int min, int max)
{
    static std::random_device generator;
    std::uniform_int_distribution distribution(min, max);
    return distribution(generator);
}

