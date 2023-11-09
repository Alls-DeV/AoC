#include <bits/stdc++.h>
using namespace std;

void solution1() {
    pair<int, int> head_position, tail_position;
    head_position = tail_position = {0, 0};
    set<pair<int, int>> visited{tail_position};

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

            int distance = 1e9;
            pair<int, int> movement;
            for (int a = -1; a <= 1; a++) {
                for (int b = -1; b <= 1; b++) {
                    int diff_y = abs(tail_position.first + a - head_position.first);
                    int diff_x = abs(tail_position.second + b - head_position.second);

                    if (diff_y + diff_x < distance) {
                        distance = diff_y + diff_x;
                        movement = {a, b};
                    }
                }
            }
            if (distance == 0)
                continue;
            tail_position.first += movement.first;
            tail_position.second += movement.second;
            visited.insert(tail_position);
        }
    }

    cout << visited.size() << endl;
}

void solution2() {
    vector<pair<int, int>> nodes(10, {0, 0});
    set<pair<int, int>> visited{nodes[9]};

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
                int distance = 1e9;
                pair<int, int> movement;
                for (int a = -1; a <= 1; a++) {
                    for (int b = -1; b <= 1; b++) {
                        int diff_y = abs(nodes[i].first + a - nodes[i - 1].first);
                        int diff_x = abs(nodes[i].second + b - nodes[i - 1].second);

                        if (diff_y + diff_x < distance) {
                            distance = diff_y + diff_x;
                            movement = {a, b};
                        }
                    }
                }
                if (distance == 0)
                    continue;
                nodes[i].first += movement.first;
                nodes[i].second += movement.second;
            }
            visited.insert(nodes[9]);
        }
    }

    cout << visited.size() << endl;
}
 
int main() {
    solution1();
    // solution2();
}
