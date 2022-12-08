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
    vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            bool visible = false;
            for (int k = 0; k < 4; k++) {
                int tmp = 1;
                while (legal(i + tmp*dirs[k].first, j + tmp*dirs[k].second) &&
                    graph[i + tmp*dirs[k].first][j + tmp*dirs[k].second] < graph[i][j])
                    tmp++;

                visible |= !legal(i + tmp*dirs[k].first, j + tmp*dirs[k].second);
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
    vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    for (int i = 1; i < graph.size() - 1; i++) {
        for (int j = 1; j < graph[i].size() - 1; j++) {
            int trees = 1;

            for (int k = 0; k < 4; k++) {
                int tmp = 1;
                while (graph[i + tmp*dirs[k].first][j + tmp*dirs[k].second] < graph[i][j])
                    tmp++;

                trees *= abs(tmp*dirs[k].first) + abs(tmp*dirs[k].second);
            }

            ans = max(ans, trees);
        }
    }

    cout << ans << endl;
}

int main() {
    solution1();
    // solution2();
}