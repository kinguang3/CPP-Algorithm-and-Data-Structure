#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k ==0 || head == nullptr || head -> next == nullptr)
        {
            return head;
        }
        int n=1;
        struct ListNode* tail = head;
        while(tail->next != nullptr)
        {
            tail = tail -> next;
            n++;
        }
        int movement = k%n;
        if(movement == 0)
        {
            return head;
        }
        tail->next = head;
        int add = n-movement;
        while(add--)
        {
            tail = tail->next;
            
        }
        struct ListNode* newnode = tail -> next;//新的头节点
        tail->next = nullptr;//断开链表
        return newnode;
    }
};