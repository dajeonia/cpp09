#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <iostream>

void	RPN::operator()(const char* arg)
{
	std::stack<int> st;
	std::stringstream ss(arg);
	char ch;

	while (ss >> ch)
	{
		if ('0' <= ch && ch <= '9')
			st.push(ch - '0');
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			if (st.size() < 2) {
				std::cout << "Error" << std::endl;
				return ;
			}
			int b(st.top());
			st.pop();
			switch (ch) {
			case '+':
				st.top() += b;
				break ;
			case '-':
				st.top() -= b;
				break ;
			case '*':
				st.top() *= b;
				break ;
			case '/':
				if (b == 0)
				{
					std::cout << "Error" << std::endl;
					return ;
				}
				st.top() /= b;
				break ;
			default:
				std::cout << "Error" << std::endl;
				return ;
			}
		}
		else {
			std::cout << "Error" << std::endl;
			return ;
		}
	}
	if (st.size() == 1)
		std::cout << st.top() << std::endl;
	else
		std::cout << "Error" << std::endl;
}
