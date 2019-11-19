#include "project2.h"
#include "functions.h"

const int TINY_SET = 100;
const int SMALL_SET = 1000;
const int MEDIUM_SET = 10000;
const int LARGE_SET = 100000;
const int LARGER_SET = 1000000;
const int BIG_BOI_SET = 10000000;
const int BIGGEST_BOI_SET = 100000000;

int main()
{
	//test_set(10);
	for(int i = 0; i < 5; ++i)
		test_set(TINY_SET);

	for (int i = 0; i < 5; ++i)
		test_set(SMALL_SET);

	for (int i = 0; i < 5; ++i)
		test_set(MEDIUM_SET);

	for (int i = 0; i < 5; ++i)
		test_set(LARGE_SET);

	for (int i = 0; i < 5; ++i)
		test_set(LARGER_SET);

	return 0;
}