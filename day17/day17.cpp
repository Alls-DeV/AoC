#include <bits/stdc++.h>
#ifdef ALE
    #include "/home/alls/CompetitiveProgramming/Library/debug.h"
#else
    #define dbg(...)
#endif
using namespace std;
/*

index: 0, 5, 10
####

index: 1, 6, 12
.#.
###
.#.
   
..#
..#
###

#
#
#
#

##
##

*/

// pair of (x, y)

void f (set<pair<int, int>> stones) {
    int min_x = 0;
    int max_x = 6;
    int min_y = 1;
    int max_y = 20;
    for (int y = max_y; y >= min_y; y--) {
        for (int x = min_x; x <= max_x; x++)
            cout << (stones.find({x, y}) != stones.end() ? '#' : '.');
        cout << '\n';
    }
    cout << "----------------------------------\n";
}

set<pair<int, int>> get_coordinates (int max_height, int piece) {
    set<pair<int, int>> coordinates;

    pair<int, int> center_cross = {3, max_height + 5};
    vector<pair<int, int>> cross_movements = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<pair<int, int>> square_movements = {{0, 0}, {1, 0}, {0, -1}, {1, -1}};

    switch (piece%5)
    {
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

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &pair) const
    {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);
 
        return h1 ^ h2;
    }
};
int main() {
    string s;
    cin >> s;
    // pair of {x, y}
    unordered_set<pair<int, int>, pair_hash> stones;
    for (int i = 0; i < 7; i++)
        stones.insert({i, 0});
    map<char, int> direction{{'<', -1}, {'>', 1}};
    int max_height = 0;
    for (int piece = 0, index_direction = 0; piece < 1000000; piece++) {
        if (piece % 100000 == 0)
            cout << piece << endl;
        auto coordinates = get_coordinates(max_height, piece);
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
                    max_height = max(max_height, y);
                }
                break;
            }
        }
    }
    cout << max_height << endl;
}