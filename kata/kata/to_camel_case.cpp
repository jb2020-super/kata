#include <cstdio>
#include <cstdlib>
#include <string>
#include <ctime>
#include "gtest/gtest.h"

// https://www.codewars.com/kata/517abf86da9663f1d2000003/solutions/cpp
std::string to_camel_case(std::string text) {
	std::string camel;
	bool need_toupper{ false };

	for (auto ch : text) {
		if (ch == '-' || ch == '_') {
			need_toupper = true;
		}
		else if (need_toupper) {
			camel.push_back(toupper(ch));
			need_toupper = false;
		}
		else {
			camel.push_back(ch);
		}
	}
	return camel;
}

TEST(ToCamelCase, BasicCases)
{
	EXPECT_EQ(to_camel_case(""), "");
	EXPECT_EQ(to_camel_case("the_stealth_warrior"), "theStealthWarrior");
	EXPECT_EQ(to_camel_case("The-Stealth-Warrior"), "TheStealthWarrior");
	EXPECT_EQ(to_camel_case("A-B-C"), "ABC");
}

TEST(ToCamelCase, RandomCases)
{
	srand(time(NULL));
	std::string word = "";

	std::string new_word = "";
	std::string camel_sol = "";
	for (int i = 0; i < 10; i++)
	{
		std::string words[] = { "the", "The", "a", "A" };
		new_word = words[rand() % 4];
		camel_sol += new_word;
		word += new_word;

		std::string words2[] = { "-", "_" };
		word += words2[rand() % 2];

		std::string words3[] = { "cat", "Cat", "pippi", "Pippi" };
		new_word = words3[rand() % 4];
		camel_sol += (new_word == "cat" || new_word == "Cat") ? "Cat" : "Pippi";
		word += new_word;

		word += words2[rand() % 2];

		std::string words4[] = { "is", "was", "Is", "Was" };
		new_word = words4[rand() % 4];
		camel_sol += (new_word == "is" || new_word == "Is") ? "Is" : "Was";
		word += new_word;

		word += words2[rand() % 2];

		std::string words5[] = { "cute","Savage","pippi","Pippi","kawaii",
							  "Omoshiroi","evil","Hungry" };
		new_word = words5[rand() % 8];
		if (new_word == "cute") { camel_sol += "Cute"; }
		else if (new_word == "Savage") { camel_sol += "Savage"; }
		else if (new_word == "pippi" || new_word == "Pippi")
		{
			camel_sol += "Pippi";
		}
		else if (new_word == "kawaii") { camel_sol += "Kawaii"; }
		else if (new_word == "Omoshiroi") { camel_sol += "Omoshiroi"; }

		else if (new_word == "evil") { camel_sol += "Evil"; }
		else if (new_word == "Hungry") { camel_sol += "Hungry"; }
		word += new_word;
		EXPECT_EQ(to_camel_case(word), camel_sol);
	}
}