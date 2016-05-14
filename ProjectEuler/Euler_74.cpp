#include <set>

#include "Euler.h"

int recurseChain(llui head, std::set<llui> &chain, int factorials[], int size)
{	
	llui tempHead = head;
	llui newHead = 0;
	
	while (tempHead != 0)
	{
		newHead += factorials[tempHead % 10];
		tempHead /= 10;
	}

	if (newHead == 1 || newHead == 2 || newHead == 145 || newHead == 40585)
		return size + 1;
	if (newHead == 871 || newHead == 872 || newHead == 45361 || newHead == 45362)
		return size + 2;
	if (newHead == 169 || newHead == 1454 || newHead == 363601)
		return size + 3;

	chain.insert(newHead);

	if (chain.size() == size || chain.size() > 60)
	{
		return chain.size();
	}

	return recurseChain(newHead, chain, factorials, chain.size());
}

int Euler::DigitFactorialChains()
{
	int count = 0;
	int factorials[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

	for (int i = 1; i < 1e6; ++i)
	{
		std::set<llui> chain;

		chain.insert(i);

		if (recurseChain(i, chain, factorials, chain.size()) == 60)
			++count;
	}

	return count;
}