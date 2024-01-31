#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

static std::unordered_map<std::string, std::string> dictionary() {
  std::unordered_map<std::string, std::string> dict;
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
  dict["hide"] = "verb";
  dict["you"] = "pronoun";
  dict["he"] = "pronoun";
  dict["she"] = "pronoun";
  dict["it"] = "pronoun";
  dict["we"] = "pronoun";
  dict["they"] = "pronoun";
  dict["me"] = "pronoun";
  dict["him"] = "pronoun";
  dict["her"] = "pronoun";
  return dict;
}

std::vector<std::string> matchString(std::string entry) {
  std::string word;
  std::string keys;
  std::vector<std::string> values;
  std::vector<std::string> words;
  
  for(int i = 0; i <= entry.size(); i++){
    if (!isspace(entry[i])){
      keys = keys + entry[i];
    }
    else{
    keys = "";  
    }
    for (auto x : dictionary()) {
      if (keys == x.first) {
        word = "\n Word: " + x.first + " " + "Category: " + x.second+"\n";
        words.push_back(word);
        //std::cout<<word;
        keys = "";
      } else 
        word = "\n Category: external\n";
    }
  }
  
  
  for(int i = 0; i < words.size(); i++){
    std::cout<<words[i];
  }

  return words;
}

static int count(std::string str, char countChar) {
  int count = 0;

  for (int i = 0; i < str.size(); i++) {
    if (str[i] == countChar) {
      count++;
    }
  }

  return count;
}

static std::string removeComments(std::string str) {
  int start = 0;
  /*

  base case: pdLoc == -1; return str
  1. find pound symbol - store position in pdLoc
  2. count " and ' behind it
  3. if both are even, return str.substr(0, pdLoc)
  4. if either is odd, move start up to pdLoc
  */
  while (true) {

    int pdLoc = str.find('#', start);

    if (pdLoc == std::string::npos) {
      return str;
    }
    std::string beforePd = str.substr(0, pdLoc);

    if (count(beforePd, '\'') % 2 == 0 && count(beforePd, '"') % 2 == 0) {
      return str.substr(0, pdLoc);
    }

    start = pdLoc + 1;
  }
}

std::vector<std::string> readFileIntoVector(std::string fileName) {

  std::vector<std::string> lines;
  std::string currLine;

  // Read from the text file
  std::ifstream inputFile(fileName);

  if (!inputFile.is_open()) {
    std::cerr << "Error opening file: " << fileName << std::endl;
  }

  bool concatWithLast = false;

  while (getline(inputFile, currLine)) {
    // 1. Various consecutive blank characters (space and tab) are identical to
    // a single space character.

    /*
    3. A pond-sign character (#) and its following characters up to a newline
    character are ignored unless the pond-sign character is not surrounded by a
    pair of single quotes or a pair of double quotes. It is called a “comment”.
    Of course, after ignoring the character and its followings, if the line
    contains only blank characters, the line is completely ignored.

    */

    currLine = removeComments(currLine);

    /*
    4. A line ending with a backslash and a newline character without
    interruption between them is called “continuation”. If a line ends with the
    continuation, the next line is concatenated to the current line. Be aware
    that a line ending with a comment cannot contain a continuation
    */

    if (concatWithLast) {
      currLine = lines.back() + currLine;
      lines.pop_back();
      concatWithLast = false;
    }

    if (!(currLine.empty()) && currLine.back() == '\\') {
      {
        concatWithLast = true;
        currLine.pop_back();
      }
    }

    // 2. A blank line is ignored.
    if (currLine.find_first_not_of(' ') != std::string::npos) {
      lines.push_back(currLine);
    }
  }

  // Close the file
  inputFile.close();

  return lines;
}

int main() {
  std::vector<std::string> answer;
  std::vector<std::string> inputLines = readFileIntoVector("InputFile.txt");
  	//Opens file, error handling for if the file can't open
	std::ifstream inputFile("InputFile.txt");
	if (!inputFile.is_open()) {
		std::cerr << "Failed to open input file." << std::endl;
		return 1;
	}
  for (size_t i = 0; i < inputLines.size(); i++) {
    matchString(inputLines[i]);
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

