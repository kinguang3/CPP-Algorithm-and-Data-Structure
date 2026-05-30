#include <bits/stdc++.h>
using namespace std;
struct  ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        int x = k;
        ListNode* s = (struct ListNode*)malloc(sizeof(ListNode));
        ListNode* cur = s;
        ListNode* fast = nullptr;
        ListNode* slow = head;
        ListNode* prev = nullptr;
        while(head != nullptr)
        {
            head = head->next;
            n++;
        }
        n /= k;
        for(int i = 1; i <= n; ++i)
        {
            while(x--)
            {
                fast = slow->next;//保存下一个节点
                slow->next = prev;//反转当前节点
                prev = slow;
                slow = fast;
            }
            cur->next = prev;
            while(cur->next)
            {
                cur = cur->next;
            }
            prev = nullptr;
            x = k;
        }
        cur->next = slow;
        ListNode* newl = s->next;//新的头节点
        return newl;
    }
};//反转链表的K个一组，剩余不足K个的部分保持原样。使用三个指针prev、slow和fast来进行反转操作。首先计算链表的长度n，然后根据n和k的关系进行反转操作。每次反转k个节点后，将prev指针重新置空，继续反转下一个k个节点。最后将剩余的节点连接到反转后的链表末尾。