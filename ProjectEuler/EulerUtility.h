#include <string>
#include <vector>

#include "BigIntegerLibrary.hh"

typedef long long unsigned int llui;

class EulerUtility
{
public:
	static int multiply(int x, int y);
	static std::vector<int> getPrimesUnderCeiling(int ceiling);
	static std::vector<int> getPrimesUnderCeilingIndexed(int ceiling);
	static std::vector<int> tokenizer(std::string s, char delim);
	static int sumOfDivisors(int n);
	static std::vector<int> factorialDigits(int n);
	static int factorial(int n);
	static BigInteger bigFactorial(BigInteger n);
	static BigInteger choose(int n, int k);
	static bool isPerfectSquare(long n);
	static std::vector<int> intToDigits(int n);
	static int digitsToInteger(std::vector<int> digits);
	static llui digitsTollui(std::string s);
	static bool hasUniqueDigits(int n, bool allowZero);
	static bool isPrime(int n);
	static bool isTriangle(int n);
	static bool isPentagonal(int n);
	static std::vector<std::string> openWordFile(std::string filename);
};