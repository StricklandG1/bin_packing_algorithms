#include "project2.h"
#include "functions.h"

void next_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	size_t len = items.size();
	size_t current_bin = 0;
	for (int i = 0; i < len; ++i)
	{
		if (items[i] <= free_space[current_bin])
		{
			assignment[i] = current_bin;
			free_space[current_bin] -= items[i];
		}
		else
		{
			free_space.push_back(1.0 - items[i]);
			++current_bin;
			assignment[i] = current_bin;
		}
	}

	/*print(items);
	print(assignment);
	print(free_space);*/
}
