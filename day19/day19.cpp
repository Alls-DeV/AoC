#include <bits/stdc++.h>
using namespace std;

vector<int> split(string s) {
    vector<int> tokens;
    string token;
    for (auto c : s) {
        if ('0' <= c && c <= '9') {
            token.push_back(c);
        } else if (token.size() > 0) {
            tokens.push_back(stoi(token));
            token.clear();
        }
    }
    return tokens;
}

vector<int> blueprint;
map<array<int, 9>, int> memo;
array<int, 3> maxes;
// each state = {ore, clay, obsidian, geode, ore_robot, clay_robot, obsidian_robot, geode_robot, minutes}
int f (array<int, 9> state) {
    if (state[8] == 1)
        return state[3] + state[7];
    if (memo.count(state))
        return memo[state];
    int ans = state[3];
    for (int i = 0; i < 5; i++) {
        auto new_state = state;
        new_state[8]--;
        switch (i)
        {
        case 0: // geode_robot
            new_state[0] -= blueprint[5];
            new_state[2] -= blueprint[6];
            break;
        case 1: // obsidian_robot
            new_state[0] -= blueprint[3];
            new_state[1] -= blueprint[4];
            break;
        case 2: // clay_robot
            new_state[0] -= blueprint[2];
            break;
        case 3: // ore_robot
            new_state[0] -= blueprint[1];
            break;
        case 4: // nothing
            break;
        }

        if (*min_element(new_state.begin(), new_state.end()) < 0 ||
            max(blueprint[1], max(blueprint[2], max(blueprint[3], blueprint[5]))) < new_state[4] ||
            blueprint[4] < new_state[5] ||
            blueprint[6] < new_state[6])
            continue;

        for (int j = 0; j < 4; j++) {
            new_state[j] += new_state[j + 4];
            // important optimization to reduce the number of possible states
            if (j != 3)
                new_state[j] = min(new_state[j], maxes[j] * new_state[8]);
        }
        if (i != 4)
            new_state[7 - i]++;
        ans = max(ans, f(new_state));
        if (i == 0)
            break;
    }
    memo[state] = ans;
    return ans;
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    auto last = start;
    string line;
    int ans1, ans2;
    ans1 = 0;
    ans2 = 1;
    int count = 0;
    while (getline(cin, line)) {
        blueprint = split(line);
        maxes[0] = max(blueprint[1], max(blueprint[2], max(blueprint[3], blueprint[5])));
        maxes[1] = blueprint[4];
        maxes[2] = blueprint[6];
        cout << "cycle number " << count + 1 << " time: "; 
        ans1 += blueprint[0]*f({0, 0, 0, 0, 1, 0, 0, 0, 24});
        if (count++ < 3)
            ans2 *= f({0, 0, 0, 0, 1, 0, 0, 0, 32});
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - last);
        last = stop;
        cout << duration.count()/(1e6) << endl;
        memo.clear();
    }
    cout << ans1 << endl << ans2 << endl;
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << duration.count()/(1e6) << endl;
}