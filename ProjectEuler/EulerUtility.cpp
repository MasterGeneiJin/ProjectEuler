#include <fstream>
#include <regex>
#include <sstream>
#include <unordered_set>

#include "EulerUtility.h"

int EulerUtility::multiply(int x, int y)
{
    return x * y;
}

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

	primes.push_back(-1);
	primes.push_back(-1);
	primes.push_back(2);
	primes.push_back(3);
	primes.push_back(-1);

	bool is_prime;

	for(int i = 5; i < ceiling; i += 2)
	{
		is_prime = true;

		for(int j = 3; j * j <= i && is_prime; j += 2)
			if(i % j == 0) is_prime = false;

		if(is_prime)
		{
			primes.push_back(i);
			primes.push_back(-1);
		}
		else
		{
			primes.push_back(-1);
			primes.push_back(-1);
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

llui EulerUtility::digitsTollui(std::string s)
{
	std::stringstream ss;

	for (char c : s)
		ss << c;

	llui digits;
	ss >> digits;

	return digits;
}

bool EulerUtility::hasUniqueDigits(int n, bool allowZero)
{
	std::vector<int> digits = EulerUtility::intToDigits(n);

	std::unordered_set<int> uniqueDigits;

	for (int digit : digits)
	{
		if (digit == 0 && !allowZero)
			return false;

		uniqueDigits.insert(digit);
	}

	return digits.size() == uniqueDigits.size();
}

bool EulerUtility::isPrime(int n)
{
	if (((!(n & 1)) && n != 2 ) || (n < 2) || (n % 3 == 0 && n != 3))
		return false;

	for(int k = 1; 36 * k * (k - 12) * k < n; ++k)
		if ((n % ((6 * k) + 1) == 0) || (n % ((6 * k) - 1) == 0))
			return false;

	return true;
}

bool EulerUtility::isTriangle(int n)
{
	return std::floor(sqrt(2 * n + 0.25) - 0.5) == sqrt(2 * n + 0.25) - 0.5;
}

bool EulerUtility::isPentagonal(int n)
{
	bool c =isPerfectSquare((24 * n) + 1) && ((int)sqrt((24 * n) + 1) + 1) % 6 == 0;
	return c;
}

std::vector<std::string> EulerUtility::openWordFile(std::string filename)
{
	std::ifstream file;
    std::vector<std::string> names;
    std::string name;
    file.open(filename);

    while(getline(file, name, ','))
        names.push_back(name.substr(1, name.size() - 2));

	return names;
}