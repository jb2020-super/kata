#include "common.h"
// https://www.codewars.com/kata/5262119038c0985a5b00029f/cpp
bool isPrime_fast(int num) {
	if (num <= 1) {
		return false;
	}
	if (num == 2 || num == 3) {
		return true;
	}	
	int num_sqr = floor(sqrt(num) + 0.5);
	for (int i = 6; i <= num_sqr; i += 6) {
		if ((num % (i - 1) == 0) ||
			(num % (i + 1) == 0)
			) 
		{
			return false;
		}
	}
	return true;
}

bool isPrime(int num) {
	if (num <= 1) {
		return false;
	}
	int num_sqr = floor(sqrt(num) + 0.5);
	for (int i = 2; i <= num_sqr; ++i) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

TEST(ISPrime, BasicCase)
{
	EXPECT_EQ(isPrime(-1), false);
	EXPECT_EQ(isPrime(1), false);
	EXPECT_EQ(isPrime(3), true);
	EXPECT_EQ(isPrime(5), true);
	EXPECT_EQ(isPrime(11), true);
	EXPECT_EQ(isPrime(16), false);
	EXPECT_EQ(isPrime(527), false);
	EXPECT_EQ(isPrime(256), false);
}

bool _isPrime(int num) {
	for (int i = 2; i <= sqrt(num); i++) if (num % i == 0) return false;
	return num <= 1 ? false : true;
}

TEST(ISPrime, RandomCase)
{
	srand(time(0));
	for (auto i = 0; i < 1000; i++) {
		int r_number = rand() % 2147483647;		
		EXPECT_EQ(isPrime(r_number), _isPrime(r_number));
	}
}
