
#pragma once

#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

enum class StatusDeck
{
    InUse,
    Free
};

namespace algorithm
{
    std::vector<std::string> split(std::string &str, const std::string &delimiter);
	int randomNumber(int min, int max);

    template<class T>
    T *getUnUsedItem(const std::vector<std::unique_ptr<T>> &deck, std::vector<StatusDeck> &statuses)
    {
		const auto it = std::ranges::find(statuses, StatusDeck::Free);

		if (it != statuses.end())
		{
			*it = StatusDeck::InUse;
			return deck[it - statuses.begin()].get();
		}

		return deck[algorithm::randomNumber(0, deck.size() - 1)].get();
    }

	template<class T>
	std::vector<T*> castToVectorRawPtr(std::vector<std::unique_ptr<T>> &vector)
    {
        std::vector<T*> res;
		std::ranges::transform(vector, std::back_inserter(res), [](auto &ptr){ return ptr.get(); });
		return res;
    }
}

