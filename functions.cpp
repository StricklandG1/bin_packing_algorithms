#include "functions.h"
#include <iostream>
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

void test_set(int set_size)
{
	std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- " << set_size << " *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n\n";
	std::vector<double> items(set_size);
	std::vector<int> assignment(set_size);
	std::vector<double> bins(1, 1.0);

	randomize(items);

	count(items);
	std::cout << "------------------------------- NEXT FIT -------------------------------\n\n";
	next_fit(items, assignment, bins);

	bins.clear();
	bins.push_back(1.0);
	std::cout << "-------------------------------------------------------------------------------------------------\n\n";

	std::cout << "------------------------------- FIRST FIT -------------------------------\n\n";
	first_fit(items, assignment, bins);

	bins.clear();
	bins.push_back(1.0);
	std::cout << "--------------------------------------------------------------------------------------------------\n\n";

	std::cout << "------------------------------- FIRST FIT DECREASING -------------------------------\n\n";
	first_fit_decreasing(items, assignment, bins);

	bins.clear();
	bins.push_back(1.0);
	std::cout << "--------------------------------------------------------------------------------------------------\n\n";

	std::cout << "------------------------------- BEST FIT -------------------------------\n\n";
	best_fit(items, assignment, bins);

	bins.clear();
	bins.push_back(1.0);
	std::cout << "--------------------------------------------------------------------------------------------------\n\n";

	std::cout << "------------------------------- BEST FIT DECREASING -------------------------------\n\n";
	best_fit_decreasing(items, assignment, bins);
}

void print(const std::vector<double>& v)
{
	size_t len = v.size();
	for (size_t i = 0; i < len; ++i)
	{
		std::cout << v[i] << " ";
	}
	std::cout << "\n\n";
}

void print(const std::vector<int>& v)
{
	size_t len = v.size();
	for (size_t i = 0; i < len; ++i)
	{
		std::cout << v[i] << " ";
	}
	std::cout << "\n\n";
}

void reverse(std::vector<double>& v)
{
	size_t i = 0;
	size_t j = v.size() - 1;
	while (i < j)
	{
		double temp = v[i];
		v[i] = v[j];
		v[j] = temp;
		++i;
		--j;
	}
}

double count(const std::vector<double>& v)
{
	double result = 0.0;
	size_t len = v.size();
	for (size_t i = 0; i < len; ++i)
	{
		result += v[i];
	}
	return result;
}