#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct cmp {
    bool operator()(Node* a, Node* b) {
        return a->val > b->val;  // 小根堆
    }
};

Node* buildHuffman(vector<int>& weights) {
    priority_queue<Node*, vector<Node*>, cmp> pq;
    
    for (int w : weights) {
        pq.push(new Node(w));
    }
    
    while (pq.size() > 1) {
        Node* l = pq.top(); pq.pop();
        Node* r = pq.top(); pq.pop();
        
        Node* p = new Node(l->val + r->val);
        p->left = l;
        p->right = r;
        
        pq.push(p);
    }
    
    return pq.top();
}