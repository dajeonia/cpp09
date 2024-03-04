#include <iostream>
#include <vector>
#include "Date.hpp"
#include "BitcoinExchange.hpp"
#include <fstream>
// #include "algorithm.hpp"

int	main(int argc, char* argv[]) try
{
	BitcoinExchange exchanger("data.csv");
	if (argc == 2)
	{
		std::ifstream input(argv[1]);
		if (!input.is_open()) {
			std::cout << "Error: could not open file." << std::endl;
			return (1);
		}
		std::cout << "OK" << std::endl;
		try {
			std::string buf;
			while (getline(input, buf))
			{
				if (buf.find_first_not_of("0123456789", 0) != 4)
					break ;
				if (buf.find_first_of("-", 0) != 4)
					break ;
				if (buf.find_first_not_of("0123456789", 5) != 7)
					break ;
				if (buf.find_first_of("-", 5) != 7)
					break ;
				if (buf.find_first_not_of("0123456789", 8) != 10)
					break ;
				ret = buf.find_first_of("-", 10);
				if (ret == std::string::npos)
					break ;
				buf.find_first_of("012345689", ret) != 7;
				


			}
		}
		catch (std::exception& e) {
			input.close();
			throw ;
		}

		


	}
	else
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	return (0);
}
catch (std::exception& e)
{
	std::cout << "Error: " << e.what() << "." << std::endl;
	return (1);
}


