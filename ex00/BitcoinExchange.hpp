#include <fstream>
#include <map>

class Date;

class BitcoinExchange {
	std::map<Date, float> table;
public:
	BitcoinExchange(const char*);
	~BitcoinExchange();

	float exchange(Date, float);
	const std::map<Date, float>& getTable(void) const;
private:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange&);
	BitcoinExchange& operator=(const BitcoinExchange&);

private: 
	class DataCannotOpenException : public std::exception {
	public:
		char const* what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream&, const BitcoinExchange&);
