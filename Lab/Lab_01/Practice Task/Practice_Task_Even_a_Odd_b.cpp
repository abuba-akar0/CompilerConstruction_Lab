// C program to implement DFA that accepts
// all strings which follow the language
// L = { a^n b^m ; n mod 2 = 0, m >= 1 }

#include "iostream"
#include <string.h>
// dfa tells the number associated
// string end in which state.
int dfa = 0;
// State encoding (we keep 0..4):
// 0 = a-phase, even number of a's (including 0)
// 1 = a-phase, odd number of a's
// 2 = b-phase, even number of b's (non-accepting)
// 3 = b-phase, odd number of b's (accepting)
// 4 = sink / invalid

// This function is for
// the starting state (Q0) of DFA
void start(char c)
{
    if (c == 'a') {
        dfa = 1; // a-phase: odd a
    }
    else if (c == 'b') {
        dfa = 3; // first b -> b-phase with 1 b (odd)
    }
    else
    {
        // -1 is used to check for any invalid symbol
        dfa = -1;
    }
}

// This function is for the first state (Q1) of DFA
// Q1 = a-phase with odd number of a's
void state1(char c){
    if (c == 'a') {
        dfa = 0; // toggle to even a
    }
    else if (c == 'b') {
        dfa = 4; // odd a then b -> invalid (n must be even before b)
    }
    else {
        dfa = -1;
    }
}

// This function is for the second state (Q2) of DFA
// Q2 = b-phase with even number of b's
void state2(char c){
    if (c == 'b') {
        dfa = 3; // toggle to odd b
    }
    else if (c == 'a') {
        dfa = 4; // 'a' after seeing b => invalid
    }
    else {
        dfa = -1;
    }
}

// This function is for the third state (Q3) of DFA
// Q3 = b-phase with odd number of b's (accepting)
void state3(char c){
    if (c == 'b') {
        dfa = 2; // toggle to even b
    }
    else if (c == 'a') {
        dfa = 4; // 'a' after seeing b => invalid
    }
    else {
        dfa = -1;
    }
}

// This function is for the fourth state (Q4) of DFA
void state4(char c){
    dfa = -1;
}


int isAccepted(char str[])
{
    // reset DFA for each call
    dfa = 0;

    // store length of string
    int i, len = strlen(str);
    for (i = 0; i < len; i++) {
        if (dfa == 0)
            start(str[i]);
        else if (dfa == 1)
            state1(str[i]);
        else if (dfa == 2)
            state2(str[i]);
        else if (dfa == 3)
            state3(str[i]);
        else if (dfa == 4)
            state4(str[i]);
        else
            return 0;
    }
    // accept only if in b-phase with odd number of b's
    if (dfa == 3)
        return 1;
    else
        return 0;
}

int main()
{
    char str[100];
    std::cout << "Enter the string: ";
    std::cin >> str;

    if (isAccepted(str))
        std::cout << "String Accepted\n";
    else
        std::cout << "String Not Accepted\n";
    return 0;
}
