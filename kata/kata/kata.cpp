// kata.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
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
	std::cout << sum << std::endl;
	return value_org == sum;
}

#include <cmath>

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

int main()
{	
    std::cout << narcissistic(12742452);
}


// TODO: add unit test https://github.com/joakimkarlsson/igloo