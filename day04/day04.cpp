#include <bits/stdc++.h>
using namespace std;

void solution1() {
    int ans = 0;

    while (true) {
        vector<int> v(4);
        for (auto &i : v) cin >> i;
        if (v[0] == -1) break;
        if (v[0] <= v[2] && v[3] <= v[1] ||
            v[2] <= v[0] && v[1] <= v[3]) ans++;
    }

    cout << ans << endl;
}

void solution2() {
    int ans = 0;

    while (true) {
        vector<int> v(4);
        for (auto &i : v) cin >> i;
        if (v[0] == -1) break;
        if (v[0] > v[3] || v[1] < v[2])
            continue;
        ans++;
    }

    cout << ans << endl;
}
 
int main() {
    solution1();
    solution2();
}
