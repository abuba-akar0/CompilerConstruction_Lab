/**
 * Title: Lexer for Tiny Language
 * This program reads a source code file (input.tiny), removes all white spaces and comments,
 * and writes the cleaned code to an output file (output.tiny).
**/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inputFile("input.tiny");
    ofstream outputFile("output.tiny");

    if (!inputFile)
    {
        cout << "Error opening input file!" << endl;
        return 1;
    }

    char ch;
    bool inComment = false;
    bool hasContent = false;

    while (inputFile.get(ch))
    {
        // Start comment
        if (ch == '{')
        {
            inComment = true;
            continue;
        }

        // End comment
        if (ch == '}')
        {
            inComment = false;
            continue;
        }

        // Ignore characters inside comment
        if (inComment)
            continue;

        // Remove spaces and tabs
        if (ch == ' ' || ch == '\t')
            continue;

        // If newline found
        if (ch == '\n')
        {
            if (hasContent)   // Only print newline if line had content
            {
                outputFile << '\n';
                hasContent = false;   // Reset for next line
            }
            continue;
        }

        // If valid character
        outputFile << ch;
        hasContent = true;
    }

    inputFile.close();
    outputFile.close();

    cout << "Whitespace, comments removed and empty lines cleaned!" << endl;

    return 0;
}
