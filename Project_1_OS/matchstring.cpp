#include <iostream>
#include <unordered_map>
#include <string>
#include "dictionary.cpp"

static std::string matchString(std::string entry)
{
	std::string word;
	std::unordered_map<std::string, std::string> dict;
	dict = dictionary();
	for (auto x : dict) {
		if (entry == x.first)
		{
			word = "Word: " + x.first + " " + "Category: " + x.second;
			break;
		}
		else
		{
			word = "external";
		}
	}

	return word;

}