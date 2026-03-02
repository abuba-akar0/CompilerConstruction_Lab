/**
 * Language Accepted
 *  L = { w ∈ {a,b} | w contains even number of a’s and odd number of b’s }
 **/

#include <iostream>
using namespace std;

int main()
{
    char str[50];
    cout << "Enter string: ";
    cin >> str;

    for (int i = 0; str[i]; i++)
    {
        if (str[i] != 'a' && str[i] != 'b')
        {
            cout << "Invalid alphabet!";
            return 0;
        }
    }

    int i = 0;
    goto Q0;

Q0:
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
    if (str[i] == '\0')
        goto REJECT;

Q1:
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

Q2:
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
    if (str[i] == '\0') goto ACCEPT;

Q3:
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
    cout << "ACCEPTED";
    return 0;

REJECT:
    cout << "REJECTED";
    return 0;
}
