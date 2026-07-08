#include "PmergeMe.hpp"
#include <cstddef>
#include <utility>
#include <vector>
#include <deque>

static std::vector<std::pair<int, int> > createPair(std::vector<int> &v) {
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < v.size(); i += 2) {
		pairs.push_back(std::make_pair(v[i], v[i + 1]));
	}
	return pairs;
}

static void mergePairs(std::vector<std::pair<int, int> > &pairs, int left, int mid, int right) {
	std::vector<std::pair<int, int> > temp;

	int i = left;
	int j = mid + 1;

	while (i <= mid && j <= right) {
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

static void sortPairs(std::vector<std::pair<int, int> >& pairs, int left, int right) {
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;
	sortPairs(pairs, left, mid);
	sortPairs(pairs, mid + 1, right);
	mergePairs(pairs, left, mid, right);
}

static int jacobsthal(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

static std::vector<int> calInsertionPos(size_t pendSize) {
	std::vector<int> positions;
	if (pendSize == 0)
		return positions;

	int pSize = static_cast<int>(pendSize);
	std::vector<int> seq;
	int index = 3;
	int jacobValue;

	while (true) {
		jacobValue = jacobsthal(index);
		if (jacobValue >= pSize) {
			seq.push_back(pSize);
			break;
		}
		seq.push_back(jacobValue);
		index++;
	}

	int lastPos = 0;
	for (size_t i = 0; i < seq.size(); ++i) {
		int value = seq[i];
		positions.push_back(value);
	
		for (int pos = value - 1; pos > lastPos; --pos)
			positions.push_back(pos);
		lastPos = value;
	}

	return positions;
}

static int binarySearch(const std::vector<int>& v, int target, int end) {
	int start = 0;
	while (start < end) {
		int mid = start + (end - start) / 2;
		if (v[mid] < target)
			start = mid + 1;
		else
			end = mid;
	}
	return start;
}

std::vector<int> mergeInsertSort(std::vector<int> &v) {
	if (v.size() <= 1)
		return v;

	bool ifStruggler = (v.size() % 2 != 0);
	int strugglerVal = ifStruggler ? v.back() : 0;

	std::vector<std::pair<int, int> > pairs = createPair(v);
	std::vector<std::pair<int, int> >::iterator it;

	for (it = pairs.begin(); it != pairs.end(); ++it) {
		if (it->second > it->first)
			std::swap(it->first, it->second);
	}	
	sortPairs(pairs, 0, pairs.size() - 1);

	std::vector<int> main;
	std::vector<int> pend;
	if (!pairs.empty())
		main.push_back(pairs[0].second);
	for (it = pairs.begin(); it != pairs.end(); ++it) {
		main.push_back(it->first);
		if (it != pairs.begin())
			pend.push_back(it->second);
	}

	std::vector<int> positions = calInsertionPos(pend.size());
	int addedCount = 0;

	for (size_t i = 0; i < positions.size(); ++i) {
		int indPend = positions[i] - 1;
		int target = pend[indPend];
		int searchUpperBound = positions[i] + 1 + addedCount;
		if (static_cast<size_t>(searchUpperBound) > main.size())
			searchUpperBound = main.size();
	
		int insertPos = binarySearch(main, target, searchUpperBound);
		main.insert(main.begin() + insertPos, target);
		addedCount++;
	}

	if (ifStruggler) {
		int insertPos = binarySearch(main, strugglerVal, main.size());
		main.insert(main.begin() + insertPos, strugglerVal);
	}

	return main;
}

static std::deque<std::pair<int, int> > createPair(std::deque<int> &v) {
	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < v.size(); i += 2) {
		pairs.push_back(std::make_pair(v[i], v[i + 1]));
	}
	return pairs;
}

static void mergePairs(std::deque<std::pair<int, int> > &pairs, int left, int mid, int right) {
	std::deque<std::pair<int, int> > temp;

	int i = left;
	int j = mid + 1;

	while (i <= mid && j <= right) {
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

static void sortPairs(std::deque<std::pair<int, int> >& pairs, int left, int right) {
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;
	sortPairs(pairs, left, mid);
	sortPairs(pairs, mid + 1, right);
	mergePairs(pairs, left, mid, right);
}

static int binarySearch(const std::deque<int>& v, int target, int end) {
	int start = 0;
	while (start < end) {
		int mid = start + (end - start) / 2;
		if (v[mid] < target)
			start = mid + 1;
		else
			end = mid;
	}
	return start;
}

std::deque<int> mergeInsertSort(std::deque<int> &v) {
	if (v.size() <= 1)
		return v;

	bool ifStruggler = (v.size() % 2 != 0);
	int strugglerVal = ifStruggler ? v.back() : 0;

	std::deque<std::pair<int, int> > pairs = createPair(v);
	std::deque<std::pair<int, int> >::iterator it;

	for (it = pairs.begin(); it != pairs.end(); ++it) {
		if (it->second > it->first)
			std::swap(it->first, it->second);
	}	
	sortPairs(pairs, 0, pairs.size() - 1);

	std::deque<int> main;
	std::deque<int> pend;
	if (!pairs.empty())
		main.push_back(pairs[0].second);
	for (it = pairs.begin(); it != pairs.end(); ++it) {
		main.push_back(it->first);
		if (it != pairs.begin())
			pend.push_back(it->second);
	}

	std::vector<int> positions = calInsertionPos(pend.size());
	int addedCount = 0;

	for (size_t i = 0; i < positions.size(); ++i) {
		int indPend = positions[i] - 1;
		int target = pend[indPend];
		int searchUpperBound = positions[i] + 1 + addedCount;
		if (static_cast<size_t>(searchUpperBound) > main.size())
			searchUpperBound = main.size();
	
		int insertPos = binarySearch(main, target, searchUpperBound);
		main.insert(main.begin() + insertPos, target);
		addedCount++;
	}

	if (ifStruggler) {
		int insertPos = binarySearch(main, strugglerVal, main.size());
		main.insert(main.begin() + insertPos, strugglerVal);
	}

	return main;
}
