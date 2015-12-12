#include <boost/multiprecision/cpp_dec_float.hpp>

#include "Euler.h"

namespace mp = boost::multiprecision;

typedef mp::number<mp::cpp_dec_float<500>> cpp_dec_float_500;

int Euler::OddPeriodSquareRoots()
{
	int count = 0;

	for (cpp_dec_float_500 i = 1; i <= 10000; ++i)
	{
		int sequenceLength = 0;

		cpp_dec_float_500 value = mp::sqrt(i);
		cpp_dec_float_500 floor = mp::floor(value);

		if (!EulerUtility::isPerfectSquare(i.convert_to<int>()))
		{
			bool sequenceDetermined = false;
			bool sequenceIsOdd = false;

			while (!sequenceDetermined)
			{
				value = 1.0 / (value - mp::floor(value));

				if (mp::floor(value) == 2 * floor)
				{
					sequenceDetermined = true;
					sequenceIsOdd = sequenceLength + 1 & 1;
				}
				else
				{
					++sequenceLength;
				}
			}

			if (sequenceIsOdd)
			{
				++count;
			}
		}
	}

	return count;
}