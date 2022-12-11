#include <bits/stdc++.h>
using namespace std;

vector<string> split(string s) {
    vector<string> tokens;
    set<char> char_to_remove = {' ', ','};
    s = s + (*char_to_remove.begin());
    string token;
    for (auto c : s) {
        if (char_to_remove.find(c) == char_to_remove.end()) {
            token.push_back(c);
        } else if (token.size() > 0) {
            tokens.push_back(token);
            token.clear();
        }
    }
    return tokens;
}

void solution() {
    vector<vector<long long>> monkeys;
    vector<pair<char, long long>> operations;
    vector<long long> divisible;
    vector<pair<int, int>> choices;

    // input
    string line;
    while (getline(cin, line)) {
        // starting items
        getline(cin, line);
        vector<string> token = split(line);
        vector<long long> monkey;
        for (int i = 2; i < token.size(); i++)
            monkey.push_back(stoi(token[i]));
        monkeys.push_back(monkey);

        // operation
        pair<char, long long> operation;
        getline(cin, line);
        token = split(line);
        operation.first = token[4][0];
        if (token[5] == "old")
            operation.second = -1;
        else
            operation.second = stoi(token[5]);
        operations.push_back(operation);

        // divisible
        getline(cin, line);
        token = split(line);
        divisible.push_back(stoi(token[3]));

        // choices
        // true
        pair<int, int> choice;
        getline(cin, line);
        token = split(line);
        choice.first = stoi(token[5]);
        // false
        getline(cin, line);
        token = split(line);
        choice.second = stoi(token[5]);

        choices.push_back(choice);

        getline(cin, line);
    }

    vector<long long> ans(monkeys.size());

    // lcm of all elements in divisible
    long long lcm = 1;
    for (auto item : divisible)
        lcm = lcm * item / __gcd(lcm, item);

    int n = 10000;
    while (n--) {
        for (int i = 0; i < monkeys.size(); i++) {
            for (auto item : monkeys[i]) {
                long long new_item;

                if (operations[i].first == '+')
                    new_item = (item%lcm + (operations[i].second == -1 ? item : operations[i].second)%lcm)%lcm;
                else
                    new_item = (item%lcm * (operations[i].second == -1 ? item : operations[i].second)%lcm)%lcm;
                
                // comment next line if second part
                // new_item /= 3;

                if (new_item % divisible[i] == 0)
                    monkeys[choices[i].first].push_back(new_item);
                else
                    monkeys[choices[i].second].push_back(new_item);
            }
            ans[i] += monkeys[i].size();
            monkeys[i].clear();
        }
    }

    sort(ans.begin(), ans.end(), greater<long long>());
    cout << ans[0]*ans[1] << endl;
}
 
int main() {
    solution();
}
