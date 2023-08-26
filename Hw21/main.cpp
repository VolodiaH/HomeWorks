#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <string>
#include <set>

size_t uniqueWordsCount(const std::string &line);
std::string mostOccurredWord(const std::string &line);
bool bracketsOk(const std::string &line);

int main()
{
    std::cout << "Unique words: " << uniqueWordsCount("Hello Hey Hello Bye Hey") << '\n';
    std::cout << "Most occurred word: " << mostOccurredWord("Hello Hey Hey Hey Hello Bye Hey Hello") << '\n';
    std::cout << "Brackets result: " << bracketsOk("(({()}))([]{})[]{}") << '\n';
    std::cout << "Brackets result: " << bracketsOk("(({()}))([]}{{})[]{}") << '\n';
}

std::vector<std::string> split(std::string &str, const std::string &delimiter);

size_t uniqueWordsCount(const std::string &line)
{
    auto tmp{ line };
    const auto words{ split(tmp, " ") };

    const std::set<std::string, std::less<>> uniqueLines(words.begin(), words.end());
    return uniqueLines.size();
}

std::string mostOccurredWord(const std::string &line)
{
    auto tmp{ line };
    const auto words{ split(tmp, " ") };

    std::map<std::string, int, std::less<>> mapWords;

    for (auto &word : words)
        ++mapWords[word];

    const auto it{ std::ranges::max_element(mapWords, [](auto &left, auto &right) { return left.second < right.second; }) };
    if (it != mapWords.end())
        return it->first;

    return "";
}

std::vector<std::string> split(std::string &str, const std::string &delimiter)
{
    std::vector<std::string> res;

    size_t pos{};
    while ((pos = str.find(delimiter)) != std::string::npos) {
        res.emplace_back(str.substr(0, pos));
        str.erase(0, pos + delimiter.length());
    }

    if (!str.empty())
        res.emplace_back(str);

    return res;
}

bool handleEmptyBrackets(std::stack<char> &brackets, const char ch);
bool handleNonEmptyBrackets(std::stack<char> &brackets, const char ch);

bool bracketsOk(const std::string &line)
{
    std::stack<char> brackets;
    for (const char ch : line)
    {
        bool ok{ true };
        if (brackets.empty())
            ok = handleEmptyBrackets(brackets, ch);
        else
            ok = handleNonEmptyBrackets(brackets, ch);

        if (!ok)
            break;
    }

    if (brackets.empty())
        return true;

    return false;
}

bool handleEmptyBrackets(std::stack<char> &brackets, const char ch)
{
    if (ch == '(' || ch == '{' || ch == '[')
        brackets.push(ch);
    else
        return false;

    return true;
}

bool handleNonEmptyBrackets(std::stack<char> &brackets, const char ch)
{
    const char top{ brackets.top() };

    if (ch == '(' || ch == '{' || ch == '[')
        brackets.push(ch);
    else if (top == '(' && ch == ')' ||
        top == '{' && ch == '}' ||
        top == '[' && ch == ']')
        brackets.pop();
    else
        return false;

    return true;
}