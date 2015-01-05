#include "Euler.h"

llui Euler::FactorialDigitSum()
{
	std::vector<int> digits = EulerUtility::factorialDigits(100);

	int sum = 0;

	for (unsigned i = 0; i < digits.size(); ++i)
		sum += digits[i];

	return sum;
}