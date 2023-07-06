#include "Randomizer.h"
#include <random>
int Randomizer::getRandomValue(int min, int max)
{
	static std::random_device generator;
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(generator);
}
