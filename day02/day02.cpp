#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    for (int i = 0; i < 2500; i++) {
        char a, b;
        cin >> a >> b;
        // rock = 0, paper = 1, scissors = 2
        a -= 'A', b -= 'X';
        // win or draw or lose
        ans += b*3;
        // rock or paper or scissors
        ans += (a + (b + 2)%3)%3 + 1;
    }
    cout << ans << endl;
}