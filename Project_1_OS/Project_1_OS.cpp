// Project_1_OS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>


// std::string::npos == -1

static int count(std::string str, char countChar)
{
    int count = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == countChar)
        {
            count++;
        }     
    }

    return count;
}




static std::string removeComments(std::string str)
{
    int start = 0;
    /*

    base case: pdLoc == -1; return str
    1. find pound symbol - store position in pdLoc
    2. count " and ' behind it
    3. if both are even, return str.substr(0, pdLoc)
    4. if either is odd, move start up to pdLoc
    */
    while (true)
    {

        int pdLoc = str.find('#', start);

        if (pdLoc == std::string::npos)
        {
            return str;
        }
        std::string beforePd = str.substr(0, pdLoc);

        if (count(beforePd, '\'') % 2 == 0 && count(beforePd, '"') % 2 == 0)
        {
            return str.substr(0, pdLoc);
        }

        start = pdLoc + 1;

    }

}



std::vector<std::string> readFileIntoArray(std::string fileName)
{
    
    std::vector<std::string> lines;
    std::string currLine;

    // Read from the text file
    std::ifstream inputFile(fileName);



    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
    }
    
    bool concatWithLast = false;

    while (getline(inputFile, currLine))
    {
        //1. Various consecutive blank characters (space and tab) are identical to a single space character.
       


        

        /*
        3. A pond-sign character (#) and its following characters up to a newline character are ignored
        unless the pond-sign character is not surrounded by a pair of single quotes or a pair of double
        quotes. It is called a “comment”. Of course, after ignoring the character and its followings, if the
        line contains only blank characters, the line is completely ignored.

        */

        currLine = removeComments(currLine);

        /*
        4. A line ending with a backslash and a newline character without interruption between them is
        called “continuation”. If a line ends with the continuation, the next line is concatenated to the
        current line. Be aware that a line ending with a comment cannot contain a continuation
        */

        if (currLine.substr(currLine.size() - 1, currLine.size()) == "\\")
        {
            concatWithLast = true;
            currLine = currLine.substr(0, currLine.size()-1);
            
        }

        if (concatWithLast)
        {
            std::string temp = lines.back() + currLine;

        }

        
        //2. A blank line is ignored.
        if (currLine.find_first_not_of(' ') != std::string::npos)
        {
            lines.push_back(currLine);
        }
    }

    // Close the file
    inputFile.close();

    return lines;

}

int main()
{
    std::vector<std::string> inputLines = readFileIntoArray("InputFile.txt");

    for (size_t i = 0; i < inputLines.size(); i++)
    {
        std::cout << inputLines[i] << std::endl;
    }


    
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
