#include <iostream>
#include <vector>
#include "Date.hpp"
#include "BitcoinExchange.hpp"
#include <fstream>

bool	isRow(std::string buf);

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
			getline(input, buf);
			while (getline(input, buf))
			{
				if (buf.size() == 0) 
				{
					std::cout << "?" << std::endl;
					continue;
				}
				if (!isRow(buf))
				{
					std::cout << "Error: bad input" << std::endl;
					continue ;
				}
				Date d(buf);
				float f(std::strtod(buf.substr(buf.find_first_of("|") + 1, buf.size()).c_str(), NULL));
				if (!(0 <= f && f <= 1000))
				{
					std::cout << "Error: bad input" << std::endl;
					continue ;
				}

				std::cout << std::fixed << d << " => " << f << " = " << exchanger.exchange(d, f) << std::endl;
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

bool	isRow(std::string buf)
{
	if (buf.find_first_not_of("0123456789", 0) != 4)
		return (0);
	if (buf.find_first_of("-", 0) != 4)
		return (0);
	if (buf.find_first_not_of("0123456789", 5) != 7)
		return (0);
	if (buf.find_first_of("-", 5) != 7)
		return (0);
	if (buf.find_first_not_of("0123456789", 8) != 10)
		return (0);
	size_t ret = buf.find_first_not_of(" ", 10);
	if (ret != buf.find_first_of("|", 10))
		return (0);
	ret = buf.find_first_not_of(" ", ret+1);
	if (ret != buf.find_first_of("0123456789", ret))
		return (0);
	ret = buf.find_first_not_of("0123456789", ret);
	if (buf[ret] == '.')
	{
		++ret;
		if (ret == buf.find_first_not_of("0123456789", ret))
			return (0);
		if (buf.find_first_not_of("0123456789", ret) != std::string::npos)
			return (0);
		return (2);
	}
	if (buf.find_first_not_of("0123456789", ret) != std::string::npos)
		return (0);
	return (1);
}

/*
int	main(int argc, char* argv[])
{
	if (argc == 2)
	{
		if (isRow(std::string(argv[1])))
			std::cout << "OK" << std::endl;
		else
			std::cout << "ERROR" << std::endl;
	}
	return (0);
}
*/
