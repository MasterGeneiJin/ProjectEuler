#include <fstream>
#include <iostream>
#include <numeric>

#include "Euler.h"

int Euler::xorDecryption()
{
	std::ifstream file;
	std::vector<int> chars;
	std::string character;
	std::string word = " the ";

	char message[1201];

	file.open("C:\\Users\\Michael\\Desktop\\Euler 59.txt");

	while(getline(file, character, ','))
		chars.push_back(atoi(character.c_str()));

	int cypher[3];

	for (cypher[0] = 97; cypher[0] < 123; ++cypher[0])
	{
		for (cypher[1] = 97; cypher[1] < 123; ++cypher[1])
		{
			for (cypher[2] = 97; cypher[2] < 123; ++cypher[2])
			{
				for (int i = 0; i < 1201; ++i)
					message[i] = chars[i] ^ cypher[i % 3];

				if (std::string(message).find(word) != std::string::npos)
					return std::accumulate(message, message + 1201, 0);
			}
		}
	}

	return 0;
}