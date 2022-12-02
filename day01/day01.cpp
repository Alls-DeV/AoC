#include <bits/stdc++.h>
using namespace std;

/*
    ^$\n
    -1\n
*/

int main() {
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