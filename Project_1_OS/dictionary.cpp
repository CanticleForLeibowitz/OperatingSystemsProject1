#include <iostream>
#include <unordered_map>

static std::unordered_map<std::string, std::string> dictionary()
{
	std::unordered_map <std::string, std::string> dict;
	dict["cat"] = "noun";
	dict["dog"] = "noun";
	dict["house"] = "noun";
	dict["car"] = "noun";
	dict["job"] = "noun";
	dict["food"] = "noun";
	dict["school"] = "noun";
	dict["man"] = "noun";
	dict["woman"] = "noun";
	dict["child"] = "noun";
	dict["run"] = "verb";
	dict["work"] = "verb";
	dict["jump"] = "verb";
	dict["read"] = "verb";
	dict["stop"] = "verb";
	dict["bring"] = "verb";
	dict["sleep"] = "verb";
	dict["give"] = "verb";
	dict["turn"] = "verb";
	dict["listen"] = "verb";
	return dict;
}