#include "project2.h"
#include "functions.h"
#include <algorithm>

void first_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	size_t len = items.size();

	for (size_t i = 0; i < len; ++i)
	{
		size_t bin_len = free_space.size();
		size_t j = 0;
		bool inserted = false;
		while (j < bin_len && !inserted)
		{
			if (items[i] <= free_space[j])
			{
				assignment[i] = j;
				free_space[j] -= items[i];
				inserted = true;
			}
			else
				++j;
		}
		if (!inserted)
		{
			free_space.push_back(1.0 - items[i]);
			assignment[i] = j;
		}
	}
	print(items);
	print(assignment);
	print(free_space);
}

void first_fit_decreasing(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	std::vector<double> items_copy = items;
	std::sort(items_copy.begin(), items_copy.end());
	reverse(items_copy);
	first_fit(items_copy, assignment, free_space);
}