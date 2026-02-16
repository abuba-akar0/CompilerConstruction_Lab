//
// Language:
//   L = { w ∈ {a,b}* | even number of a’s AND even number of b’s }
//

#include <iostream>
using namespace std;

bool isAccepted(char str[])
{
    int state = 0;

    for (int i = 0; str[i]; i++)
    {
        if (str[i] != 'a' && str[i] != 'b')
            return false;

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
    return state == 0;
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
        if (isAccepted(tests[i]))
            cout << "ACCEPTED\n";
        else
            cout << "REJECTED\n";
    }
    return 0;
}
