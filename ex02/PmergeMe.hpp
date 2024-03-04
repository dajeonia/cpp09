#include <vector>
#include <deque>

class PmergeMe {
	static int min(int, int);
	static int max(int, int);
	static int getJacob(int, size_t);
	template<typename Iter>
	static Iter BinarySearch(Iter, Iter, int);
	template<typename C>
	static C organize(C& ret, C& head, C& tail);
public:
	static std::vector<int> MergeInsertion(const std::vector<int>&);
	static std::deque<int> MergeInsertion(const std::deque<int>&);
};
