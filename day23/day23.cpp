#include <bits/stdc++.h>
#ifdef ALE
    #include "/home/alls/CompetitiveProgramming/Library/debug.h"
#else
    #define dbg(...)
#endif
using namespace std;

int main () {
    string line;
    set<pair<int, int>> elves;
    int y = 0;
    while (getline(cin, line)) {
        for (int x = 0; x < line.size(); x++)
            if (line[x] == '#')
                elves.insert({y, x});
        y++;
    }

    int cycles = 0, count; 
    const int M = 1e9;
    // if value of the map is {M, M} it means that more than one elf wants to move there
    map<pair<int, int>, pair<int, int>> new_positions;
    array<char, 4> dirs = {'N', 'S', 'W', 'E'};
    while (++cycles) {
        for (auto &elf : elves) {
            count = 0;
            for (int dy = -1; dy <= 1; dy++)
                for (int dx = -1; dx <= 1; dx++)
                    count += elves.count({elf.first + dy, elf.second + dx});
            if (count == 1)
                continue;
    
            bool moved = false;
            for (int i = 0; !moved && i < 4; i++) 
                if (dirs[i] == 'N') {
                    count = 0;
                    for (int i = -1; i < 2; i++)
                        count += elves.count({elf.first - 1, elf.second + i});
                    if (count == 0) {
                        if (new_positions.count({elf.first - 1, elf.second}) == 0)
                            new_positions[{elf.first - 1, elf.second}] = elf;
                        else
                            new_positions[{elf.first - 1, elf.second}] = {M, M};
                        moved = true;
                    }
                } else if (dirs[i] == 'S') {
                    count = 0;
                    for (int i = -1; i < 2; i++)
                        count += elves.count({elf.first + 1, elf.second + i});
                    if (count == 0) {
                        if (new_positions.count({elf.first + 1, elf.second}) == 0)
                            new_positions[{elf.first + 1, elf.second}] = elf;
                        else
                            new_positions[{elf.first + 1, elf.second}] = {M, M};
                        moved = true;
                    }
                } else if (dirs[i] == 'W') {
                    count = 0;
                    for (int i = -1; i < 2; i++)
                        count += elves.count({elf.first + i, elf.second - 1});
                    if (count == 0) {
                        if (new_positions.count({elf.first, elf.second - 1}) == 0)
                            new_positions[{elf.first, elf.second - 1}] = elf;
                        else
                            new_positions[{elf.first, elf.second - 1}] = {M, M};
                        moved = true;
                    }
                } else if (dirs[i] == 'E') {
                    count = 0;
                    for (int i = -1; i < 2; i++)
                        count += elves.count({elf.first + i, elf.second + 1});
                    if (count == 0) {
                        if (new_positions.count({elf.first, elf.second + 1}) == 0)
                            new_positions[{elf.first, elf.second + 1}] = elf;
                        else
                            new_positions[{elf.first, elf.second + 1}] = {M, M};
                        moved = true;
                    }
                }
        }
      
        if (cycles == 11) {
            int Mx, My, mx, my;
            Mx = My = -1e9;
            mx = my = 1e9;
            for (auto [y, x] : elves) {
                Mx = max(Mx, x);
                My = max(My, y);
                mx = min(mx, x);
                my = min(my, y);
            }
            cout << (Mx - mx + 1) * (My - my + 1) - elves.size() << endl;
        }
      
        if (new_positions.size() == 0) {
            cout << cycles << endl;
            break;
        }        

        for (auto [key, value] : new_positions) {
            if (value != make_pair(M, M)) {
                elves.erase(value);
                elves.insert(key);
            }
        }

        rotate(dirs.begin(), dirs.begin() + 1, dirs.end());
        new_positions.clear();
    }
}