#include <algorithm>
#include <unordered_set>

#include "Euler.h"

int Euler::PanDigitalProducts()
{
	std::string lexicon = "123456789";

	std::unordered_set<int> products;

	for (BigInteger i = 0; i < EulerUtility::factorial(9); ++i)
	{
		for (int it1 = 1; it1 < 5; ++ it1)
			for (int it2 = it1 + 1; it2 < lexicon.size() - 2; ++it2)
			{
				int prod = std::stoi(lexicon.substr(0, it1)) * std::stoi(lexicon.substr(it1, it2 - it1));

				if (prod == std::stoi(lexicon.substr(it2, lexicon.size())))
					products.insert(prod);
			}

		std::next_permutation(lexicon.begin(), lexicon.end());
	}

	int sum = 0;

	for (int product : products)
		sum += product;

	return sum;
}