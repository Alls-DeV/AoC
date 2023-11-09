#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long data;
    int counter;
    struct Node* next;
    struct Node* prev;
};

int n = 0;
struct Node* newNode (long long data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->counter = n++;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

struct Node* find (struct Node *node, int distance) {
    if (distance == 0)
        return node;
    return find(node->next, distance - 1);
}

void printList (struct Node* node) {
    auto head = node;
    do {
        cout << node->data << " ";
        node = node->next;
    } while (node != head);
    cout << endl;
}

void solution (vector<long long> &v, bool part2 = false) {
    struct Node *head, *tmp, *zero;
    long long sz, visited;
    head = tmp = zero = NULL;
    sz = visited = 0; 
    for (auto &data : v) {
        sz++;
        if (head == NULL) {
            head = newNode(data * (part2 ? 811589153LL : 1));
            tmp = head;
        } else {
            tmp->next = newNode(data * (part2 ? 811589153LL : 1));
            tmp->next->prev = tmp;
            tmp = tmp->next;
        }
    }
    tmp->next = head;
    head->prev = tmp;

    tmp = head;
    int cycles = (part2 ? 10 : 1);
    while (cycles--) {
        while (visited < sz) {
            struct Node* after = tmp->next;
            if (visited == tmp->counter) {
                visited++;
                if (tmp->data == 0) {
                    zero = tmp;
                } else if (tmp->data % (sz - 1) != 0) {
                    auto end = find(tmp, tmp->data % (sz - 1) + (tmp->data > 0 ? 0 : sz - 1));
                    // remove tmp
                    tmp->prev->next = after;
                    after->prev = tmp->prev;
                    // insert tmp after end
                    tmp->next = end->next;
                    end->next->prev = tmp;
                    end->next = tmp;
                    tmp->prev = end;
                }
            }
            tmp = after;
        }
        visited = 0;
    }
    n = 0;
    cout << find(zero, 1000)->data + find(zero, 2000)->data  + find(zero, 3000)->data << endl;
}

int main() {
    vector<long long> v;
    string line;
    while (getline(cin, line))
        v.push_back(stoi(line));
    solution(v);
    solution(v, true);
}