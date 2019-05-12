#include "project2.h"
#include "functions.h"
#include <algorithm>

void best_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	size_t len = items.size();
	for (size_t i = 0; i < len; ++i)
	{
		double max = 0.0;
		int best_bin = 0;
		size_t bins = free_space.size();
		bool found_bin = false;
		for (size_t j = 0; j < bins; ++j)
		{
			if (items[i] < free_space[j] && free_space[j] > max)
			{
				best_bin = j;
				max = free_space[j];
				found_bin = true;
			}
		}
		if (!found_bin)
		{
			free_space.push_back(1.0 - items[i]);
			assignment[i] = bins;
		}
		else
		{
			assignment[i] = best_bin;
			free_space[best_bin] -= items[i];
		}
	}
	print(items);
	print(assignment);
	print(free_space);
}

void best_fit_decreasing(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	std::vector<double> items_copy = items;
	std::sort(items_copy.begin(), items_copy.end());
	reverse(items_copy);
	best_fit(items_copy, assignment, free_space);
}