#include "common.h"

class add {
public:
	add() {}
	add(int a):
		m_a{ a }
	{

	}
	add operator ()(int n) {
		return  add(m_a + n);
	}
	bool operator == (const int n) {
		return m_a == n;
	}
	operator int() const {
		return m_a;
	}
	
private:
	int m_a{0};
};

std::ostream& operator<<(std::ostream &os, const add &ca)
{
	os << ca;
	return os;
}



TEST(ChainAdding, BasicCase)
{	
	EXPECT_EQ(add(1), 1);
	EXPECT_EQ(add(1)(2), 3);
	EXPECT_EQ(add(1)(2)(3), 6);
	EXPECT_EQ(add(1)(2)(3)(4), 10);
	EXPECT_EQ(add(1)(2)(3)(4)(5), 15);
}

TEST(ChainAdding, must_be_able_to_store_curried_functions)
{
	auto a = add(1)(2);
	EXPECT_EQ(a(3), 6);


}

TEST(ChainAdding, must_be_able_to_store_values)
{
	auto a = add(1)(2);
	auto b = add(3)(4);
	a(3);
	EXPECT_EQ(a, 3);
	EXPECT_EQ(b, 7);
}

TEST(ChainAdding, must_be_usable_in_a_normal_addition)
{
	auto a = add(1)(2);
	EXPECT_EQ(a + 3, 6);
}

TEST(ChainAdding, must_be_usable_in_a_normal_subtraction)
{
	auto a = add(1)(2);
	EXPECT_EQ(a - 3, 0);
}

TEST(ChainAdding, RandomCase)
{
	srand(time(NULL));
	for (int i = 0; i < 20; ++i)
	{
		int n = rand() % 100, expected = n;
		auto a = add(n);
		for (int j = rand() % 30; j > 0; --j)
		{
			n = rand() % 100;
			expected += n;
			a = a(n);
		}
		EXPECT_EQ(a, expected);
	}
}