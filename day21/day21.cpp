#include <bits/stdc++.h>
using namespace std;

vector<string> split(string s) {
    vector<string> tokens;
    set<char> char_to_remove = {' ', ':'};
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

int main () {
    string line;
    map<string, long long> conversions_start;
    vector<vector<string>> to_convert_start;
    while (getline(cin, line)) {
        auto tokens = split(line);
        if (tokens.size() == 2)
            conversions_start[tokens[0]] = stoll(tokens[1]);
        else
            to_convert_start.push_back(tokens);
    }
    
    auto conversions = conversions_start;
    auto to_convert = to_convert_start;
    while (!to_convert.empty()) for (auto it = to_convert.begin(); it != to_convert.end();) {
        if (conversions.count((*it)[1]) &&
            conversions.count((*it)[3])) {
            switch ((*it)[2][0]) {
                case '+':
                    conversions[(*it)[0]] = conversions[(*it)[1]] + conversions[(*it)[3]];
                    break;
                case '*':
                    conversions[(*it)[0]] = conversions[(*it)[1]] * conversions[(*it)[3]];
                    break;
                case '-':
                    conversions[(*it)[0]] = conversions[(*it)[1]] - conversions[(*it)[3]];
                    break;
                case '/':
                    conversions[(*it)[0]] = conversions[(*it)[1]] / conversions[(*it)[3]];
                    break;
            }
            it = to_convert.erase(it++);
        } else
            it++;
    }
    
    cout << conversions["root"] << endl;
    // binary search
    long long low = 1, high = 1e15;
    while (low < high) {
        long long mid = (low + high) / 2;
        conversions = conversions_start;
        to_convert = to_convert_start;
        conversions["humn"] = mid;
        while (!to_convert.empty())
        for (auto it = to_convert.begin(); it != to_convert.end();) {
            if (conversions.count((*it)[1]) &&
                conversions.count((*it)[3])) {
                if ((*it)[0] == "root")
                    conversions[(*it)[0]] = conversions[(*it)[1]] - conversions[(*it)[3]];
                else switch ((*it)[2][0]) {
                    case '+':
                        conversions[(*it)[0]] = conversions[(*it)[1]] + conversions[(*it)[3]];
                        break;
                    case '*':
                        conversions[(*it)[0]] = conversions[(*it)[1]] * conversions[(*it)[3]];
                        break;
                    case '-':
                        conversions[(*it)[0]] = conversions[(*it)[1]] - conversions[(*it)[3]];
                        break;
                    case '/':
                        conversions[(*it)[0]] = conversions[(*it)[1]] / conversions[(*it)[3]];
                        break;
                }
                it = to_convert.erase(it++);
            } else
                it++;
        }
        if (conversions["root"] == 0) {
            cout << mid << endl;
            return 0;
        }
        else if (conversions["root"] < 0)
            high = mid + 1;
        else
            low = mid - 1;
    } 
}