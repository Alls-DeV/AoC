#include <bits/stdc++.h>
using namespace std;

void solution1() {
    int ans = 0;

    for (int i = 0; i < 2500; i++) {
        char a, b;
        cin >> a >> b;
        // rock = 0, paper = 1, scissors = 2
        a -= 'A', b -= 'X';
        ans += b + 1;
        if (a == b)
            ans += 3;
        else
            ans += (((b - a + 3)%3)%2)*6;
    }
    
    cout << ans << endl;
}

void solution2() {
    int ans = 0;

    for (int i = 0; i < 2500; i++) {
        char a, b;
        cin >> a >> b;
        a -= 'A', b -= 'X';
        ans += b*3;
        ans += (a + (b + 2)%3)%3 + 1;
    }

    cout << ans << endl;
}

int main() {
    solution1();
    solution2();
}