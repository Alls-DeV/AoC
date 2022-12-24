#include <bits/stdc++.h>
#ifdef ALE
    #include "/home/alls/CompetitiveProgramming/Library/debug.h"
#else
    #define dbg(...)
#endif
using namespace std;

pair<int, int> move_part1(vector<vector<char>>& grid, pair<int, int> pos, pair<int, int> direction) { 
    pair<int, int> possible_pos = {pos.first + direction.first, pos.second + direction.second};
    if (grid[possible_pos.first][possible_pos.second] != ' ')
        return (grid[possible_pos.first][possible_pos.second] == '#') ? pos : possible_pos;
    pair<int, int> teleported_position;
    if (direction == make_pair(0, 1)) {
        teleported_position = {pos.first, 0};
        while (grid[teleported_position.first][teleported_position.second] == ' ') teleported_position.second++;
    } else if (direction == make_pair(0, -1)) {
        teleported_position = {pos.first, grid[pos.first].size() - 1};
        while (grid[teleported_position.first][teleported_position.second] == ' ') teleported_position.second--;
    } else if (direction == make_pair(1, 0)) {
        teleported_position = {0, pos.second};
        while (grid[teleported_position.first][teleported_position.second] == ' ') teleported_position.first++;
    } else if (direction == make_pair(-1, 0)) {
        teleported_position = {grid.size() - 1, pos.second};
        while (grid[teleported_position.first][teleported_position.second] == ' ') teleported_position.first--;
    }
    return (grid[teleported_position.first][teleported_position.second] == '#') ? pos : teleported_position;
}

vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

pair<int, int> move_part2(vector<vector<char>>& grid, pair<int, int> pos, int &direction) { 
    int y = pos.first + directions[direction].first;
    int x = pos.second + directions[direction].second;
    if (0 <= y && y < grid.size() && 0 <= x && x < grid[y].size() &&
        grid[y][x] != ' ')
        return (grid[y][x] == '#') ? pos : make_pair(y, x);

    pair<int, int> teleported_position;
    if (y < 0 && 50 <= x && x < 100 && direction == 3) {
        direction = 0;
        teleported_position = {x + 100, 0};
    } else if (150 <= y && y < 200 && x < 0 && direction == 2) {
        direction = 1;
        teleported_position = {0, y - 100};
    } else if (y < 0 && 100 <= x && x < 150 && direction == 3) {
        teleported_position = {199, x - 100};
    } else if (y >= 200 && 0 <= x && x < 50 && direction == 1) {
        teleported_position = {0, x + 100};
    } else if (x >= 150 && 0 <= y && y < 50 && direction == 0) {
        direction = 2;
        teleported_position = {149 - y, 99};
    } else if (x == 100 && 100 <= y && y < 150 && direction == 0) {
        direction = 2;
        teleported_position = {149 - y, 149};
    } else if (y == 50 && 100 <= x && x < 150 && direction == 1) {
        direction = 2;
        teleported_position = {x - 50, 99};
    } else if (x == 100 && 50 <= y && y < 100 && direction == 0) {
        direction = 3;
        teleported_position = {49, y + 50};
    } else if (y == 150 && 50 <= x && x < 100 && direction == 1) {
        direction = 2;
        teleported_position = {x + 100, 49};
    } else if (x == 50 && 150 <= y && y < 200 && direction == 0) {
        direction = 3;
        teleported_position = {149, y - 100};
    } else if (y == 99 && 0 <= x && x < 50 && direction == 3) {
        direction = 0;
        teleported_position = {x + 50, 50};
    } else if (x == 49 && 50 <= y && y < 100 && direction == 2) {
        direction = 1;
        teleported_position = {100, y - 50};
    } else if (x == 49 && 0 <= y && y < 50 && direction == 2) {
        direction = 0;
        teleported_position = {149 - y, 0};
    } else if (x < 0 && 100 <= y && y < 150 && direction == 2) {
        direction = 0;
        teleported_position = {149 - y, 50};
    }
    return teleported_position;
}

int main () {
    vector<vector<char>> grid;
    string line;
    // comment next line if part 2
    // grid.push_back(vector<char>(200, ' '));
    while (getline(cin, line)) {
        if (line.empty())
            break;
        // comment next line if part 2
        // line = " " + line + string(200 - line.size() - 1, ' ');
        grid.push_back(vector<char>(line.begin(), line.end()));
    }
    // comment next line if part 2
    // grid.push_back(vector<char>(200, ' '));
    // print grid
    // for (auto& row : grid) {
    //     for (auto& c : row)
    //     if (c == ' ')
    //         cout << '-';
    //     else
    //         cout << c;
    //     cout << endl;
    // }
    string movements;
    vector<int> distances;
    vector<char> rotations;
    getline(cin, movements);
    movements.append(".");
    string tmp;
    for (auto c : movements)
        if (c == 'L' || c == 'R' || c == '.') {
            rotations.push_back(c);
            distances.push_back(stoi(tmp));
            tmp.clear();
        } else
            tmp.push_back(c);
    // {y, x}
    pair<int, int> pos = {1, 1};
    while (grid[pos.first][pos.second] != '.') pos.second++;
    int direction = 0;
    for (int distance = 0, rotation = 0; distance < distances.size(); distance++, rotation++) {
        while (distances[distance]--) {
            // pair<int, int> new_pos = move_part1(grid, pos, directions[direction]); 
            pair<int, int> new_pos = move_part2(grid, pos, direction); 
            if (new_pos != pos)
                pos = new_pos;
            else
                break;
        }
        if (rotations[rotation] == 'L')
            direction = (direction + 3) % 4;
        else if (rotations[rotation] == 'R')
            direction = (direction + 1) % 4;
    }
    cout << 1000 * pos.first + 4 * pos.second + direction << endl;
}