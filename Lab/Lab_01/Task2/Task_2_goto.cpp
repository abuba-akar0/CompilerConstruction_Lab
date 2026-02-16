//
// Language:
//   L = { w ∈ {a,b}* | even number of a’s AND even number of b’s }
//

#include <iostream>
using namespace std;

bool runDFA(char str[])
{
    int i = 0;
    goto Q0;

Q0: // even a, even b (start & accept)
    if (str[i] == 'a')
    {
        i++;
        goto Q1;
    }
    if (str[i] == 'b')
    {
        i++;
        goto Q2;
    }
    if (str[i] == '\0') goto ACCEPT;
    goto REJECT;

Q1: // odd a, even b
    if (str[i] == 'a')
    {
        i++;
        goto Q0;
    }
    if (str[i] == 'b')
    {
        i++;
        goto Q3;
    }
    goto REJECT;

Q2: // even a, odd b
    if (str[i] == 'a')
    {
        i++;
        goto Q3;
    }
    if (str[i] == 'b')
    {
        i++;
        goto Q0;
    }
    goto REJECT;

Q3: // odd a, odd b
    if (str[i] == 'a')
    {
        i++;
        goto Q2;
    }
    if (str[i] == 'b')
    {
        i++;
        goto Q1;
    }
    goto REJECT;

ACCEPT:
    return true;

REJECT:
    return false;
}

int main()
{
    char tests[][20] = {
        "aa", "ab", "aba", "abab", "aabbaabb"
    };

    cout << "TASK 2 RESULTS\n";
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
