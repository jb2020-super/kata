#include "common.h"
// Product of consecutive Fib numbers
// https://www.codewars.com/kata/5541f58a944b85ce6d00006a/solutions/cpp

typedef unsigned long long ull;
class ProdFib
{
public:
	static std::vector<ull> productFib(ull prod)
	{
		std::vector<ull> result;
		bool equal = false;
		ull f0 = 0, f1 = 1;
		do
		{
			ull prod01 = f0 * f1;
			if (prod01 == prod) {
				equal = true;
				break;
			}
			else if (prod01 > prod) {
				break;
			}
			ull f2 = f0 + f1;
			f0 = f1;
			f1 = f2;
		} while (true);
		result.push_back(f0);
		result.push_back(f1);
		result.push_back(equal ? 1ull : 0ull);
		return result;
	}

	static std::vector<ull> productFib_clever(ull prod)
	{
		ull a = 0, b = 1;
		while (a * b < prod) {
			std::swap(a, b);
			b += a;
		}
		return { a, b, ((a*b == prod) ? true : false) };
	}

	static bool compare(const std::vector<ull>& first, const std::vector<ull>& last)
	{
		if (first.size() != 3 || last.size() != 3) {
			return false;
		}
		if (first[0] != last[0])
			return false;
		if (first[1] != last[1])
			return false;
		if (first[2] != last[2])
			return false;
		return true;
	}
};




TEST(ProdFib, BasicTest)
{	
	EXPECT_TRUE(ProdFib::compare(ProdFib::productFib(4895), { 55, 89, 1ULL }));
	EXPECT_TRUE(ProdFib::compare(ProdFib::productFib(5895), { 89, 144, 0ULL }));
	EXPECT_TRUE(ProdFib::compare(ProdFib::productFib(74049690), { 6765, 10946, 1ULL }));
	EXPECT_TRUE(ProdFib::compare(ProdFib::productFib(84049690), { 10946, 17711, 0ULL }));
	EXPECT_TRUE(ProdFib::compare(ProdFib::productFib(193864606), { 10946, 17711, true }));
	EXPECT_TRUE(ProdFib::compare(ProdFib::productFib(447577), { 610, 987, false }));
	EXPECT_TRUE(ProdFib::compare(ProdFib::productFib(602070), { 610, 987, true }));
}
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine gen(seed);

void randomtesting()
{
	std::vector<int> data =
	{
	55,89,144,233,377,610,987,1597,2584,4181,6765,
	10946,17711,28657,46368,75025,121393,196418,317811,514229,
	832040,1346269,2178309,3524578,5702887,9227465,14930352,
	24157817,39088169,63245986
	};
	std::uniform_int_distribution<int> uni1(0, 28);
	for (int n = 0; n < 15; ++n)
	{
		int rn = uni1(gen);
		int f1 = data[rn];
		int f2 = data[rn + 1];
		ull p = static_cast<ull>(f1) * static_cast<ull>(f2);
		std::vector<ull> sol = { static_cast<ull>(f1), static_cast<ull>(f2), 1ULL };
		EXPECT_TRUE(ProdFib::compare(ProdFib::productFib(p), sol));
	}
}

TEST(ProdFib, RandomTest)
{
	randomtesting();
}
