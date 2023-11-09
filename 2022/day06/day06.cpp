#include <bits/stdc++.h>
using namespace std;

void solution1() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        set<char>  sett;
        for (int j = 0; j < 4; j++) {
            sett.insert(s[j + i]);
        }
        if(sett.size() == 4) {
            cout << i + 4 << endl;
            return;
        }
    }
}

void solution2() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        set<char>  sett;
        for (int j = 0; j < 14; j++) {
            sett.insert(s[j + i]);
        }
        if(sett.size() == 14) {
            cout << i + 14 << endl;
            return;
        }
    }
}
 
int main() {
    solution1();
    solution2();
}
