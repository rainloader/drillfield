#include <iostream>
#include <string>

struct Pack
{
	int m_int;
	char m_char;
	std::string m_string;
};
	std::istream& operator >>(std::istream& is, Pack& pack)
	{
		is >> pack.m_int;
		is >> pack.m_char;
		is >> pack.m_string;
		return is;
	}
	std::ostream& operator <<(std::ostream& os, const Pack& pack)
	{
		os << pack.m_int;
		os << pack.m_char;
		os << pack.m_string;
		return os;
	}
int main()
{
	Pack pak1, pak2;
	pak1.m_int = 8;
	pak1.m_char = 'c';
	pak1.m_string = "OH?";
	std::cout << pak1<< std::endl;
	std::cin >> pak2;
	std::cout << pak2 << std::endl;
	return 0;
}
