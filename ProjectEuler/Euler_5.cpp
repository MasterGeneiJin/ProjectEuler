#include "Euler.h"

int Euler::DivisibleBy1To20()
{
	int i = 2519;

	bool isDivisible = true;

	do {
		i += 1;
		isDivisible = true;

		for (int j = 1; j <= 20; ++j)
		{
			if (i % j != 0)
				isDivisible = false;
		}
	} while(!isDivisible);

	return i;
}