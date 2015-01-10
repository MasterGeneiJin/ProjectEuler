#include <algorithm>
#include <unordered_set>

#include "Euler.h"

int getSubInt(int it1, int it2, std::vector<int> &sub_lex)
{
	int integer = 0;

	for (int i = it1; i < it2; ++i)
	{
		integer *= 10;
		integer += sub_lex[i];
	}

	return integer;
}

int Euler::PanDigitalProducts()
{
	int lexicon[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector<int> lex(std::begin(lexicon), std::end(lexicon));

	std::unordered_set<int> products;

	for (int i = 0; i < 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2; ++i)
	{
		for (int it1 = 1; it1 < 5; ++ it1)
			for (int it2 = it1 + 1; it2 < lex.size() - 3; ++it2)
			{
				int multiplicand = getSubInt(0, it1, lex);
				int multiplier	 = getSubInt(it1, it2, lex);
				int product		 = getSubInt(it2, lex.size(), lex);

				if (multiplicand * multiplier == product)
					products.insert(product);
			}

		std::next_permutation(lex.begin(), lex.end());
	}

	int sum = 0;

	for (int product : products)
		sum += product;

	return sum;
}