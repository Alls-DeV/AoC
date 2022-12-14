#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> split(string s) {
    vector<pair<int, int>> tokens;
    set<char> char_to_remove = {' ', '-', '>'};
    s = s + (*char_to_remove.begin());
    string token;
    pair<int, int> p;
    for (auto c : s) {
        if (c == ',') {
            p.first = stoi(token);
            token.clear();
        } else if (char_to_remove.find(c) == char_to_remove.end()) {
            token.push_back(c);
        } else if (token.size() > 0) {
            p.second = stoi(token);
            tokens.push_back(p);
            token.clear();
        }
    }

    return tokens;
}

int main() {
    set<pair<int, int>> stones, sands;
    int max_y = 0;

    // input
    string line;
    while (getline(cin, line)) {
        vector<pair<int, int>> tokens = split(line);
        for (int i = 1; i < tokens.size(); i++) {
            if (tokens[i].first != tokens[i - 1].first) {
                int nin = min(tokens[i].first, tokens[i - 1].first);
                int nax = max(tokens[i].first, tokens[i - 1].first);
                int y = tokens[i].second;
                max_y = max(max_y, y);
                for (int j = nin; j <= nax; j++)
                    stones.insert({j, y});
            } else {
                int nin = min(tokens[i].second, tokens[i - 1].second);
                int nax = max(tokens[i].second, tokens[i - 1].second);
                int x = tokens[i].first;
                max_y = max(max_y, nax);
                for (int j = nin; j <= nax; j++)
                    stones.insert({x, j});
            }
        }
    }

    // comment for part 1
    // max_y += 2;
    // for (int i = 0; i < 10000; i++)
    //     stones.insert({i, max_y});

    vector<int> dirs = {0, -1, 1};
    pair<int, int> sand;
    do {
        sand = {500, 0};

        for (int i = 0; sand.second < max_y && i < 3; i++) {
            pair<int, int> next = {sand.first + dirs[i], sand.second + 1};
            if (stones.find(next) == stones.end() &&
                sands.find(next) == sands.end()) {
                sand = next;
                i = -1;
            }
        }
    } while (sand.second != max_y && sands.insert(sand).second);
    
    cout << sands.size() << endl;
}