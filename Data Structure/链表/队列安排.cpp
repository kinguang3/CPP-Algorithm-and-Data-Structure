#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int data;
    ListNode *prev;
    ListNode *next;
    ListNode(int x) : data(x), prev(nullptr), next(nullptr) {}
};
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    if (N <= 0) return 0;

    vector<ListNode*> nodes(N + 1, nullptr);
    ListNode *head = new ListNode(1);
    nodes[1] = head;

    for (int i = 2; i <= N; i++) {
        int k, p;
        cin >> k >> p;
        ListNode *node = new ListNode(i);//构造新节点
        nodes[i] = node;

        ListNode *target = nodes[k];
        if (p == 0) {
            node->next = target;
            node->prev = target->prev;
            if (target->prev) {
                target->prev->next = node;
            } else {
                head = node;
            }
            target->prev = node;
        } else {
            node->prev = target;
            node->next = target->next;
            if (target->next) {
                target->next->prev = node;
            }
            target->next = node;
        }
    }

    int M;
    cin >> M;
    while (M--) {
        int x;
        cin >> x;
        if (x >= 1 && x <= N && nodes[x] != nullptr) {
            ListNode *node = nodes[x];
            if (node->prev) {
                node->prev->next = node->next;
            } else {
                head = node->next;
            }
            if (node->next) {
                node->next->prev = node->prev;
            }
            nodes[x] = nullptr;
            delete node;
        }
    }

    bool first = true;
    for (ListNode *p = head; p != nullptr; p = p->next) {
        if (!first) cout << ' ';
        cout << p->data;
        first = false;
    }
    cout << '\n';

    return 0;
}