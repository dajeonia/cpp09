#include "BitcoinExchange.hpp"
#include "algorithm.hpp"
#include <cstdlib>
#include "Date.hpp"

char const*	BitcoinExchange::DataCannotOpenException::what(void) const throw()
{
	return ("database cannot be openned");
}

BitcoinExchange::BitcoinExchange(const char* filename)
{
	std::string check(filename);
	if (!(check.rfind(".csv") != std::string::npos))
		throw (DataCannotOpenException());
	if (!(check.substr(check.length() - 4) == ".csv"))
		throw (DataCannotOpenException());

	std::ifstream data(filename);
	if (!data.is_open())
		throw (DataCannotOpenException());
	try {
		std::string buf;
		getline(data, buf, '\n');
		while (getline(data, buf, ','))
		{
			int year(std::atoi(buf.substr(0, 4).c_str()));
			int month(std::atoi(buf.substr(5, 2).c_str()));
			int day(std::atoi(buf.substr(8, 2).c_str()));
			Date date(year, month, day);

			getline(data, buf, '\n');
			float exchange_rate(strtod(buf.c_str(), NULL));

			table.insert(std::pair<Date,float>(date, exchange_rate));
		}
	}
	catch (std::exception& e) {
		data.close();
		throw ;
	}
	data.close();
}

BitcoinExchange::~BitcoinExchange(void) { }

const std::map<Date, float>&	BitcoinExchange::getTable(void) const { return (table); }

std::ostream& operator<<(std::ostream& os, const BitcoinExchange& b)
{
	typedef std::map<Date, float>::const_iterator Iter;

	for (Iter beg=b.getTable().begin(); beg!=b.getTable().end(); ++beg)
		os << beg->first << " | " << beg->second << std::endl;
	return (os);
}

float	BitcoinExchange::exchange(Date date, float value)
{
	typedef std::map<Date,float>::const_reverse_iterator Iter;

	Iter iter(lowerBound(table, date));
	if (iter == table.rend())
		return (0);
	return (iter->second * value);
}
