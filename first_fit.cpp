#include "project2.h"
#include <algorithm>

void first_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	std::sort(items.begin(), items.end());
}

void first_fit_decreasing(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	first_fit(items, assignments, free_space);
}