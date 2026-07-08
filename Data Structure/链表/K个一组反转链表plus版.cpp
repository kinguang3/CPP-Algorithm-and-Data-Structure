#include <bits/stdc++.h>
using namespace std;
typedef struct LinkList{
    struct LinkList *next;
    string data[3];   // [0]:地址, [1]:值, [2]:下一个地址
}ListNode, *List;

// 根据输入数据构建链表，按地址链接节点
void Create_Link(List &L, vector<vector<string>> &a, map<string,int> &addr2idx, int f){
    L = new ListNode();                  // 创建头节点
    L->data[0] = a[f][0];
    L->data[1] = a[f][1];
    L->data[2] = a[f][2];
    L->next = nullptr;                  
    ListNode* cur = L;                  
    string nextAddr = a[f][2];           // 当前节点的下一个地址

    while(nextAddr != "-1"){             // 直到链表末尾
        int idx = addr2idx[nextAddr];    // 通过地址映射找到下一节点的索引
        cur->next = new ListNode();
        cur = cur->next;
        cur->data[0] = a[idx][0];
        cur->data[1] = a[idx][1];
        cur->data[2] = a[idx][2];
        cur->next = nullptr;
        nextAddr = a[idx][2];
    }
}

// K个一组反转链表
ListNode* reverseKGroup(ListNode* head, int k) {
    
    int i{k};
    ListNode* pre;    // 已反转部分的前驱
    ListNode* next;   // 暂存下一节点
    ListNode* res;    // 结果链表头
    ListNode *begin, *tail;  // 当前组的头和尾
    bool first{true};
    while(head)
    {
        // 检查剩余节点是否够k个
        ListNode* temp = head;
        while(i--){ if(!temp) return res; temp = temp->next; }
        i = k;
        if(first) tail = head;
        begin = head;
        pre = nullptr;
        // 反转当前k个节点
        while(i--){
            if(!head) break;
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        i = k;
        // 将上一组的尾连接到当前组的头
        if(!first) tail->next = pre;
        tail = begin;
        begin->next = head;
        if(first){ res = pre; first = false; }
    }
    return res;
}

int main(){
    string start;                                      
    int n, k, f;
    ListNode* L = nullptr;                              
    vector<vector<string>> a(1e5+5, vector<string>(3));  
    map<string,int> addr2idx;                           

    cin>>start>>n>>k;
    for(auto i = 1; i <= n; ++i){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        addr2idx[a[i][0]] = i;             // 地址 -> 数组索引映射
        if(a[i][0] == start)f = i;         // 找到起始节点
    }

    Create_Link(L, a, addr2idx, f);        // 构建链表
    ListNode* head = L;                               

    ListNode* res = reverseKGroup(head, k);  // K个一组反转

    // 输出结果
    ListNode* p = res;
    while(p != nullptr){
        if(p->next != nullptr)
            cout<<p->data[0]<<" "<<p->data[1]<<" "<<p->next->data[0]<<endl;
        else
            cout<<p->data[0]<<" "<<p->data[1]<<" -1"<<endl;
        p = p->next;
    }
}