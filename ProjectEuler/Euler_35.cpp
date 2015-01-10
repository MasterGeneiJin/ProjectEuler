#include "Euler.h"

int Euler::NoOfCircularPrimes()
{
	int total = 2; //this algorithm misses out 2 and 5
	int ceiling = 1e6;
	int r_it = 1;

	std::vector<int> primes = EulerUtility::getPrimesUnderCeilingIndexed(ceiling);

	for (int prime : primes)
	{
		if (prime != 0)
		{
			bool potentialCircularPrime = true;

			std::vector<int> digits = EulerUtility::intToDigits(prime);

			for (int digit : digits)
				if ((digit == 0) || (digit == 5) || (digit % 2 == 0))
				{
					potentialCircularPrime = false;
					break;
				}

			if (potentialCircularPrime)
				for (int j = 0; j <= log10(prime); ++j)
				{
					if (primes[EulerUtility::digitsToInteger(digits)] == 0)
					{
						potentialCircularPrime = false;
						break;
					}

					std::rotate(digits.begin(), digits.begin() + 1, digits.end());
				}

			if (potentialCircularPrime)
				++total;
		}
	}

	return total;
}