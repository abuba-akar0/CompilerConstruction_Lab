#include <iostream>
#include <string>

using namespace std;

// Global variables for the parser
string input;
int pos_index = 0;

// Function prototypes for non-terminals
void Stmtseq();
void Stmt();
void Exp();

// Helper function to check and consume the expected token
bool match(const string& expected) {
    if (input.substr(pos_index, expected.length()) == expected) {
        pos_index += expected.length();
        return true;
    }
    return false;
}

// Helper function to enforce exact syntax and throw errors for erroneous inputs
void require(const string& expected) {
    if (!match(expected)) {
        cout << "\nParsing Error: Expected '" << expected << "' at position " << pos_index << "\n";
        cout << "String Rejected\n";
        exit(1);
    }
}

// Implementation of: Stmtseq -> Stmt {; Stmt}
void Stmtseq() {
    cout << "Parsing Stmtseq -> Stmt {; Stmt}" << endl;

    // Check if the current token is the start of a valid statement ('if')
    if (input.substr(pos_index, 2) == "if") {
        Stmt();
        // Handle optional repeating statements separated by ';'
        while (input.substr(pos_index, 1) == ";") {
            match(";");
            Stmt();
        }
    }
}

// Implementation of: Stmt -> if Exp then Stmtseq [else Stmtseq] end
void Stmt() {
    cout << "Parsing Stmt -> if Exp then Stmtseq [else Stmtseq] end" << endl;

    require("if");
    Exp();
    require("then");
    Stmtseq();

    // Handle optional 'else' block
    if (input.substr(pos_index, 4) == "else") {
        cout << "Found else, parsing else Stmtseq" << endl;
        require("else");
        Stmtseq();
    }

    require("end");
    cout << "End of Stmt" << endl;
}

// Implementation of: Exp -> 0 | 1
void Exp() {
    if (match("0")) {
        cout << "Parsing Exp -> 0" << endl;
    } else if (match("1")) {
        cout << "Parsing Exp -> 1" << endl;
    } else {
        cout << "\nParsing Error: Expected '0' or '1' at position " << pos_index << "\n";
        cout << "String Rejected\n";
        exit(1);
    }
}

int main() {
    // Prompt for input
    cout << "Enter input program: ";
    cin >> input;

    // Reset index to start
    pos_index = 0;

    // Start parsing from the start symbol
    Stmtseq();

    // Determine if the whole input string was consumed successfully
    if (pos_index == input.length()) {
        cout << "Parsing Successful: Input Accepted!" << endl;
    } else {
        cout << "\nString Rejected\n";
    }

    return 0;
}