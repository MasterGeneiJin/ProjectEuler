#include "Euler.h"

int periodiuy(int n)
{
	double n2 = std::sqrtl(n);
	int a = n2, p = 0, q = 1, length = 0;

	do
	{
		length++;
		p = a * q - p;
		q = ( n - p * p ) / q;
		a = ( p + n2 ) /q;
	} while ( q != 1 );

	return length;
}

int Euler::ConvergentsOfE()
{
	int odds = 0;

	for (int n = 1; n <= 10000; n++)
	{
		int n2 = sqrt(n);

		if (n2 * n2 != n)
		{
			if (periodiuy(n) & 1)
			{
				odds++;
			}
		}
	}

	return odds;
}
