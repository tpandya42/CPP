#include "pmerge.hpp"
#include <cinttypes>
#include <utility>
#include <vector>

static std::vector<std::pair<int, int>> createPair(std::vector<int> &v)
{
	std::vector<std::pair<int, int>> pairs;
	for (size_t i = 0; i + 1 < v.size(); i+=2)
	{
		pairs.emplace_back(v[i], v[i+1]);
	}
	return pairs;
}

std::vector<int> mergeInsertSort(std::vector<int> &v)
{
	
	std::vector<std::pair<int, int>> pairs = createPair(v);
	// trying to sort this pairs
	std::vector<std::pair<int, int>>::iterator it;
	for (it = pairs.begin(); it != pairs.end(); ++it )
	{
		if (it->second > it->first)
			std::swap(it->first, it->second);
	}
	
	// making main chain and pend
	std::vector<int> main;
	std::vector<int> pend;
	for (it = pairs.begin(); it != pairs.end(); ++it)
		main.push_back(it->first);
	for (it = pairs.begin(); it != pairs.end(); ++it)
		pend.push_back(it->second);

	// moving on with insertion part (jacobsthol sequence thingy)
	
}
