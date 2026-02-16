//
// Language Accepted
//   L = { a(bb)^n b c | n ≥ 0 }
// In words:
//   All strings that start with a, contain even number of bs before final bc, and end with bc
//

#include <iostream>
using namespace std;

bool isAccepted(char str[]) {
    int state = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] != 'a' && str[i] != 'b' && str[i] != 'c')
            return false;

        switch (state) {
        case 0:
            if (str[i] == 'a') state = 1;
            else return false;
            break;

        case 1:
            if (str[i] == 'b') state = 2;
            else return false;
            break;

        case 2:
            if (str[i] == 'b') state = 1;
            else if (str[i] == 'c') state = 3;
            else return false;
            break;

        case 3:
            return false;
        }
    }
    return state == 3;
}

int main() {
    char tests[][20] = {
        "abc", "abbc", "abcd", "abbbc", "abbbbc"
    };

    cout << "TASK 1 RESULTS\n";
    for (int i = 0; i < 5; i++) {
        cout << tests[i] << " : ";
        if (isAccepted(tests[i]))
            cout << "ACCEPTED\n";
        else
            cout << "REJECTED\n";
    }
    return 0;
}
