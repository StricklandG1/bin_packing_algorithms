#include "functions.h"
#include <random>

void randomize(std::vector<double>& items)
{
	std::random_device rd;
	std::mt19937 eng(rd());

	std::uniform_real_distribution<> distr(0.0, 1.0);

	size_t len = items.size();

	for (size_t i = 0; i < len; ++i)
	{
		items[i] = distr(eng);
	}
}

void test_set(int fit, int set_size)
{
	switch (fit)
	{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
	}
}