#include <bits/stdc++.h>
using namespace std;

void solution1() {
    string s;
    vector<string> position;
    map<string, int> dimension;

    while (getline(cin, s)) {
        if ("-1" == s)
            break;
        if ("cd" == s.substr(0, 2)) {
            if (".." == s.substr(3))
                position.pop_back();
            else if ("/" == s.substr(3))
                position = {"/"};
            else
                position.push_back(s.substr(3));
        } else if ("ls" == s.substr(0, 2)) {
            continue;
        } else {
            if ("dir" == s.substr(0, 3)) {
                continue;
            } else {
                int dim = stoi(s.substr(0, s.find(' ')));
                string pos = "";
                for (auto folder : position) {
                    pos = pos + "/" + folder;
                    dimension[pos] += dim;
                }
            }
        }
    }

    int ans = 0;
    for (auto [k, v] : dimension)
        if (v <= 100000)
            ans += v;
    cout << ans << endl;
}

void solution2() {
    string s;
    vector<string> position;
    map<string, int> dimension;

    while (getline(cin, s)) {
        if ("-1" == s)
            break;
        if ("cd" == s.substr(0, 2)) {
            if (".." == s.substr(3))
                position.pop_back();
            else if ("/" == s.substr(3))
                position = {"/"};
            else
                position.push_back(s.substr(3));
        } else if ("ls" == s.substr(0, 2)) {
            continue;
        } else {
            if ("dir" == s.substr(0, 3)) {
                continue;
            } else {
                int dim = stoi(s.substr(0, s.find(' ')));
                string pos = "";
                for (auto folder : position) {
                    pos = pos + "/" + folder;
                    dimension[pos] += dim;
                }
            }
        }
    }

    int free_space = 70000000 - dimension["//"];
    int space_needed = 30000000 - free_space;
    int ans = INT32_MAX; 
    for (auto [k, v] : dimension)
        if (v >= space_needed)
            ans = min(ans, v);
    cout << ans << endl;
} 

int main() {
    solution1();
    solution2();
}
