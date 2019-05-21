#include "project2.h"
#include "functions.h"
#include <algorithm>
#include <map>

void best_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	size_t len = items.size();
	for (size_t i = 0; i < len; ++i)
	{
		double min = 1.1;
		int best_bin = -1;
		size_t bins = free_space.size();
		for (size_t j = 0; j < bins; ++j)
		{
			if (items[i] < free_space[j] && free_space[j] < min)
			{
				best_bin = j;
				min = free_space[j];
			}
		}
		if (best_bin == -1)
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
	/*print(items);
	print(assignment);
	print(free_space);*/
}

void best_fit_decreasing(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	std::map<double, int> m;
	size_t len = items.size();
	for (size_t i = 0; i < len; ++i)
	{
		m[items[i]] = i;
	}
	std::vector<double> items_copy = items;
	std::sort(items_copy.rbegin(), items_copy.rend());
	best_fit(items_copy, assignment, free_space);
	std::vector<int> temp = assignment;
	for (int i = 0; i < len; ++i)
	{
		assignment[m[items_copy[i]]] = temp[i];
	}
	/*print(items_copy);
	print(assignment);
	print(free_space);*/
}