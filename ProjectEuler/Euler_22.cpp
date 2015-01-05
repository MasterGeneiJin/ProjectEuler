#include <fstream>
#include <regex>
#include <set>

#include "Euler.h"

llui Euler::NameScores()
{
	std::ifstream fin;
	fin.open("C:\\Users\\Michael\\Desktop\\Euler 22.txt");
	std::string names_raw;
	std::getline(fin, names_raw);
	fin.close();

	std::regex regex("[A-Z]+");
	std::set<std::string> names;

	for (std::sregex_iterator i = std::sregex_iterator(names_raw.begin(), names_raw.end(), regex); i != std::sregex_iterator(); ++i)                                             
		names.insert(i->str());

	llui sum = 0;
	int count = 0;

	for (std::string name : names)
	{
		int namesum = 0;

		for (unsigned i = 0; i < name.size(); ++i)
			namesum += name.at(i) - 64;

		sum += namesum * ++count;
	}

	return sum;
}