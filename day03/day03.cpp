#include <bits/stdc++.h>
using namespace std;

void solution1() {
    int ans = 0;

    for (int i = 0; i < 300; i++) {
        string s; cin >> s;
        string s1 = s.substr(0, s.size() / 2);
        string s2 = s.substr(s.size() / 2);
        vector<pair<bool, bool>> appear(52);

        for (char c : s1)
            if ('a' <= c && c <= 'z')
                appear[c - 'a'].first = true;
            else
                appear[c - 'A' + 26].first = true;
        for (char c : s2)
            if ('a' <= c && c <= 'z')
                appear[c - 'a'].second = true;
            else
                appear[c - 'A' + 26].second = true;

        for (int i = 0; i < 52; i++)
            ans += (appear[i].first && appear[i].second)*(i + 1);
    }

    cout << ans << endl;
}
 
void solution2() {
    int ans = 0;
    
    for (int i = 0; i < 100; i++) {
        vector<array<bool, 3>> appear(52);
        for (int j = 0; j < 3; j++) {
            string s; cin >> s;

            for (char c : s)
                if ('a' <= c && c <= 'z')
                    appear[c - 'a'][j] = true;
                else
                    appear[c - 'A' + 26][j] = true;
        }

        for (int i = 0; i < 52; i++)
            ans += (appear[i][0] && appear[i][1] && appear[i][2])*(i + 1);
    }

    cout << ans << endl;
}

int32_t main() {
    solution1();
    solution2();
}
