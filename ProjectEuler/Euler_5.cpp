#include <algorithm>
#include <numeric>

#include "Euler.h"

void addNewPrimeFactors(int nextDivisor, std::vector<int> &p_factors, std::vector<int> &primes)
{
	std::vector<int> myPrimeFactors;
	int i = 0;
	bool first = true;

	while (nextDivisor != 1 && primes[i] <= nextDivisor)
	{
		if (primes[i] != 0)
		{
			if (nextDivisor % primes[i] == 0)
			{
				nextDivisor /= primes[i];

				if (first)
				{
					first = false;
					myPrimeFactors.push_back(1);
				}
				else
					myPrimeFactors[myPrimeFactors.size() - 1] += 1;
			}
			else
			{
				myPrimeFactors.push_back(0);
				++i;
			}
		}
		else
		{
			myPrimeFactors.push_back(0);
			++i;
		}
	}

	for (int j = 0; j < myPrimeFactors.size(); ++j)
		if (p_factors[j] < myPrimeFactors[j])
			p_factors[j] = myPrimeFactors[j];
}

int Euler::DivisibleBy1To20()
{
	std::vector<int> noOfPrimeFactors(20, 0);
	std::vector<int> primeFactors;
	std::vector<int> primes = EulerUtility::getPrimesUnderCeilingIndexed(20);

	for (int i = 2; i <= 20; ++i)
		addNewPrimeFactors(i, noOfPrimeFactors, primes);

	for (int i = 0; i < noOfPrimeFactors.size(); ++i)
		for (int j = 0; j < noOfPrimeFactors[i]; ++j)
			primeFactors.push_back(primes[i]);

	return std::accumulate(primeFactors.begin(), primeFactors.end(), 1, EulerUtility::multiply);
}