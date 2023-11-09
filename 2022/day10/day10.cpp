#include <bits/stdc++.h>
using namespace std;

void solution1() {
    int ans, cycle;
    ans = cycle = 0;
    int value = 1;

    auto tick = [&] () {
        cycle++;
        if ((cycle-20)%40 == 0)
            ans += value*cycle;
    };

    string s;
    while (getline(cin, s)) {
        tick();
        if (s[0] == 'n')
            continue;
        int tmp = stoi(s.substr(4));
        tick();
        value += tmp;
    }

    cout << ans << endl;
}

void solution2() {
    vector<vector<char>> mat(6, vector<char>(40, ' '));
    int cycle = 0;
    int value = 1;

    auto tick = [&] () {
        if (abs(value - cycle%40) <= 1)
            mat[cycle/40][cycle%40] = '#';
        cycle++;
    };

    string s;
    while (getline(cin, s)) {
        tick();
        if (s[0] == 'n')
            continue;
        int tmp = stoi(s.substr(4));
        tick();
        value += tmp;
    }

    for (auto v : mat) {
        for (auto c : v)
            cout << c;
        cout << endl;
    }
}
 
int main() {
    // solution1();
    solution2();
}
