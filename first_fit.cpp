#include "project2.h"
#include "functions.h"
#include <algorithm>
#include <map>

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
}

void first_fit_decreasing(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	std::map<double, int> m;
	size_t len = items.size();
	for (size_t i = 0; i < len; ++i)
	{
		m[items[i]] = i;
	}
	std::vector<double> items_copy = items;
	std::sort(items_copy.rbegin(), items_copy.rend());
	first_fit(items_copy, assignment, free_space);
	std::vector<int> temp = assignment;
	for (int i = 0; i < len; ++i)
	{
		assignment[m[items_copy[i]]] = temp[i];
	}
}