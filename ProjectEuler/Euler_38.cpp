#include <unordered_set>

#include "Euler.h"

bool hasUniqueDigits(int n)
{
	std::vector<int> digits = EulerUtility::intToDigits(n);

	std::unordered_set<int> uniqueDigits;

	for (int digit : digits)
	{
		if (digit == 0)
			return false;

		uniqueDigits.insert(digit);
	}

	return digits.size() == uniqueDigits.size();
}

int Euler::PanDigitalMultiples()
{
	int greatestPanDigitalMultiple = 918273645;

	for (int i = 9182; i < 9876; ++i) //9182 is the first 4 digits of the above no, 9876 is the int with unique digits < 10000
	{
		if (hasUniqueDigits(i))
		{
			if (hasUniqueDigits(i * 2))
			{
				int potentialPanDigital = atoi((std::to_string(i) + std::to_string(i * 2)).c_str());

				if ((hasUniqueDigits(potentialPanDigital)) && (potentialPanDigital > greatestPanDigitalMultiple))
					greatestPanDigitalMultiple = potentialPanDigital;
			}
		}
	}

	return greatestPanDigitalMultiple;
}