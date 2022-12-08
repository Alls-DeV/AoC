#include <bits/stdc++.h>
using namespace std;
 
bool legal(int y, int x) {
    return y >= 0 && x >= 0 && y < 99 && x < 99;
}

void solution1() {
    vector<vector<int>> graph;
    string line;
    while (getline(cin, line)) {
        vector<int> tmp;
        for (auto c : line)
            tmp.push_back(c - '0');
        graph.push_back(tmp);
    }

    int ans = 0;

    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            bool visible = false;
            for (int k = 0; k < 4; k++) {
                int y = i, x = j;
                do {
                    switch (k) {
                        case 0: y--; break;
                        case 1: x--; break;
                        case 2: y++; break;
                        case 3: x++; break;
                    }
                } while (legal(y, x) && graph[y][x] < graph[i][j]);
                visible |= !legal(y, x);
            }
            if (visible)
                ans++;
        }
    }

    cout << ans << endl;
}

void solution2() {
    vector<vector<int>> graph;
    string line;
    while (getline(cin, line)) {
        vector<int> tmp;
        for (auto c : line)
            tmp.push_back(c - '0');
        graph.push_back(tmp);
    }

    for (int i = 0; i < graph.size(); i++)
        for (int j = 0; j < graph[i].size(); j++)
            if (i == 0 || j == 0 || i == graph.size() - 1 || j == graph[i].size() - 1)
                graph[i][j] = 10;
    
    int ans = 0;

    for (int i = 1; i < graph.size() - 1; i++) {
        for (int j = 1; j < graph[i].size() - 1; j++) {
            int tmp = 1;
            for (int k = 0; k < 4; k++) {
                int y = i, x = j;
                do {
                    switch (k) {
                        case 0: y--; break;
                        case 1: x--; break;
                        case 2: y++; break;
                        case 3: x++; break;
                    }
                } while (graph[y][x] < graph[i][j]);
                tmp *= abs(y - i) + abs(x - j);
            }
            ans = max(ans, tmp);
        }
    }

    cout << ans << endl;
}

int main() {
    // solution1();
    solution2();
}