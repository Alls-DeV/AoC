#include <bits/stdc++.h>
#ifdef ALE
    #include "/home/alls/CompetitiveProgramming/Library/debug.h"
#else
    #define dbg(...)
#endif
using namespace std;

map<int, pair<int, char>> mapp{{0, {0, '0'}}, {1, {0, '1'}}, {2, {0, '2'}}, {3, {1, '='}}, {4, {1, '-'}}, {5, {1, '0'}}};

long long SNAFU_to_decimal (string s) {
    long long ans = 0;
    long long mul = 1;
    reverse(s.begin(), s.end());
    for (char c : s) {
        if (c == '-')
            ans += (-1LL) * mul;
        else if (c == '=')
            ans += (-2LL) * mul;
        else
            ans += (c - 48LL) * mul;
        mul *= 5LL;
    }
    return ans;
}

string decimal_to_SNAFU (long long n) {
    string res;
    int remainder = 0;
    while (n != 0) {
        res.push_back(mapp[n % 5 + remainder].second);
        remainder = mapp[n % 5 + remainder].first;
        n /= 5;
    }
    if (remainder)
        res.push_back(remainder + '0');
    reverse(res.begin(), res.end());
    return res;
}

int main () {
    long long ans = 0;
    // {module, {remainder, digit to append}}
    string line;
    while (getline(cin, line))
        ans += SNAFU_to_decimal(line);
    cout << decimal_to_SNAFU(ans) << endl;
}