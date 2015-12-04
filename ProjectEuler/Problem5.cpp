//https://blog.svpino.com/2015/05/07/five-programming-problems-every-software-engineer-should-be-able-to-solve-in-less-than-1-hour

#include <bitset>
#include <iostream>

#include "Euler.h"

std::string Euler::problem5()
{
	std::string lexicon = "123456789";

	for (int i = 1; i < 256; ++i)
	{	
		std::string b1 = std::bitset<8>(i).to_string();

		int pos = 0, len = 1;

		std::vector<int> numbers;

		for (char c : b1)
		{
			if (c - '0')
			{
				numbers.push_back(atoi(lexicon.substr(pos, len).c_str()));
				pos += len;
				len = 1;
			}
			else
				++len;
		}

		numbers.push_back(atoi(lexicon.substr(pos, len).c_str()));


		if (i == 219)
		{
			std::cout  <<std::endl;
		}

		for (int j = 1; j < pow(2, numbers.size() - 1); ++j)
		{
			std::string b2 = std::bitset<8>(j).to_string();
			int sum = numbers[0];

			for (int l = 1; l < numbers.size(); ++l)
			{
				for (int k = b2.size() - 1; k >= b2.size() - numbers.size() + 2; --k)
				{
					if (b2[k] - '0')
						sum += numbers[l];
					else
						sum -= numbers[l];
				}
			}

			if (sum == 100)
			{
				
		std::cout << std::endl;
			}
		}
	}

	return "";
}