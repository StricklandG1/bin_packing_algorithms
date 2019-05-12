#include "project2.h"
#include <algorithm>

void best_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	std::sort(items.begin(), items.end());
}

void best_fit_decreasing(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	best_fit(items, assignment, free_space);
}