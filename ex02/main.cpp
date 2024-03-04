#include <iostream>
#include <ctime>
#include "PmergeMe.hpp"

int getJacob(int n, size_t max);
template<typename T>
void EasyPrint(T& a, const char* name);
template<typename T1, typename T2>
int	isSorted(T1 a, T2 b, T1 origin);
int	isOnlyNumber(const char* arg);

int	main(int argc, char *argv[])
{
	if (argc != 1)
	{
		std::vector<int> vec;
		std::deque<int> deq;

		for (int i=1; i!=argc; ++i) {
			if (isOnlyNumber(argv[i]) < 0)
				return (1);
			vec.push_back(std::atoi(argv[i]));
			deq.push_back(std::atoi(argv[i]));
		}
		std::vector<int> original(vec);

		clock_t vec_start = clock();
		vec = PmergeMe::MergeInsertion(vec);
		clock_t vec_end = clock();

		clock_t deq_start = clock();
		deq = PmergeMe::MergeInsertion(deq);
		clock_t deq_end = clock();

		EasyPrint(original, "Before");
		EasyPrint(vec, "After");

		/*
		if (isSorted(vec, deq, original) < 0)
			return (1);
		*/
		std::cout << std::fixed;
		std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << (float)(vec_end - vec_start) / CLOCKS_PER_SEC * 1000 * 1000 << " us" << std::endl;
		std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : " << (float)(deq_end - deq_start) / CLOCKS_PER_SEC * 1000 * 1000 << " us" << std::endl;
	}
	else
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	return (0);
}

template<typename T>
void	EasyPrint(T& a, const char* name)
{
	typedef typename T::iterator Iter;

	std::cout << name << ": ";
	for (Iter iter=a.begin(); iter!=a.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl;;
}

int	isOnlyNumber(const char* arg)
{
	std::string s(arg);
	if (s.find_first_not_of("\n\t\v\f\r 0123456789") != std::string::npos)
	{
		std::cout << "Error" << std::endl;
		return (-1);
	}
	return (0);
}

/*
template<typename T1, typename T2>
int	isSorted(T1 a, T2 b, T1 origin)
{
	std::cout << "Pmerge: ";
	if (origin.size() != a.size()) {
		std::cout << "Error: size" << std::endl;
		return (-1);
	}
	if (a.size() != b.size()) {
		std::cout << "Error: size" << std::endl;
		return (-1);
	}
	size_t sz(a.size());
	if (sz != 0) {
		int prev(a[0]);
		for (size_t i=0; i!=sz; ++i) {
			if (a[i] != b[i]) {
				std::cout << "Error: a[" << i << "]: " << a[i] << std::endl;
				std::cout << "Error: b[" << i << "]: " << b[i] << std::endl;
				return (-1);
			}
			else if (prev > a[i]) {
				std::cout << "Error: is not sorted: " << prev << " > " << a[i] << std::endl;
				return (-1);
			}
			prev = a[i];
		}
	}
		std::cout << "OK" << std::endl;
		return (0);
}
*/
