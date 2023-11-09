#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<char>> &graph, pair<int, int> start, pair<int, int> end,  int n, int m) {
    queue<array<int, 3>> q;
    vector<vector<bool>> visited(n, vector<bool> (m));
    q.push({start.first, start.second, 0});

    while (!q.empty()) {
        auto [y, x, value] = q.front();
        q.pop();
        vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (auto [a, b] : directions) {
            int ny = y + a, nx = x + b;
            if (ny < 0 || n <= ny || nx < 0 || m <= nx || visited[ny][nx] ||
                graph[ny][nx] > graph[y][x] + 1)
                continue;

            if (make_pair(ny, nx) == end)
                return value + 1;

            visited[ny][nx] = true;
            q.push({ny, nx, value + 1});
        }
    }

    return INT32_MAX;
}

void solution1() {
    vector<vector<char>> graph;
    string line;
    while (getline(cin, line))
        graph.push_back(vector<char>(line.begin(), line.end()));

    pair<int, int> start, end;
    for (int i = 0; i < ssize(graph); i++)
        for (int j = 0; j < ssize(graph[i]); j++)
            if (graph[i][j] == 'S') {
                start = {i, j};
                graph[i][j] = 'a';
            } else if (graph[i][j] == 'E') {
                end = {i, j};
                graph[i][j] = 'z';
            }

    int n = graph.size(), m = graph[0].size();
    cout << bfs(graph, start, end, n, m) << endl;
}
 
void solution2() {
    vector<vector<char>> graph;
    string line;
    while (getline(cin, line))
        graph.push_back(vector<char>(line.begin(), line.end()));

    vector<pair<int, int>> starts;
    pair<int, int> end;
    for (int i = 0; i < ssize(graph); i++)
        for (int j = 0; j < ssize(graph[i]); j++)
            if (graph[i][j] == 'S' || graph[i][j] == 'a') {
                starts.push_back({i, j});
                graph[i][j] = 'a';
            } else if (graph[i][j] == 'E') {
                end = {i, j};
                graph[i][j] = 'z';
            }

    int n = graph.size(), m = graph[0].size();
    int ans = INT32_MAX;
    for (auto start : starts)
        ans = min(ans, bfs(graph, start, end, n, m));
    cout << ans << endl;
}

int main() {
    // solution1();
    solution2();
}
