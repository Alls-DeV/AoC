#include <bits/stdc++.h>
#ifdef ALE
    #include "/home/alls/CompetitiveProgramming/Library/debug.h"
#else
    #define dbg(...)
#endif
using namespace std;
const int INF = INT32_MAX;

vector<string> split(string s) {
    vector<string> tokens;
    set<char> char_to_use = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    s = s + " ";
    string token;
    for (auto c : s) {
        if (char_to_use.find(c) != char_to_use.end()) {
            token.push_back(c);
        } else if (token.size() > 0) {
            tokens.push_back(token);
            token.clear();
        }
    }
    return vector<string>(tokens.begin() + 1, tokens.end());
}

vector<pair<int, vector<int>>> graph;
map<string, int> string_to_index;
map<int, int> shift_index;
map<tuple<int, int, long long>, pair<int, long long>> memo;

// state = {node, time, visited}
pair<int, long long> f (int node = 0, int time = 30, long long visited = 0) {
    if (time <= 0)
        return {0, visited};
    pair<int, long long> ans = {0, visited};
    for (auto edge : graph[node].second) {
        // if node where I am is not visited
        if (graph[node].first && (visited & (1LL << shift_index[node])) == 0) {
            long long new_visited = visited | (1LL << shift_index[node]);
            tuple<int, int, long long> state = {edge, time - 2, new_visited};
            if (memo.count(state) == 0)
                memo[state] = f(edge, time - 2, new_visited);
            auto new_ans = memo[state];
            new_ans.first += (graph[node].first)*(time - 1);
            if (new_ans.first > ans.first)
                ans = new_ans;
        }

        tuple<int, int, long long> state = {edge, time - 1, visited};
        if (memo.count(state) == 0)
            memo[state] = f(edge, time - 1, visited);

        auto new_ans = memo[state];
        if (new_ans.first > ans.first)
            ans = new_ans;
    }

    memo[{node, time, visited}] = ans;
    return ans;
}

int main() {
    int index = 0;
    string line;
    while (getline(cin, line)) {
        vector<string> tokens = split(line);
        for (int i = 0; i < tokens.size(); i++) {
            if (i != 1 && string_to_index.count(tokens[i]) == 0) {
                string_to_index[tokens[i]] = index++;
                graph.push_back({0, vector<int>()});
            }
        }
        graph[string_to_index[tokens[0]]].first = stoi(tokens[1]);
        for (int i = 2; i < tokens.size(); i++) 
            graph[string_to_index[tokens[0]]].second.push_back(string_to_index[tokens[i]]);
    }

    index = 0;
    for (int i = 0; i < graph.size(); i++)
        if (graph[i].first > 0)
            shift_index[i] = index++;
    // part1
    cout << f().first << endl;
    // part2
    auto [ans, visited] = f(string_to_index["AA"], 26);
    cout << ans + f(string_to_index["AA"], 26, visited).first << endl;
}