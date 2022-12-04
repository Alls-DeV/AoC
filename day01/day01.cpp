#include <bits/stdc++.h>
using namespace std;

/*
    find and replace on the input
    ^$\n
    -1\n
*/

void solution1() {
    vector<int> v;
    int ans, tmp;
    ans = tmp = 0;

    for (int i = 0; i < 2255; i++) {
        int n;
        cin >> n;
        if (n == -1) {
            ans = max(ans, tmp);
            tmp = 0;
        } else {
            tmp += n;
        }
    }

    cout << ans << endl;
}

void solution2() {
    vector<int> v;
    int tmp = 0;

    for (int i = 0; i < 2255; i++) {
        int n;
        cin >> n;
        if (n == -1) {
            v.push_back(tmp);
            tmp = 0;
        } else {
            tmp += n;
        }
    }

    sort(v.begin(), v.end(), [](auto a, auto b){return a > b;});
    cout << accumulate(v.begin(), v.begin()+3, 0) << endl;
}

int main() {
    solution1();
    solution2();
}
