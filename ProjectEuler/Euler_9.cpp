#include <sstream>
#include "Euler.h"

std::string Euler::SpecialPythagoreanTriplet()
{
	for (int a = 1; a < 1000; ++a)
		for (int b = 1; b < 1000; ++b)
		{
			double c = sqrt(a * a + b * b);
			if ((a + b + c) == 1000)
			{
				std::ostringstream oss;
				oss << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
				oss << "product = " << a * b * (int)c;
				return oss.str();
			}
		}

		return "couldn't calculate answer.";
}