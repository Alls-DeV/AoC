#include <bits/stdc++.h>
using namespace std;
const int dimension = 5000;

void solution1() {
    vector<vector<bool>> visited(dimension, vector<bool>(dimension, false));
    vector<pair<int, int>> nodes(10, {dimension/2, dimension/2});
    pair<int, int> head_position, tail_position;
    head_position = tail_position = {dimension/2, dimension/2};
    visited[dimension/2][dimension/2] = true;
    visited[dimension/2][dimension/2] = true;

    string s;
    while (getline(cin, s)) {
        char c = s[0];
        int n = stoi(s.substr(2));
        while (n--) {
            if (c == 'U')
                head_position.first--;
            else if (c == 'D')
                head_position.first++;
            else if (c == 'R')
                head_position.second++;
            else
                head_position.second--;

            int diff = 1e9;
            pair<int, int> movement;
            for (int a = -1; a <= 1; a++) {
                for (int b = -1; b <= 1; b++) {
                    if (abs(tail_position.first + a - head_position.first) + abs(tail_position.second + b - head_position.second) < diff) {
                        diff = abs(tail_position.first + a - head_position.first) + abs(tail_position.second + b - head_position.second);
                        movement = {a, b};
                    }
                }
            }

            if (diff == 0)
                continue;

            tail_position.first += movement.first;
            tail_position.second += movement.second;
            visited[tail_position.first][tail_position.second] = true;
        }
    }

    int ans = 0;

    for (int i = 0; i < dimension; i++)
        for (int j = 0; j < dimension; j++)
            ans += visited[i][j];

    cout << ans << endl;
}

void solution2() {
    vector<vector<bool>> visited(dimension, vector<bool>(dimension, false));
    vector<pair<int, int>> nodes(10, {dimension/2, dimension/2});
    visited[dimension/2][dimension/2] = true;

    string s;
    while (getline(cin, s)) {
        char c = s[0];
        int n = stoi(s.substr(2));
        while (n--) {
            if (c == 'U')
                nodes[0].first--;
            else if (c == 'D')
                nodes[0].first++;
            else if (c == 'R')
                nodes[0].second++;
            else
                nodes[0].second--;

            for (int i = 1; i < 10; i++) {
                int diff = 1e9;
                pair<int, int> movement;
                for (int a = -1; a <= 1; a++) {
                    for (int b = -1; b <= 1; b++) {
                        if (abs(nodes[i].first + a - nodes[i - 1].first) + abs(nodes[i].second + b - nodes[i - 1].second) < diff) {
                            diff = abs(nodes[i].first + a - nodes[i - 1].first) + abs(nodes[i].second + b - nodes[i - 1].second);
                            movement = {a, b};
                        }
                    }
                }
                if (diff == 0)
                    continue;
                nodes[i].first += movement.first;
                nodes[i].second += movement.second;
            }
            visited[nodes[9].first][nodes[9].second] = true;
        }
    }

    int ans = 0;

    for (int i = 0; i < dimension; i++)
        for (int j = 0; j < dimension; j++)
            ans += visited[i][j];

    cout << ans << endl;
}
 
int main() {
    solution1();
    // solution2();
}
