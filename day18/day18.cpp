#include <bits/stdc++.h>
#ifdef ALE
    #include "/home/alls/CompetitiveProgramming/Library/debug.h"
#else
    #define dbg(...)
#endif
using namespace std;

tuple<int, int, int> split(string s) {
    // for example s = "12,2,3"
    vector<int> tokens;
    set<char> char_to_remove = {','};
    s = s + (*char_to_remove.begin());
    string token;
    for (auto c : s) {
        if (char_to_remove.find(c) == char_to_remove.end()) {
            token.push_back(c);
        } else if (token.size() > 0) {
            tokens.push_back(stoi(token));
            token.clear();
        }
    }
    return {tokens[0], tokens[1], tokens[2]};
}

const int DIM = 20;
vector<vector<vector<char>>> cube(DIM, vector<vector<char>>(DIM, vector<char>(DIM, 0)));

bool is_legal(int x, int y, int z) {
    return x >= 0 && x < DIM && y >= 0 && y < DIM && z >= 0 && z < DIM;
}

bool inner_obsidian (int x, int y, int z) {
    cube[x][y][z] = 3;
    bool ans = true;
    
    array<int, 3> moves[6] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
    for (auto [dx, dy, dz] : moves) {
        int nx = x + dx;
        int ny = y + dy;
        int nz = z + dz;
        if (!is_legal(nx, ny, nz))
            ans = false;
        else if (cube[nx][ny][nz] == 0)
            ans &= inner_obsidian(nx, ny, nz);
    }

    return ans;
}

int dfs (int x, int y, int z) {
    cube[x][y][z] = 2;
    int ans = 0;
    
    array<int, 3> moves[6] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
    for (auto [dx, dy, dz] : moves) {
        int nx = x + dx;
        int ny = y + dy;
        int nz = z + dz;
        if (!is_legal(nx, ny, nz) || cube[nx][ny][nz] == 0 || cube[nx][ny][nz] == 4)
            ans++;
        else if (cube[nx][ny][nz] == 1)
            ans += dfs(nx, ny, nz);
    }

    return ans;
}

int main() {
    string line;
    while (getline(cin, line)) {
        auto [x, y, z] = split(line);
        cube[x][y][z] = 1;
    }

    int ans = 0;
    for (int i = 0; i < DIM; i++)
        for (int j = 0; j < DIM; j++)
            for (int k = 0; k < DIM; k++)
                if (cube[i][j][k] == 1)
                    ans += dfs(i, j, k);

    cout << ans << endl;

    for (int i = 0; i < DIM; i++)
        for (int j = 0; j < DIM; j++)
            for (int k = 0; k < DIM; k++) if (cube[i][j][k] == 0) {
                bool tmp = inner_obsidian(i, j, k);
                for (int ii = 0; ii < DIM; ii++)
                    for (int jj = 0; jj < DIM; jj++)
                        for (int kk = 0; kk < DIM; kk++)
                            if (cube[ii][jj][kk] == 3)
                                cube[ii][jj][kk] = (tmp ? 2 : 4);
            }

    ans = 0;
    for (int i = 0; i < DIM; i++)
        for (int j = 0; j < DIM; j++)
            for (int k = 0; k < DIM; k++)
                if (cube[i][j][k] == 2)
                    ans += dfs(i, j, k);

    cout << ans << endl;
}