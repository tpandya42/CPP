#include "pmerge.hpp"
#include <cinttypes>
#include <cstddef>
#include <utility>
#include <vector>

static std::vector<std::pair<int, int>> createPair(std::vector<int> &v)
{
	std::vector<std::pair<int, int>> pairs;
	for (size_t i = 0; i + 1 < v.size(); i+=2)
	{
		pairs.push_back(std::make_pair(v[i], v[i + 1]));
	}
	return pairs;
}

static void mergePairs(std::vector<std::pair<int, int>> &pairs, int left, int mid, int right)
{
	std::vector<std::pair<int, int>> temp;

	int i = left;
	int j = mid + 1;

	while (i <= mid && j <= right)
	{
		if (pairs[i].first <= pairs[j].first)
			temp.push_back(pairs[i++]);
		else
			temp.push_back(pairs[j++]);
	}
	while (i <= mid)
		temp.push_back(pairs[i++]);
	while (j <= right)
		temp.push_back(pairs[j++]);

	for (size_t k = 0; k < temp.size(); ++k)
		pairs[left + k] = temp[k];
}

static void sortPairs(std::vector<std::pair<int, int>>& pairs, int left, int right)
{
	if (left >= right)
		return ;

	int mid = left + (right - left) / 2;
	sortPairs(pairs, left , mid);
	sortPairs(pairs, mid + 1, right);
	mergePairs(pairs, left, mid, right);
}

static int jacobsthal(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return jacobsthal((n - 1)  + 2 * jacobsthal(n - 2));
}

static std::vector<int> calInsertionPos(size_t pendSize)
{
	std::vector<int> positions;
	if (pendSize == 0)
		return positions;

	std::vector<int> seq;
	int index = 3;
	int jacobValue;

	while ((jacobValue = jacobsthal(index)) < pendSize)
	{
		seq.push_back(jacobValue);
		index++;
	}

	int lastPos = 0;
	for (int i = 0; i < seq.size(); ++i)
	{
		int value = seq[i];
		positions.push_back(value);
	
		// filling backward now down to the last position
		for (int pos =  value - 1; pos > lastPos; --pos)
			positions.push_back(pos);
		lastPos = value;
	}

	// filling the remaining elements in sequential order now cause why not.. seq has to be filled... of course of course 
	for (int pos = lastPos + 1; pos <= pendSize; ++pos)
	{
		positions.push_back(pos);
	}

	return positions;
}

static	int binarySearch(const std::vector<int>& v, int target, int end)
{
	int		start = 0;
	while (start < end)
	{
		int mid = start + (end - start ) / 2;
		if (v[mid] < target )
			start = mid + 1;
		else
			end = mid;
	}
	return	start;
}

std::vector<int> mergeInsertSort(std::vector<int> &v)
{

	if (v.size()<= 1)
		return v;

	// struggler check
	bool	ifStruggler = (v.size() % 2 != 0);
	int 	strugglerVal;
	if (ifStruggler)
		strugglerVal = v.back();
	else
		strugglerVal = 0;


	std::vector<std::pair<int, int>> pairs = createPair(v);
	// trying to sort this pairs
	std::vector<std::pair<int, int>>::iterator it;

	// as per my understanding... we first need to sort the elements inside each pair and then sort the order of pair afterwards... 
	for (it = pairs.begin(); it != pairs.end(); ++it )
	{
		if (it->second > it->first)
			std::swap(it->first, it->second);
	}	
	sortPairs(pairs, 0, pairs.size() - 1);


	// making main chain and pend
	std::vector<int> main;
	std::vector<int> pend;
	if (!pairs.empty())
		main.push_back(pairs[0].second);
	for (it = pairs.begin(); it != pairs.end(); ++it)
	{
		main.push_back(it->first);
		if (it != pairs.begin())
			pend.push_back(it->second);
	}



	// moving on with insertion part (jacobsthol sequence thingy)
	std::vector<int> positions = calInsertionPos(pend.size());
	int	addedCount = 0;

	// insertion via binarySearch
	for (int i = 0; i < positions.size(); ++i)
	{
		int		indPend = positions[i] - 1;
		int 	target = pend[indPend];
		int 	searchUpperBound = positions[i] + addedCount;
		if (searchUpperBound > main.size())
			searchUpperBound = main.size();
	
		int 	insertPos = binarySearch(main, target, searchUpperBound);
		main.insert(main.begin() + insertPos, target);
		addedCount++;
	}

	// putting the struggler in the main chain
	if (ifStruggler)
	{
		int		insertPos = binarySearch(main, strugglerVal, main.size());
		main.insert(main.begin() + insertPos, strugglerVal);
	}

	return main;
}



























