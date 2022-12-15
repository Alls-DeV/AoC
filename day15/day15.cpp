#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int, int> split(string s) {
    vector<int> tokens;
    tuple<int, int, int, int> aaa;
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
    return {tokens[0], tokens[1], tokens[2], tokens[3]};
}

void solution1() {
    set<int> b, ans;
    string line;
    while (getline(cin, line)) {
        auto [x, y, xx, yy] = split(line);

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
    int value = 4000000; 
    vector<vector<pair<int, int>>> windows(value + 1);

    string line;
    while (getline(cin, line)) {
        auto [x, y, xx, yy] = split(line);
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
                cout << ((long long)windows[i][j].second + 1)*value + i << endl;
                return;
            }
        }
    }
}

int main() {
    // solution1();
    // solution2();
}