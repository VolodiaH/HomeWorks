#include <iostream>

#include <future>
#include <algorithm>
#include <array>
#include <format>
#include <numeric>
#include <vector>
#include <random>
#include <chrono>
#include <execution>

using namespace std::chrono;
//TODO: in future rework - only one vector, but it will be passed into functions with range, like measureTime(v, forHardwareConcurrency, begin, size, ...) long long forHardwareConcurrency(begin, size) 
constexpr size_t StartSize { 10000 };
constexpr size_t Multiplicator { 10 };
constexpr size_t VectorCount { 5 };

constexpr int MinValue {-1000};
constexpr int MaxValue {1000};

void fillRandomNumbers(std::vector<int> &vec)
{
    std::random_device rnd_device;
    std::mt19937 mersenne_engine{ rnd_device() }; 
    std::uniform_int_distribution dist{ MinValue, MaxValue };

    auto gen = [&dist, &mersenne_engine]() {
        return dist(mersenne_engine);
    };

    std::ranges::generate(vec, gen);
}

long long forSingleThread(const std::vector<int> &vec)
{
    return std::reduce(vec.begin(), vec.end());
}

long long forTwoThreads(const std::vector<int> &vec)
{
    auto f1 = std::async(std::launch::async, [&vec] {return std::reduce(vec.begin(), vec.begin() + vec.size() / 2, 0); });
    auto f2 = std::async(std::launch::async, [&vec] {return std::reduce(vec.begin() + vec.size() / 2, vec.end(), 0); });
    return f1.get() + f2.get();
}

long long forTwoThreadsNoLambda(const std::vector<int> &vec)
{
    auto f1 = std::async(std::launch::async, std::reduce<const std::vector<int>::const_iterator>, vec.begin(), vec.begin() + vec.size() / 2);
    auto f2 = std::async(std::launch::async, std::reduce<const std::vector<int>::const_iterator>, vec.begin() + vec.size() / 2, vec.end());
    return f1.get() + f2.get();
}

long long toSum(const std::vector<int>::const_iterator &begin, const std::vector<int>::const_iterator &end) 
{
    return std::reduce( begin, end);
}

long long forTwoThreadsFunc(const std::vector<int> &vec)
{
    auto f1 = std::async(std::launch::async, toSum, vec.begin(), vec.begin() + vec.size() / 2);
    auto f2 = std::async(std::launch::async, toSum, vec.begin() + vec.size() / 2, vec.end());
    return f1.get() + f2.get();
}

long long forTwoThreadsNoLambdaPar(const std::vector<int> &vec)
{
    auto f1 = std::async(std::launch::async, std::reduce<std::execution::parallel_policy const &, std::vector<int>::const_iterator, int, std::plus<int>>, std::execution::par, vec.begin(), vec.begin() + vec.size() / 2, 0ll, std::plus<int>());
    auto f2 = std::async(std::launch::async, std::reduce<std::execution::parallel_policy const &, std::vector<int>::const_iterator, int, std::plus<int>>, std::execution::par, vec.begin() + vec.size() / 2, vec.end(), 0ll, std::plus<int>());
    return f1.get() + f2.get();
}

long long forTwoThreadsPar(const std::vector<int> &vec)
{
    auto f1 = std::async(std::launch::async, [&vec] {return std::reduce(std::execution::par ,vec.begin(), vec.begin() + vec.size() / 2, 0ll); });
    auto f2 = std::async(std::launch::async, [&vec] {return std::reduce(std::execution::par, vec.begin() + vec.size() / 2, vec.end(), 0ll); });
    return f1.get() + f2.get();
}

long long forHardwareConcurrency(const std::vector<int> &vec)
{
    const size_t threads{ std::thread::hardware_concurrency() };
    const size_t step = vec.size() / threads;

    std::vector<std::future<long long>> futures;

    for (size_t i{}, currValue{}; i < threads; ++i, currValue += step)
        futures.emplace_back(std::async(std::launch::async, toSum, vec.begin() + currValue, vec.begin() + currValue + step));

    long long res{};

    for(auto &f : futures)
        res += f.get();

    return res;
}

long long forDoubleHardwareConcurrency(const std::vector<int> &vec)
{
    const size_t threads{ std::thread::hardware_concurrency() * 2};
    const size_t step = vec.size() / threads;

    std::vector<std::future<long long>> futures;

    for (size_t i{}, size{}; i < threads; ++i, size += step)
        futures.emplace_back(std::async(std::launch::async, toSum, vec.begin() + size, vec.begin() + size + step));

    long long res{};

    for (auto &f : futures)
        res += f.get();

    return res;
}

template <typename Func>
void measureTime(const std::vector<int> &vec, Func function, const std::string &threadDetails, const std::string &details)
{
    const auto start = high_resolution_clock::now();
    auto sum = function(vec);
    const auto stop = high_resolution_clock::now();
    const auto duration = duration_cast<microseconds>(stop - start);
    std::cout << std::format("Time for {} with {}: {} microseconds for size: {}, sum:{}\n", threadDetails, details, duration.count(), vec.size(), sum);
}

int main()
{
    std::array<std::vector<int>, VectorCount> collections;

    for(size_t i{}, size { StartSize }; i < collections.size(); ++i, size *= Multiplicator)
        collections[i].resize(size);

    for (auto &v : collections)
        fillRandomNumbers(v);

    for (auto &v : collections)
        measureTime(v, forSingleThread, "single thread", "");

    std::cout << '\n';

    for (auto &v : collections)
        measureTime(v, forTwoThreads, "2 threads", "Lambda");

    std::cout << '\n';

    for (auto &v : collections)
        measureTime(v, forTwoThreadsNoLambda, "2 threads", "No Lambda");

    std::cout << '\n';

    for (auto &v : collections)
        measureTime(v, forTwoThreadsPar, "2 threads", "with std::execution::par and lambda");

    std::cout << '\n';

    for (auto &v : collections)
        measureTime(v, forTwoThreadsNoLambdaPar, "2 threads", "No Lambda std::execution::par ");

    std::cout << '\n';

    for (auto &v : collections)
        measureTime(v, forTwoThreadsFunc, "2 threads", "other Function std::execution::par ");

    std::cout << '\n';
    
    for (auto &v : collections)
        measureTime(v, forHardwareConcurrency, std::to_string(std::thread::hardware_concurrency()) + " threads", "");

    std::cout << '\n';

    for (auto &v : collections)
        measureTime(v, forDoubleHardwareConcurrency, std::to_string(std::thread::hardware_concurrency() * 2) + " threads", "");
}


