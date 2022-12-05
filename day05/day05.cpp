#include <bits/stdc++.h>
#ifdef ALE
    #include "/home/alls/CompetitiveProgramming/Library/debug.h"
#else
    #define dbg(...)
#endif
using namespace std;

void solution1() {
    vector<stack<char>> st(9);

    st[0].push('B');
    st[0].push('P');
    st[0].push('N');
    st[0].push('Q');
    st[0].push('H');
    st[0].push('D');
    st[0].push('R');
    st[0].push('T');

    st[1].push('W');
    st[1].push('G');
    st[1].push('B');
    st[1].push('J');
    st[1].push('T');
    st[1].push('V');


    st[2].push('N');
    st[2].push('R');
    st[2].push('H');
    st[2].push('D');
    st[2].push('S');
    st[2].push('V');
    st[2].push('M');
    st[2].push('Q');

    st[3].push('P');
    st[3].push('Z');
    st[3].push('N');
    st[3].push('M');
    st[3].push('C');


    st[4].push('D');
    st[4].push('Z');
    st[4].push('B');

    st[5].push('V');
    st[5].push('C');
    st[5].push('W');
    st[5].push('Z');

    st[6].push('G');
    st[6].push('Z');
    st[6].push('N');
    st[6].push('C');
    st[6].push('V');
    st[6].push('Q');
    st[6].push('L');
    st[6].push('S');

    st[7].push('L');
    st[7].push('G');
    st[7].push('J');
    st[7].push('M');
    st[7].push('D');
    st[7].push('N');
    st[7].push('V');

    st[8].push('T');
    st[8].push('P');
    st[8].push('M');
    st[8].push('F');
    st[8].push('Z');
    st[8].push('C');
    st[8].push('G');

    while (true) {
        int n, start, end;
        cin >> n >> start >> end;
        if (n == -1) break;
        for (int i = 0; i < n; i++) {
            st[end-1].push(st[start-1].top());
            st[start-1].pop();
        }
    }

    dbg(st);
}

void solution2() {
    vector<stack<char>> st(9);

    st[0].push('B');
    st[0].push('P');
    st[0].push('N');
    st[0].push('Q');
    st[0].push('H');
    st[0].push('D');
    st[0].push('R');
    st[0].push('T');

    st[1].push('W');
    st[1].push('G');
    st[1].push('B');
    st[1].push('J');
    st[1].push('T');
    st[1].push('V');


    st[2].push('N');
    st[2].push('R');
    st[2].push('H');
    st[2].push('D');
    st[2].push('S');
    st[2].push('V');
    st[2].push('M');
    st[2].push('Q');

    st[3].push('P');
    st[3].push('Z');
    st[3].push('N');
    st[3].push('M');
    st[3].push('C');


    st[4].push('D');
    st[4].push('Z');
    st[4].push('B');

    st[5].push('V');
    st[5].push('C');
    st[5].push('W');
    st[5].push('Z');

    st[6].push('G');
    st[6].push('Z');
    st[6].push('N');
    st[6].push('C');
    st[6].push('V');
    st[6].push('Q');
    st[6].push('L');
    st[6].push('S');

    st[7].push('L');
    st[7].push('G');
    st[7].push('J');
    st[7].push('M');
    st[7].push('D');
    st[7].push('N');
    st[7].push('V');

    st[8].push('T');
    st[8].push('P');
    st[8].push('M');
    st[8].push('F');
    st[8].push('Z');
    st[8].push('C');
    st[8].push('G');

    while (true) {
        int n, start, end;
        cin >> n >> start >> end;
        if (n == -1) break;
        vector<char> tmp(0);
        for (int i = 0; i < n; i++) {
            tmp.push_back(st[start-1].top());
            st[start-1].pop();
        }
        for (auto it = tmp.rbegin(); it != tmp.rend(); it++)
            st[end-1].push(*it);
    }

    dbg(st);
}
 
int32_t main() {
    solution1();
    solution2();
}
