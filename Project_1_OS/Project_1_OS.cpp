#include <iostream>
#include <fstream>
#include <string>

int main() {
	//Opens file, error handling for if the file can't open
	std::ifstream inputFile("input.txt");
	if (!inputFile.is_open()) {
		std::cerr << "Failed to open input file." << std::endl;
		return 1;
	}

	// 1. Various consecutive blank characters are identical to single space character.
	//Initializes string and boolean, loops through file by character.
	//If character is space, mark boolean as true and skip. Testing using cout to ensure it's only counting one space.
	//If character is not space, mark boolean as false and read as normal. Testing using cout.
	std::string line;
	while (std::getline(inputFile, line)) {
		bool lastCharSpace = false;

		for (char& c : line) {
			if (std::isspace(c)) {
				lastCharSpace = true;
				std::cout << c;
				continue;
			}
			std::cout << c;
			lastCharSpace = false;
		}
	}
}
