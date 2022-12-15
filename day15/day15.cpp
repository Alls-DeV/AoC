#include <bits/stdc++.h>
using namespace std;

vector<int> split(string s) {
    vector<int> tokens;
    set<char> char_used = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-'};
    s = s + " ";
    string token;
    for (auto c : s) {
        if (char_used.find(c) != char_used.end()) {
            token.push_back(c);
        } else if (token.size() > 0) {
            tokens.push_back(stoi(token));
            token.clear();
        }
    }
    return tokens;
}

void solution1() {
    vector<int> coordinates;
    string line;
    while (getline(cin, line)) {
        vector<int> tmp = split(line);
        coordinates.insert(coordinates.end(), tmp.begin(), tmp.end());
    }

    set<int> b, ans;

    for (int i = 0; i + 3 < coordinates.size(); i += 4) {
        int x, y, xx, yy;
        tie(x, y, xx, yy) = tie(coordinates[i], coordinates[i + 1], coordinates[i + 2], coordinates[i + 3]);

        if (yy == 2000000)
            b.insert(xx);

        int distance = abs(x - xx) + abs(y - yy);
        distance -= abs(y - 2000000);
        for (int j = 0; j <= distance; j++) {
            ans.insert(x + j);
            ans.insert(x - j);
        }
    }

    cout << ans.size() - b.size() << endl;
}

void solution2() {
    vector<int> coordinates;
    string line;
    while (getline(cin, line)) {
        vector<int> tmp = split(line);
        coordinates.insert(coordinates.end(), tmp.begin(), tmp.end());
    }

    int value = 4000000; 
    vector<vector<pair<int, int>>> windows(value + 1);

    for (int i = 0; i + 3 < coordinates.size(); i += 4) {
        int x, y, xx, yy;
        tie(x, y, xx, yy) = tie(coordinates[i], coordinates[i + 1], coordinates[i + 2], coordinates[i + 3]);
        int distance = abs(x - xx) + abs(y - yy);

        for (int yyy = max(0, y - distance); yyy <= min(value, y + distance); yyy++) {
            pair<int, int> range = {max(0, x - (distance - abs(y - yyy))),
                                    min(value, x + (distance - abs(y - yyy)))};
            windows[yyy].push_back(range);
        }
    }

    for (int i = 0; i < windows.size(); i++) {
        windows[i].push_back({-1, -1});
        windows[i].push_back({value + 1, value + 1});
        sort(windows[i].begin(), windows[i].end());
        
        int nax = -1;
        for (int j = 0; j < windows[i].size() - 1; j++) {
            nax = max(nax, windows[i][j].second);
            
            if (nax + 1 < windows[i][j + 1].first) {
                long long ans = ((long long)windows[i][j].second + 1)*value + i;
                cout << ans << endl;
                return;
            }
        }
    }
}

int main() {
    solution1();
    // solution2();
}