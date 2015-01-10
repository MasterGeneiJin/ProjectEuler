#include <sstream>

#include "EulerUtility.h"

int EulerUtility::sumOfDivisors(int n)
{
	int prod = 1;

	for(int k = 2; k * k <= n; ++k)
	{
		int p = 1;

		while(n % k == 0)
		{
			p = p * k + 1;
			n /= k;
		}

		prod *= p;
	}

	if(n > 1)
		prod *= 1 + n;

	return prod;
}

std::vector<int> EulerUtility::getPrimesUnderCeiling(int ceiling)
{
	std::vector<int> primes;

	primes.push_back(2);
	primes.push_back(3);

	bool is_prime;

	for(int i = 5; i < ceiling; i += 2)
	{
		is_prime = true;

		for(int j = 3; j * j <= i && is_prime; j += 2)
			if(i % j == 0) is_prime = false;

		if(is_prime)
			primes.push_back(i);
	}

	return primes;
}

std::vector<int> EulerUtility::getPrimesUnderCeilingIndexed(int ceiling)
{
	std::vector<int> primes;

	primes.push_back(0);
	primes.push_back(0);
	primes.push_back(2);
	primes.push_back(3);
	primes.push_back(0);

	bool is_prime;

	for(int i = 5; i < ceiling; i += 2)
	{
		is_prime = true;

		for(int j = 3; j * j <= i && is_prime; j += 2)
			if(i % j == 0) is_prime = false;

		if(is_prime)
		{
			primes.push_back(i);
			primes.push_back(0);
		}
		else
		{
			primes.push_back(0);
			primes.push_back(0);
		}
	}

	return primes;
}

std::vector<int> EulerUtility::tokenizer(std::string s, char delim)
{
	std::istringstream split(s);
	std::vector<int> tokens;
	for (std::string each; std::getline(split, each, delim); tokens.push_back(atoi(each.c_str())));

	return tokens;
}

std::vector<int> EulerUtility::factorialDigits(int n)
{
	std::vector<int> digits(1, 1);

	for (int i = 1; i <= n; ++i)
	{
		for (unsigned j = 0; j < digits.size(); ++j)
			digits[j] *=i;

		for (unsigned j = 0; j < digits.size(); ++j)
		{
			if (digits[j] >= 10)
			{
				int carry = (digits[j] - (digits[j] % 10)) / 10;
				digits[j] = digits[j] % 10;

				if (j == digits.size() - 1)
					digits.push_back(carry);
				else
					digits[j + 1] += carry;
			}
		}
	}

	return digits;
}

BigInteger EulerUtility::bigFactorial(BigInteger n) 
{
	if (n == 0)
		return 1;
	return n * bigFactorial(n - 1);
}

int EulerUtility::factorial(int n) 
{
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}

BigInteger EulerUtility::choose(int n, int k)
{
	return EulerUtility::bigFactorial(n) / (EulerUtility::bigFactorial(k) * EulerUtility::bigFactorial(n - k));
}

bool EulerUtility::isPerfectSquare(long n)
{
	if (n < 0)
		return false;

	long tst = (long)(sqrt(n) + 0.5);
	return tst*tst == n;
}

std::vector<int> EulerUtility::intToDigits(int n)
{
	std::vector<int> digitArray;

	while (n != 0)
	{
		digitArray.push_back(n % 10);
		n /= 10;
	}

	std::reverse(digitArray.begin(), digitArray.end());

	return digitArray;
}

int EulerUtility::digitsToInteger(std::vector<int> d)
{
	std::stringstream ss;

	for (int i : d)
		ss << i;

	int integer;
	ss >> integer;

	return integer;
}