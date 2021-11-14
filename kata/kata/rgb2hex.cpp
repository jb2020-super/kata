#include "common.h"

// https://www.codewars.com/kata/513e08acc600c94f01000001/
class RGBToHex
{
public:
	const static int BUFFER_SIZE = 20;
	static void clamp(int &a) {
		if (a < 0) {
			a = 0;
		}
		else if (a > 255) {
			a = 255;
		}
	}
	static std::string rgb(int r, int g, int b) {
		clamp(r);
		clamp(g);
		clamp(b);
		char buf[BUFFER_SIZE];
		snprintf(buf, BUFFER_SIZE, "%02X%02X%02X", r, g, b);
		return std::string(buf);
	}
};

TEST(RGBToHex, BasicCase)
{
	EXPECT_EQ(RGBToHex::rgb(0, 0, 0), "000000");
	EXPECT_EQ(RGBToHex::rgb(1, 2, 3), "010203");
	EXPECT_EQ(RGBToHex::rgb(255, 255, 255), "FFFFFF");
	EXPECT_EQ(RGBToHex::rgb(254, 253, 252), "FEFDFC");
	EXPECT_EQ(RGBToHex::rgb(-20, 275, 125), "00FF7D");
}

// Expected test solution
std::string testRGB(int r, int g, int b)
{
	std::ostringstream oss;
	oss << std::uppercase << std::setfill('0') << std::hex
		<< std::setw(2) << (r < 0 ? 0 : r > 255 ? 255 : r)
		<< std::setw(2) << (g < 0 ? 0 : g > 255 ? 255 : g)
		<< std::setw(2) << (b < 0 ? 0 : b > 255 ? 255 : b);
	return oss.str();
}
TEST(RGBToHex, RandomCase)
{
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		int r = (rand() % 256) + (int)(pow(-1, rand() % 2)) * (rand() % 256);
		int g = (rand() % 256) + (int)(pow(-1, rand() % 2)) * (rand() % 256);
		int b = (rand() % 256) + (int)(pow(-1, rand() % 2)) * (rand() % 256);
		EXPECT_EQ(RGBToHex::rgb(r, g, b), testRGB(r, g, b));
	}
}