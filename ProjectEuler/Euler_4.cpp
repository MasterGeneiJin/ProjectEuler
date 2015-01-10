#include <algorithm>
#include <sstream>
#include <vector>

#include "Euler.h"

bool isPalindrome(int i)
{
	std::ostringstream oss;
	oss << i;

	std::string temp = oss.str();

	for (unsigned int i = 0; i < temp.length(); ++i)
		if (temp.at(i) != temp.at(temp.length() - 1 - i))
			return false;

	return true;
}

struct digits {
	int i;
	int j;
};

bool digitsfunction (digits x, digits y) { return (x.i * x.j < y.i * y.j); }

std::string Euler::LargestPalindromeFrom3DigitProduct()
{
	std::vector<digits> data;

	for (int i = 999; i > 99; --i)
	{
		for (int j = 999; j > 99; --j)
		{
			if (isPalindrome(i * j)) {
				digits d;
				d.i = i;
				d.j = j;
				data.push_back(d);
				break;
			}
		}
	}

	if (!data.empty()) {
		std::sort(data.begin(), data.end(), digitsfunction);

		digits largest = data.back();

		std::ostringstream oss;
		oss << largest.i << " * " << largest.j << " = " << largest.i * largest.j << std::endl;
		return oss.str();
	}

	return "no palindromes exist within range!\r\n";
}