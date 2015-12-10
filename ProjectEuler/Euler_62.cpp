#include <algorithm>
#include <map>

#include "Euler.h"

llui Euler::CubicPermutations()
{
	std::map<std::string, std::vector<llui>> cubicGroups;

	for (llui i = 346;; ++i)
	{
		std::vector<int> cubeDigits = EulerUtility::lluiToDigits(i * i * i);

		std::string key;

		for (int j = 0; j < 10; ++j)
		{
			int count = 0;

			for (int cubeDigit : cubeDigits)
				if (cubeDigit == j)
					++count;

			key.push_back(count + '0');
		}

		std::map<std::string, std::vector<llui>>::iterator it = cubicGroups.find(key);

		if (it == cubicGroups.end())
		{
			std::vector<llui> newGroup;
			newGroup.push_back(i * i * i);
			cubicGroups.insert(std::pair<std::string, std::vector<llui>>(key, newGroup));
		}
		else
		{
			it->second.push_back(i * i * i);

			if (it->second.size() == 5 && key != "0000000000")
			{
				return it->second[0];
			}
		}
	}

	return 0;
}