#include <iostream>

#include "Euler.h"

const BigInteger ZERO = 0;
const BigInteger ONE = 1;
BigInteger partition(BigInteger &n, std::vector<BigInteger> &cache)
{
	BigInteger p = 0;

	if (n >= 0)
	{
		if (n.compareTo(ZERO) == BigInteger::CmpRes::equal || n.compareTo(ONE) == BigInteger::CmpRes::equal)
		{
			return 1;
		}
		if (cache[n.toInt() - 1] != 0)
		{
			return cache[n.toInt() - 1];
		}

		int k = 1;

		BigInteger s1 = 0;
		BigInteger s2 = 0;

		while (n - s2 >= 0)
		{
			s1 = (k * (3 * k - 1)) / 2;
			s2 = (k * (3 * k + 1)) / 2;

			BigInteger sign = (k - 1) & 1 ? -1 : 1;

			p += sign * partition(n - s1, cache);
			p += sign * partition(n - s2, cache);
			++k;
		}

		cache[n.toInt() - 1] = p;
	}

	return p;
}

llui Euler::CoinPartitions()
{
	for (int i = 1; i < 1000; ++i)
	{
		if ((i - 4) % 5 == 0)
		{
			BigInteger n = partition(BigInteger(i), std::vector<BigInteger>(i, ZERO));
			
			//std::cout << i << " - > " << n << std::endl;

			if (n % 10000 == 0)
			{
				return 1;
			}
		}
	}

	return 0;
}