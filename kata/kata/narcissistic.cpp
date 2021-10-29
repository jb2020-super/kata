#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "gtest/gtest.h"

// https://www.codewars.com/kata/5287e858c6b5a9678200083c/cpp
bool narcissistic(int value) {
	//Code away
	int sum = 0;
	int digits[10];
	int digits_cnt = 0;
	int value_org = value;
	int i;
	for (i = 0; value; ++i) {
		digits[i] = value % 10;
		value /= 10;
	}
	digits_cnt = i;
	int digits_pow[10];
	for (int i = 0; i < digits_cnt; ++i) {
		digits_pow[i] = 1;
	}
	for (int i = 0; i < digits_cnt; ++i) {
		for (int j = 0; j < digits_cnt; ++j) {
			digits_pow[i] *= digits[i];
		}
	}
	for (int i = 0; i < digits_cnt; ++i) {
		sum += digits_pow[i];
	}
	//std::cout << sum << std::endl;
	return value_org == sum;
}


bool narcissistic_clever(int value) {

	int n = value;
	int i = log10(value) + 1; //get the number of digits in "number"
	int sum = 0;

	while (n) {
		sum += pow(n % 10, i);
		n /= 10;
	}

	return sum == value;
}

void test_Narcissistic(bool (*pnarcissistic)(int)) {
	EXPECT_EQ(narcissistic(1), true);
	EXPECT_EQ(narcissistic(5), true);
	EXPECT_EQ(narcissistic(7), true);

	EXPECT_EQ(narcissistic(153), true);
	EXPECT_EQ(narcissistic(370), true);
	EXPECT_EQ(narcissistic(371), true);
	EXPECT_EQ(narcissistic(1634), true);

	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		int num = (rand() % 5 + 5) * 60000 + (rand() % 99 + 1);
		EXPECT_EQ(narcissistic(num), false);
	}

	std::vector<int> bignums = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 153, 370, 371, 407, 1634, 8208, 9474, 54748, 92727, 93084, 548834, 1741725,
							4210818, 9800817, 9926315, 24678050, 24678051 };
	for (int b : bignums) {
		if (rand() % 11 > 5)
			EXPECT_EQ(narcissistic(b), true);
		else {
			int num = (rand() % 5 + 5) * 900000 + (rand() % 99 + 1);
			EXPECT_EQ(narcissistic(num), false);
		}
	}
}

TEST(Narcissistic, MySolution) {
	test_Narcissistic(narcissistic);
}

TEST(Narcissistic, CleverSolution) {
	test_Narcissistic(narcissistic_clever);
}