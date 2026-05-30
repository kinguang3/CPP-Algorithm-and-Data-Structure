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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//对于环形链表，我们可以使用快慢指针来判断是否存在环，如果存在环，那么快慢指针一定会在某个节点相遇。相遇后，我们将其中一个指针重新指向链表头部，然后两个指针以相同的速度前进，直到它们再次相遇，相遇的节点就是环的入口节点。
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL||head->next == NULL)
        {
            return NULL;
        }
        int pos;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pa = head;
        while(fast != NULL)
        {
            if(fast->next == NULL)
            {
                return NULL;
            }
            fast = fast->next->next;//快指针每次移动两步
            slow = slow->next;//慢指针每次移动一步
            if(slow == fast)//如果快慢指针相遇，说明存在环
            {
                while(pa!=slow)//将其中一个指针重新指向链表头部，然后两个指针以相同的速度前进，直到它们再次相遇，相遇的节点就是环的入口节点
                {
                    pa = pa->next;
                    slow = slow->next;
                }
                return pa;
            }
            
        }
        return NULL;
    }
};