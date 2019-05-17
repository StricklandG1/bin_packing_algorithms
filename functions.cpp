#include "functions.h"
#include <iostream>
#include <random>
#include <fstream>

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

	double count = items_total(items);
	std::cout << "------------------------------- NEXT FIT -------------------------------\n\n";
	next_fit(items, assignment, bins);
	double waste = count - bins.size();
	write_to_file("next_fit", set_size, waste);
	bins.clear();
	bins.push_back(1.0);
	std::cout << "-------------------------------------------------------------------------------------------------\n\n";

	std::cout << "------------------------------- FIRST FIT -------------------------------\n\n";
	first_fit(items, assignment, bins);
	waste = count - bins.size();
	write_to_file("first_fit", set_size, waste);
	bins.clear();
	bins.push_back(1.0);
	std::cout << "--------------------------------------------------------------------------------------------------\n\n";

	std::cout << "------------------------------- FIRST FIT DECREASING -------------------------------\n\n";
	first_fit_decreasing(items, assignment, bins);
	waste = count - bins.size();
	write_to_file("first_fit_decreasing", set_size, waste);
	bins.clear();
	bins.push_back(1.0);
	std::cout << "--------------------------------------------------------------------------------------------------\n\n";

	std::cout << "------------------------------- BEST FIT -------------------------------\n\n";
	best_fit(items, assignment, bins);
	waste = count - bins.size();
	write_to_file("best_fit", set_size, waste);
	bins.clear();
	bins.push_back(1.0);
	std::cout << "--------------------------------------------------------------------------------------------------\n\n";

	std::cout << "------------------------------- BEST FIT DECREASING -------------------------------\n\n";
	best_fit_decreasing(items, assignment, bins);
	waste = count - bins.size();
	write_to_file("best_fit_decreasing", set_size, waste);
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

double items_total(const std::vector<double>& v)
{
	double result = 0.0;
	size_t len = v.size();
	for (size_t i = 0; i < len; ++i)
	{
		result += v[i];
	}
	return result;
}

void write_to_file(const std::string& file, int set_size, double waste)
{
	std::ofstream out_file;
	std::string fname = file + ".txt";
	out_file.open(fname, std::ofstream::app);

	out_file << file << "," << set_size << "," << waste << "\r\n";

	out_file.close();
}