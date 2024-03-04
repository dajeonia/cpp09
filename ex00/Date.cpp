#include "Date.hpp"

char const*	Date::DateNotValidException::what(void) const throw()
{
	return ("date not valid");
}

Date::Date(void) : year(1970), month(1), day(1) { }

Date::Date(std::string s)
{
	year = std::atoi(s.substr(0, 4).c_str());
	month = std::atoi(s.substr(5, 2).c_str());
	day = std::atoi(s.substr(8, 2).c_str());
	if (!validate(year, month, day))
	{
		std::cout << year << ", ";
		std::cout << month << ", ";
		std::cout << day << std::endl;
		throw (DateNotValidException());
	}
}

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {
	if (!validate(y, m, d))
	{
		std::cout << y << ", ";
		std::cout << m << ", ";
		std::cout << d << std::endl;
		throw (DateNotValidException());
	}
}

Date::Date(const Date& d) : year(d.year), month(d.month), day(d.day) { }

Date::~Date(void) { }

bool	Date::validate(int y, int m, int d)
{
	int month[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (!(1970 <= y && y <= 9999))
		return (false);
	if (!(1 <= m && m <= 12))
		return (false);
	if (!(1 <= d && d <= month[m-1]))
		return (false);
	if (m == 2 && d == 29 && !(((y % 4) == 0 && (y % 100) != 0) || (y % 400) == 0))
		return (false);
	return (true);
}

bool	Date::operator>(const Date& d) const
{
	if (year != d.year)
		return (year > d.year);
	else if (month != d.month)
		return (month > d.month);
	return (day > d.day);
}

bool	Date::operator<(const Date& d) const
{
	if (year != d.year)
		return (year < d.year);
	else if (month != d.month)
		return (month < d.month);
	return (day < d.day);
}

bool	Date::operator>=(const Date& d) const
{
	if (year != d.year)
		return (year >= d.year);
	else if (month != d.month)
		return (month >= d.month);
	return (day >= d.day);
}

bool	Date::operator<=(const Date& d) const
{
	if (year != d.year)
		return (year <= d.year);
	else if (month != d.month)
		return (month <= d.month);
	return (day <= d.day);
}

int	Date::getYear(void) const { return (year); }

int	Date::getMonth(void) const { return (month); }

int	Date::getDay(void) const { return (day); }

std::ostream&	operator<<(std::ostream& os, const Date& d)
{
	os.fill('0');
	os.width(4);
	os<< d.getYear() << "-";
	os.width(2);
	os.fill('0');
	os << d.getMonth() << "-";
	os.fill('0');
	os.width(2);
   	os << d.getDay();
	return (os);
}
