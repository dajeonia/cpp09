#include <iostream>
#include "RPN.hpp"

int	main(int argc, char* argv[])
{
	RPN test;
	if (argc == 2)
		test(argv[1]);
	else
		std::cout << "Error" << std::endl;
	return (0);
}
