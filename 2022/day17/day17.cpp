#include <bits/stdc++.h>
#ifdef ALE
    #include "/home/alls/CompetitiveProgramming/Library/debug.h"
#else
    #define dbg(...)
#endif
using namespace std;

set<pair<int, int>> get_coordinates (int max_height, int piece) {
    set<pair<int, int>> coordinates;

    pair<int, int> center_cross = {3, max_height + 5};
    vector<pair<int, int>> cross_movements = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<pair<int, int>> square_movements = {{0, 0}, {1, 0}, {0, -1}, {1, -1}};

    switch (piece) {
    case 0:
        for (int i = 2; i < 6; i++)
            coordinates.insert({i, max_height + 4});
        break;
    case 1:
        coordinates.insert(center_cross);
        for (auto [x, y] : cross_movements)
            coordinates.insert({center_cross.first + x, center_cross.second + y});
        break;
    case 2:
        for (int i = 0; i < 3; i++) {
            coordinates.insert({4 - i, max_height + 4});
            coordinates.insert({4, max_height + 4 + i});
        }
        break;
    case 3:
        for (int i = 0; i < 4; i++)
            coordinates.insert({2, max_height + 4 + i});
        break;
    case 4:
        for (auto [x, y] : square_movements)
            coordinates.insert({2 + x, max_height + 5 + y});
        break;
    }
    return coordinates;
}

int main() {
    string s;
    cin >> s;
    // pair of {x, y}
    set<pair<int, int>> stones;
    for (int i = 0; i < 7; i++)
        stones.insert({i, 0});
    map<char, int> direction{{'<', -1}, {'>', 1}};
    array<long long, 7> max_heights = {0, 0, 0, 0, 0, 0, 0};
    map<tuple<array<long long, 7>, int, int>, pair<long long, long long>> memo;
    bool flag = false;
    long long total_cycles = 1000000000000;
    long long ans_part2;
    for (long long piece = 0, index_direction = 0; piece < total_cycles; piece++) {
        auto coordinates = get_coordinates(*max_element(max_heights.begin(), max_heights.end()), piece%5);
        while (true) {
            set<pair<int, int>> possible_coordinates;
            set<pair<int, int>> inters;

            // move right or left
            for (auto [x, y] : coordinates)
                possible_coordinates.insert({x + direction[s[index_direction]], y});
            set_intersection(possible_coordinates.begin(), possible_coordinates.end(), stones.begin(), stones.end(), 
                inserter(inters, inters.begin()));
            if (inters.empty() && possible_coordinates.begin()->first >= 0 &&
                possible_coordinates.rbegin()->first < 7)
                coordinates = possible_coordinates;
            index_direction = (index_direction + 1) % s.size();

            possible_coordinates.clear();
            inters.clear();

            // move down 
            for (auto [x, y] : coordinates)
                possible_coordinates.insert({x, y - 1});
            set_intersection(possible_coordinates.begin(), possible_coordinates.end(), stones.begin(), stones.end(), 
                inserter(inters, inters.begin()));
            if (inters.empty())
                coordinates = possible_coordinates;
            else {
                for (auto [x, y] : coordinates) {
                    stones.insert({x, y});
                    max_heights[x] = max(max_heights[x], (long long)y);
                }
                if (!flag) {
                    array<long long, 7> relative_heights = max_heights;
                    long long tmp = *min_element(max_heights.begin(), max_heights.end());
                    for (auto &x : relative_heights) x -= tmp;
                    int nax = *max_element(max_heights.begin(), max_heights.end());
                    if (memo.insert({{relative_heights, piece%5, index_direction}, {piece, nax}}).second == false && piece > 2021) {
                        flag = true;
                        long long height = nax - memo[{relative_heights, piece%5, index_direction}].second;
                        long long length_cycle = piece - memo[{relative_heights, piece%5, index_direction}].first;
                        ans_part2 = ((total_cycles - piece)/length_cycle)*(height);
                        piece = total_cycles - (total_cycles - piece)%length_cycle;
                    }
                }
                break;
            }
        }
        if (piece == 2021)
            cout << *max_element(max_heights.begin(), max_heights.end()) << endl;
    }
    cout << ans_part2 + *max_element(max_heights.begin(), max_heights.end()) << endl;
}