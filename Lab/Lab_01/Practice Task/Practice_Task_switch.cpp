//
// Created by abuba on 04/02/2026.
//

#include <iostream>
#include <cstring>
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

    int state = 0;

    for (int i = 0; str[i]; i++)
    {
        switch (state)
        {
        case 0: state = (str[i] == 'a') ? 1 : 2;
            break;
        case 1: state = (str[i] == 'a') ? 0 : 3;
            break;
        case 2: state = (str[i] == 'a') ? 3 : 0;
            break;
        case 3: state = (str[i] == 'a') ? 2 : 1;
            break;
        }
    }

    if (state == 2)
        cout << "ACCEPTED";
    else
        cout << "REJECTED";
}
