#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

unsigned int countDivisibleBy(const std::vector<int> &vec, int number)
{
    return std::ranges::count_if(vec, [number](int n)
    {
        return (n % number == 0);
    });
}

//#TODO: Find out what's wrong
std::function<std::string()> makeLambda()
{
    const std::string val = "string";
    // should take copy of val
    // val has already been destroyed, when it is called in main
    return [val] {return val; };
}

//compare strings task
bool compareByLength(const std::string &lhs, const std::string &rhs)
{
    return lhs.size() < rhs.size();
}

class StringComparator
{
public:
    bool operator()(const std::string &lhs, const std::string &rhs) const 
    {
        return lhs.size() < rhs.size();
    }
};

int main()
{
    auto bad = makeLambda();
    std::cout << bad();

    std::vector<int> v1 {40,45, 55,60,71,90,500};
    std::cout << countDivisibleBy(v1, 5);

    //compare strings task
    std::vector<std::string> stringContainer{"QWERTY", "qwerty", "qwe", "zxcaf", "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq"};

    //std::ranges::sort(stringContainer, [](auto &lhs, auto &rhs) { return lhs.size() < rhs.size(); });
    //std::ranges::sort(stringContainer, compareByLength);
    std::ranges::sort(stringContainer, StringComparator());

}
