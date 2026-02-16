//
// Language Accepted
//   L = { a(bb)^n b c | n ≥ 0 }
// In words:
//   All strings that start with a, contain even number of bs before final bc, and end with bc
//

#include <iostream>
using namespace std;

bool runDFA(char str[])
{
    int i = 0;
    goto Q0;

Q0:
    if (str[i] == 'a')
    {
        i++;
        goto Q1;
    }
    goto REJECT;

Q1:
    if (str[i] == 'b')
    {
        i++;
        goto Q2;
    }
    goto REJECT;

Q2:
    if (str[i] == 'b')
    {
        i++;
        goto Q1;
    }
    if (str[i] == 'c')
    {
        i++;
        goto Q3;
    }
    goto REJECT;

Q3:
    if (str[i] == '\0') goto ACCEPT;
    goto REJECT;

ACCEPT:
    return true;

REJECT:
    return false;
}

int main()
{
    char tests[][20] = {
        "abc", "abbc", "abcd", "abbbc", "abbbbc"
    };

    cout << "TASK 1 RESULTS\n";
    for (int i = 0; i < 5; i++)
    {
        cout << tests[i] << " : ";
        if (runDFA(tests[i]))
            cout << "ACCEPTED\n";
        else
            cout << "REJECTED\n";
    }
    return 0;
}
