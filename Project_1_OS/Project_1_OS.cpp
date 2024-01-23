// Project_1_OS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>


static std::string removeComments(char quoteType, std::string str)
{
    int start = 0;
    int pdPos = -1;

    while (true)
    {
        int quotePos = str.find(quoteType);

        if (quotePos == -1)
        {
            pdPos = str.find('#', start);
            if (pdPos == -1)
            {
                return str;
            }
            else
            {
                return str.substr(start, pdPos);
            }
        }
        std::string beforeQuote = str.substr(start, quotePos);

        int pdPos = beforeQuote.find('#');

        if (pdPos != 1)
            return str.substr(0, pdPos);

        start = str.find(quoteType, quotePos+1) + 1;

    }

}


std::string* readFileIntoArray(std::string fileName)
{
   
    std::vector<std::string> lines;
    std::string currLine;

    // Read from the text file
    std::ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        // Handle the error, return or exit the program if needed
    }
    
    while (getline(inputFile, currLine))
    {
        //1. Various consecutive blank characters (space and tab) are identical to a single space character.
       

        //2. A blank line is ignored.
        
        /*
        3. A pond-sign character (#) and its following characters up to a newline character are ignored
        unless the pond-sign character is not surrounded by a pair of single quotes or a pair of double
        quotes. It is called a “comment”. Of course, after ignoring the character and its followings, if the
        line contains only blank characters, the line is completely ignored.

        int i = 8; # comment 
        string pdStr = "#"
        char pd = '#'
        string pdStr = "#" # the comment is here
        char pd = '#'

        search for " or '

        once found, search for # in substring before

        if # found, set as endpoint and unconsider all other characters

        if not found, search for second "

        recursively call function with substring starting after "


        */



        /*
        4. A line ending with a backslash and a newline character without interruption between them is
        called “continuation”. If a line ends with the continuation, the next line is concatenated to the
        current line. Be aware that a line ending with a comment cannot contain a continuation
        */

        
        // Add final edited string into vector

        lines.push_back(currLine);

    }

    // Close the file
    inputFile.close();

    const size_t n = lines.size();

    std::string * linesArr = new std::string[n];

    copy(lines.begin(), lines.end(), linesArr);

    return linesArr;

}

int main()
{
    std::string * inputLines = readFileIntoArray("InputFile.txt");

    std::string oldLine = "string pdStr = \"#\" # Here is the comment";

    std::cout << removeComments('"', oldLine);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
