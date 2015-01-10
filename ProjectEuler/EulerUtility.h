#include <string>
#include <vector>

#include "BigIntegerLibrary.hh"

typedef long long unsigned int llui;

class EulerUtility
{
public:
	static std::vector<int> getPrimesUnderCeiling(int ceiling);
	static std::vector<int> tokenizer(std::string s, char delim);
	static int sumOfDivisors(int n);
	static std::vector<int> factorialDigits(int n);
	static int factorial(int n);
	static BigInteger factorial(BigInteger n);
	static BigInteger choose(int n, int k);
	static bool isPerfectSquare(long n);
	static std::vector<int> intToDigitArray(int n);
};