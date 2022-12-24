#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;

bool is_legal(pair<int, int> pos, int minutes) {
    bool ans = pos.first >= 0 && pos.first < grid.size() && pos.second >= 0 && pos.second < grid[0].size() && grid[pos.first][pos.second] != '#';
    if (ans && (pos.first == 0 || pos.first == grid.size() - 1))
        return true;
    int rows = grid.size() - 2, cols = grid[0].size() - 2;
    pair<int, int> up{((pos.first - 1 - (minutes % rows) + rows) % rows) + 1, pos.second};
    pair<int, int> down{((pos.first - 1 + (minutes % rows)) % rows) + 1, pos.second};
    pair<int, int> left{pos.first, ((pos.second - 1 - (minutes % cols) + cols) % cols) + 1};
    pair<int, int> right{pos.first, ((pos.second - 1 + (minutes % cols)) % cols) + 1};
    ans = ans && (grid[up.first][up.second] != 'v') && (grid[down.first][down.second] != '^') &&
            (grid[left.first][left.second] != '>') && (grid[right.first][right.second] != '<');
    return ans;
}

int main() {
    string line;
    while (getline(cin, line))
        grid.push_back(vector<char>(line.begin(), line.end()));
    pair<int, int> start{0, 1}, end{grid.size() - 1, grid[0].size() - 2};
    queue<array<int, 3>> q;
    vector<pair<int, int>> dirs{{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    set<array<int, 3>> visited;
    q.push({start.first, start.second, 0});
    int phase = 0;
    while (!q.empty()) {
        auto [x, y, minutes] = q.front();
        q.pop();
        if (visited.count({x, y, minutes}))
            continue;
        visited.insert({x, y, minutes});
        if (x == end.first && y == end.second) {
            if (phase == 0) {
                phase++;
                cout << minutes << endl;
                visited.clear();
                q = queue<array<int, 3>>();
                swap(start, end);
                q.push({start.first, start.second, minutes});
                continue;
            } else if (phase == 1) {
                visited.clear();
                q = queue<array<int, 3>>();
                swap(start, end);
                q.push({start.first, start.second, minutes});
                phase++;
            } else {
                cout << minutes << endl;
                break;
            }
        }
        for (auto [dx, dy] : dirs) {
            int nx = x + dx, ny = y + dy;
            if (is_legal({nx, ny}, minutes + 1))
                q.push({nx, ny, minutes + 1});
        }
    }
}