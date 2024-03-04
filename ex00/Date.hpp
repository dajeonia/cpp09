#include <stdexcept>
#include <iostream>

class Date {
	int year;
	int month;
	int day;
	static bool validate(int, int, int);
public:
	Date();
	Date(int, int, int);
	Date(std::string);
	Date(const Date&);
	~Date();

	int getYear() const;
	int getMonth() const;
	int getDay() const;

	bool operator<(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator>=(const Date& d) const;

	class DateNotValidException : public std::exception {
	public:
		char const* what(void) const throw();
	};
private:
	Date& operator=(const Date&);
};

std::ostream& operator<<(std::ostream& os, const Date& d);
