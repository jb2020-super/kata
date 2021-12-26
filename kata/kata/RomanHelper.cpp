#include "common.h"

// https://www.codewars.com/kata/51b66044bce5799a7f000003/solutions/cpp
class RomanHelper {
public:
	RomanHelper() {
		_romans[0][0] = 'I';
		_romans[0][1] = 'V';
		_romans[1][0] = 'X';
		_romans[1][1] = 'L';
		_romans[2][0] = 'C';
		_romans[2][1] = 'D';
		_romans[3][0] = 'M';
	}
	std::string to_roman(unsigned int n) {
		if (n < 1 || n >= 4000) {
			return "";
		}		
		int digits[4];
		int idx = 0;
		while (n) {
			digits[idx++] = n % 10;
			n /= 10;
		}
		std::string rn;
		for (int i = idx - 1; i >= 0; --i) {
			switch (digits[i])
			{
			case 1:
			case 2:
			case 3:
				for (int j = 0; j < digits[i]; ++j) {
					rn.push_back(_romans[i][0]);
				}
				break;
			case 4:
				rn.push_back(_romans[i][0]);
				rn.push_back(_romans[i][1]);
				break;
			case 5:
				rn.push_back(_romans[i][1]);
				break;
			case 6:
			case 7:
			case 8:
				rn.push_back(_romans[i][1]);
				for (int j = 0; j < digits[i] - 5; ++j) {
					rn.push_back(_romans[i][0]);
				}
				break;
			case 9:
				rn.push_back(_romans[i][0]);
				rn.push_back(_romans[i + 1][0]);
				break;
			default:
				break;
			}
		}
		return rn;
	}
	int from_roman(std::string rn) {
		int num = 0;
		int len = rn.size();
		for (int i = 0; i < len; ++i) {
			switch (rn[i])
			{
			case 'I':
				if (i + 1 < len && (rn[i + 1] == 'V' || rn[i + 1] == 'X')) {
					num -= 1;
				}
				else
				{
					num += 1;
				}
				break;
			case 'V':
				num += 5;
				break;
			case 'X':
				if (i + 1 < len && (rn[i + 1] == 'L' || rn[i + 1] == 'C')) {
					num -= 10;
				}
				else
				{
					num += 10;
				}
				break;
			case 'L':
				num += 50;
				break;
			case 'C':
				if (i + 1 < len && (rn[i + 1] == 'D' || rn[i + 1] == 'M')) {
					num -= 100;
				}
				else {
					num += 100;
				}
				break;
			case 'D':
				num += 500;
				break;
			case 'M':
				num += 1000;
				break;
			default:
				break;
			}
		}
		return num;
	}
private:
	char _romans[4][2];
}RomanNumerals;

TEST(RomanHelper, BasicCase)
{
	EXPECT_EQ(RomanNumerals.to_roman(1000), "M");
	EXPECT_EQ(RomanNumerals.to_roman(4), "IV");
	EXPECT_EQ(RomanNumerals.to_roman(1), "I");
	EXPECT_EQ(RomanNumerals.to_roman(9), "IX");
	EXPECT_EQ(RomanNumerals.to_roman(1990), "MCMXC");
	EXPECT_EQ(RomanNumerals.to_roman(2008), "MMVIII");
	EXPECT_EQ(RomanNumerals.to_roman(3999), "MMMCMXCIX");

	EXPECT_EQ(RomanNumerals.from_roman("XXI"), 21);
	EXPECT_EQ(RomanNumerals.from_roman("I"), 1);
	EXPECT_EQ(RomanNumerals.from_roman("IX"), 9);
	EXPECT_EQ(RomanNumerals.from_roman("IV"), 4);
	EXPECT_EQ(RomanNumerals.from_roman("MMVIII"), 2008);
	EXPECT_EQ(RomanNumerals.from_roman("MDCLXVI"), 1666);
}

class Solution {
private:
	char romanD[7] = { 'I','V','X','L','C','D','M' };

public:
	std::string to_roman(unsigned int n) {
		std::string strtmp, roman = "";
		int N;
		unsigned base = 1;

		if (n >= 4000)
			return "";

		while (n > 0) {
			strtmp = "";
			N = n % 10;
			if (N == 4) {
				roman = this->romanD[(base - 1) * 2 + 1] + roman;
				roman = this->romanD[(base - 1) * 2] + roman;
			}
			else if (N == 9) {
				roman = this->romanD[(base - 1) * 2 + 2] + roman;
				roman = this->romanD[(base - 1) * 2] + roman;
			}
			else {
				strtmp.append((N % 5), this->romanD[(base - 1) * 2]);
				roman = strtmp + roman;
				if (N >= 5)
					roman = this->romanD[(base - 1) * 2 + 1] + roman;
			}
			base = base + 1;
			n = n / 10;
		}
		return roman;
	}

	int from_roman(std::string rn) {
		int base = 0;
		int b10 = 0;
		int rnlen = rn.length();
		int i = rnlen - 1;

		while (i >= 0) {
			if (this->romanD[base * 2] == rn[i]) {
				if (i < (rnlen - 1) && this->romanD[base * 2 + 1] == rn[i + 1]) {
					b10 = b10 - pow(10, base);
				}
				else if (i < (rnlen - 1) && this->romanD[base * 2 + 2] == rn[i + 1]) {
					b10 = b10 - pow(10, base);
				}
				else {
					b10 = b10 + pow(10, base);
				}
			}
			else if (this->romanD[base * 2 + 1] == rn[i]) {
				b10 = b10 + (5 * pow(10, base));
			}
			else if (this->romanD[base * 2 + 2] == rn[i]) {
				b10 = b10 + (10 * pow(10, base));
			}
			else {
				base = base + 1;
				i = i + 1;
			}

			if (b10 >= 3999) {
				break;
			}
			i = i - 1;
		}
		return b10;
	}
} solution;

TEST(RomanHelper, RandomToRoman)
{
	srand(time(nullptr));

	for (int i = 0; i < 100; i++) {
		int n = (rand() % 3999) + 1;
		EXPECT_EQ(RomanNumerals.to_roman(n), solution.to_roman(n));
	}
}

TEST(RomanHelper, RandomFromRoman)
{
	srand(time(nullptr));

	for (int i = 0; i < 100; i++) {
		int n = (rand() % 3999) + 1;
		std::string roman = solution.to_roman(n);
		EXPECT_EQ(RomanNumerals.from_roman(roman), solution.from_roman(roman));
	}
}

#include <unordered_map>

using namespace std;

class Cleverest {
public:
	string to_roman(int num) {
		string r[13] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
		int n[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		string rnum = "";
		for (int i = 0; i < 13; ++i) {
			while (num >= n[i]) {
				num -= n[i];
				rnum += r[i];
			}
		}
		return rnum;
	}

	int from_roman(string rnum) {
		unordered_map<char, int> ri = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
		int n = rnum.size(), res = 0;
		for (int i = 0; i < n; ++i) {
			if (i + 1 < n && ri[rnum[i]] < ri[rnum[i + 1]])
				res -= ri[rnum[i]];
			else res += ri[rnum[i]];
		}
		return res;
	}
};