#include "Euler.h"

int phi(int n, std::vector<int> &primes, std::vector<int> &primesIndexed)
{
	// Base case
	if (n < 2)
		return 0;

	// Lehmer's conjecture
	if (primesIndexed[n] != -1)
		return n - 1;

	// Even number?
	if (n & 1 == 0)
	{
		int m = n >> 1;
		return !(m & 1) ? phi(m, primes, primesIndexed) << 1 : phi(m, primes, primesIndexed);
	}

	// For all primes ...
	for (std::vector<int>::iterator p = primes.begin(); p != primes.end() && *p <= n; ++p)
	{
		int m = *p;
		if (n % m) continue;

		// phi is multiplicative
		int o = n / m;
		int d = EulerUtility::gcd(m, o);
		return (d == 1) ? phi(m, primes, primesIndexed) * phi(o, primes, primesIndexed) : phi(m, primes, primesIndexed) * phi(o, primes, primesIndexed) * d / phi(d, primes, primesIndexed);
	}
}

int Euler::EulerTotient()
{
	std::vector<int> primes = EulerUtility::getPrimesUnderCeiling(1e6);
	std::vector<int> primesIndexed = EulerUtility::getPrimesUnderCeilingIndexed(1e6);
	double NoverPhi = 0, n = 0;
	for (double i = 2; i <= 1e6; ++i)
	{
		int p = phi(i, primes, primesIndexed);

		if (i / p > NoverPhi)
		{
			NoverPhi = i / p;
			n = i;
		}
	}

	return n;
}