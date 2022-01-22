#include "common.h"
// cleverest
//class add
//{
//public:
//	add(int x) : _x(x) { }
//	operator int() { return _x; }
//	add operator() (int y) { return add(_x + y); }
//	friend bool operator==(const int& a, const add& b) { return a == b._x; }
//
//private:
//	int _x;
//};

/**/
class ChainAdd {
public:
	ChainAdd() {}
	ChainAdd(int a):
		m_a{ a }
	{

	}
	ChainAdd operator ()(int n) {
		return  ChainAdd(m_a + n);
	}
	int operator + (int n) {
		return m_a + n;
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

std::ostream& operator<<(std::ostream &os, const ChainAdd &ca)
{
	os << ca;
	return os;
}

auto add(int n)
{
	return ChainAdd(n);
}

TEST(ChainAdding, BasicCase)
{	
	EXPECT_EQ(add(1), 1);
	EXPECT_EQ(add(1)(2), 3);
	EXPECT_EQ(add(1)(2)(3), 6);
}