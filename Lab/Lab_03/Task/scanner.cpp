#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* TINY Keywords */
string keywords[] = {
    "read", "write", "if", "then",
    "else", "end", "repeat", "until"
};

ifstream inputFile;
ofstream outputFile;
char ch;

/* Check character types */
bool isLetter(char c) { return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'); }
bool isDigit(char c) { return (c >= '0' && c <= '9'); }
bool isWhite(char c) { return (c == ' ' || c == '\n' || c == '\t' || c == '\r'); }

/* Check if word is a keyword */
bool isKeyword(string word){
    for (int i = 0; i < 8; i++)
        if (word == keywords[i]) return true;
    return false;
}
/* Safe getChar with EOF handling */
bool getChar(){
    return inputFile.get(ch) ? true : false;
}
/* Skip whitespace */
void skipWhite(){
    while (isWhite(ch) && !inputFile.eof()) getChar();
}
/* Skip comment */
void skipComment()
{
    if (ch == '{')
    {
        while (getChar() && ch != '}')
        {
        }
        getChar(); // move after '}'
    }
}
/* Get next token */
bool getNextToken(){
    // Skip whitespaces and comments
    while (true)
    {
        if (inputFile.eof()) return false;
        if (isWhite(ch)) skipWhite();
        else if (ch == '{') skipComment();
        else break;
    }

    string buffer = "";
    // Identifier or keyword
    if (isLetter(ch))
    {
        while (isLetter(ch) && !inputFile.eof())
        {
            buffer += ch;
            getChar();
        }
        if (isKeyword(buffer))
            outputFile << "Keyword: " << buffer << endl;
        else
            outputFile << "Identifier: " << buffer << endl;
        return true;
    }
    // Number
    if (isDigit(ch))
    {
        while (isDigit(ch) && !inputFile.eof())
        {
            buffer += ch;
            getChar();
        }
        outputFile << "Number: " << buffer << endl;
        return true;
    }
    // Operators and symbols
    switch (ch)
    {
    case '+': outputFile << "Operator: +" << endl;
        break;
    case '-': outputFile << "Operator: -" << endl;
        break;
    case '*': outputFile << "Operator: *" << endl;
        break;
    case '/': outputFile << "Operator: /" << endl;
        break;
    case '<': outputFile << "Operator: <" << endl;
        break;
    case '=': outputFile << "Operator: =" << endl;
        break;
    case ';': outputFile << "Semicolon: ;" << endl;
        break;
    case '(': outputFile << "Left Parenthesis: (" << endl;
        break;
    case ')': outputFile << "Right Parenthesis: )" << endl;
        break;
    case ':':
        if (getChar() && ch == '='){
            outputFile << "Assignment Operator: :=" << endl;
            getChar(); // move after '='
        }
        else{
            outputFile << "Invalid Token" << endl;
        }
        return true;
    default:
        if (!inputFile.eof()) getChar(); // skip unknown
        return true;
    }
    getChar();
    return true;
}

int main(){
    inputFile.open("input.tiny");
    outputFile.open("output.tiny");

    if (!inputFile){
        cout << "Input file not found!" << endl;
        return 1;
    }

    if (!getChar()){
        cout << "Input file is empty." << endl;
        return 0;
    }
    while (getNextToken()); // stop at EOF

    inputFile.close();
    outputFile.close();
    cout << "Lexical Analysis Completed. Check output.txt for tokens." << endl;
    return 0;
}
