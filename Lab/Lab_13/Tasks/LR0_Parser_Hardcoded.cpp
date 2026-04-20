#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

map<pair<int,char>, string> ACTION;
map<pair<int,char>, int>    GOTO;
map<int, pair<char,string>> prod;

string intToStr(int x) {
    stringstream ss;
    ss << x;
    return ss.str();
}

struct Item {
    char symbol;
    int  state;
};

string getStackString(stack<Item> st) {
    vector<Item> v;
    while (!st.empty()) {
        v.push_back(st.top());
        st.pop();
    }
    string res = "";
    for (int i = (int)v.size() - 1; i >= 0; i--) {
        res += intToStr(v[i].state);
        if (v[i].symbol != '#')
            res += string(1, v[i].symbol);
    }
    return res;
}

int main() {
    string input = "aabb$";
    int i = 0, step = 1;

    prod[1] = make_pair('S', "AA");
    prod[2] = make_pair('A', "aA");
    prod[3] = make_pair('A', "b");

    ACTION[make_pair(0,'a')] = "s3";
    ACTION[make_pair(0,'b')] = "s4";
    ACTION[make_pair(2,'a')] = "s3";
    ACTION[make_pair(2,'b')] = "s4";
    ACTION[make_pair(3,'a')] = "s3";
    ACTION[make_pair(3,'b')] = "s4";
    ACTION[make_pair(4,'a')] = "r3";
    ACTION[make_pair(4,'b')] = "r3";
    ACTION[make_pair(4,'$')] = "r3";
    ACTION[make_pair(6,'a')] = "r2";
    ACTION[make_pair(6,'b')] = "r2";
    ACTION[make_pair(6,'$')] = "r2";
    ACTION[make_pair(5,'$')] = "r1";
    ACTION[make_pair(1,'$')] = "acc";

    GOTO[make_pair(0,'S')] = 1;
    GOTO[make_pair(0,'A')] = 2;
    GOTO[make_pair(2,'A')] = 5;
    GOTO[make_pair(3,'A')] = 6;

    stack<Item> st;
    st.push({'#', 0});

    cout << left << setw(6)  << "Step"
                 << setw(18) << "Stack"
                 << setw(18) << "Input"
                 << "Action" << endl;
    cout << "------------------------------------------------------------"
         << endl;

    while (true) {
        int  state = st.top().state;
        char a     = input[i];

        cout << left << setw(6)  << step;
        cout        << setw(18) << getStackString(st);
        cout        << setw(18) << input.substr(i);

        if (ACTION.find(make_pair(state,a)) == ACTION.end()) {
            cout << "REJECT" << endl;
            break;
        }

        string act = ACTION[make_pair(state,a)];

        if (act[0] == 's') {
            int nextState = act[1] - '0';
            st.push({a, nextState});
            i++;
            cout << "SHIFT " << a << endl;
        }
        else if (act[0] == 'r') {
            int    rule = act[1] - '0';
            char   lhs  = prod[rule].first;
            string rhs  = prod[rule].second;
            for (int k = 0; k < (int)rhs.size(); k++)
                st.pop();
            int nextState = GOTO[make_pair(st.top().state, lhs)];
            st.push({lhs, nextState});
            cout << "REDUCE " << lhs << "->" << rhs << endl;
        }
        else if (act == "acc") {
            cout << "ACCEPT" << endl;
            break;
        }
        step++;
    }
    return 0;
}