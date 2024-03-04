#include "PmergeMe.hpp"
#include <algorithm>

int	PmergeMe::min(int a, int b) { return (a < b ? a : b); }

int	PmergeMe::max(int a, int b) { return (a > b ? a : b); }

int PmergeMe::getJacob(int n, size_t max)
{
	int jacobs[18] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381};
	for (int i=0; i!=18; ++i)
	{
		if (jacobs[i] <= n && n < jacobs[i + 1])
			return (jacobs[i] + (min(max, jacobs[i + 1]) - n) - 1);
	}
	return (n);
}

std::vector<int> PmergeMe::MergeInsertion(const std::vector<int>& v)
{
	std::vector<int> head;
	std::vector<int> tail;

	if (v.size() == 1)
		return (v);
	for (size_t i=0; i+1<v.size(); i+=2)
	{
		head.push_back(max(v.at(i), v.at(i + 1)));
		tail.push_back(min(v.at(i), v.at(i + 1)));
	}
	if (v.size() % 2 == 1)
		tail.push_back(v.at(v.size() - 1));

	std::vector<int> ret(MergeInsertion(head));
	std::vector<int> cpy(ret);
	
	tail = organize(ret, head, tail);
	cpy.insert(BinarySearch(cpy.begin(), cpy.end(), tail[0]), tail[0]);
	for (size_t i=1; i!=tail.size(); ++i)
	{
		// std::cout << "getJacob" << getJacob(i, tail.size()) << std::endl;
		cpy.insert(BinarySearch(cpy.begin(), cpy.end(), tail[getJacob(i, tail.size())]), tail[getJacob(i, tail.size())]);
	}
	return (cpy);
}

std::deque<int> PmergeMe::MergeInsertion(const std::deque<int>& v)
{
	std::deque<int> head;
	std::deque<int> tail;

	if (v.size() == 1)
		return (v);
	for (size_t i=0; i+1<v.size(); i+=2)
	{
		head.push_back(max(v.at(i), v.at(i + 1)));
		tail.push_back(min(v.at(i), v.at(i + 1)));
	}
	if (v.size() % 2 == 1)
		tail.push_back(v.at(v.size() - 1));

	std::deque<int> ret(MergeInsertion(head));
	std::deque<int> cpy(ret);
	
	tail = organize(ret, head, tail);
	cpy.insert(BinarySearch(cpy.begin(), cpy.end(), tail[0]), tail[0]);
	for (size_t i=1; i!=tail.size(); ++i)
	{
		cpy.insert(BinarySearch(cpy.begin(), cpy.end(), tail[getJacob(i, tail.size())]), tail[getJacob(i, tail.size())]);
	}
	return (cpy);
}

template<typename C>
C	PmergeMe::organize(C& ret, C& head, C& tail)
{
	typedef typename C::iterator Iter;
	C tail_new;
	for (Iter iter=ret.begin(); iter!=ret.end(); ++iter)
	{
		int idx(std::distance(head.begin(), std::find(head.begin(), head.end(), *iter)));
		tail_new.push_back(tail.at(idx));
	}
	if (tail.size() != head.size())
		tail_new.push_back(tail.at(tail.size() - 1));
	return (tail_new);
}

template<typename Iter>
Iter	PmergeMe::BinarySearch(Iter beg, Iter end, int value)
{
	while (beg < end)
	{
		Iter mid(beg + (end - beg) / 2);
		if (value < *mid)
			end = mid;
		else
			beg = mid + 1;
	}
	return beg;
}
