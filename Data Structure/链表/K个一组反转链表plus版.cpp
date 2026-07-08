#include <bits/stdc++.h>
using namespace std;
typedef struct LinkList{
    struct LinkList *next;
    string data[3];   
}ListNode, *List;

void Create_Link(List &L, vector<vector<string>> &a, map<string,int> &addr2idx, int f){
    L = new ListNode();                 
    L->data[0] = a[f][0];
    L->data[1] = a[f][1];
    L->data[2] = a[f][2];
    L->next = nullptr;                  
    ListNode* cur = L;                  
    string nextAddr = a[f][2];

    while(nextAddr != "-1"){            
        int idx = addr2idx[nextAddr];   
        cur->next = new ListNode();
        cur = cur->next;
        cur->data[0] = a[idx][0];
        cur->data[1] = a[idx][1];
        cur->data[2] = a[idx][2];
        cur->next = nullptr;
        nextAddr = a[idx][2];
    }
}

ListNode* reverseKGroup(ListNode* head, int k) {
    
    int i{k};
    ListNode* pre;
    ListNode* next;
    ListNode* res;
    ListNode *begin, *tail;
    bool first{true};
    while(head)
    {
        ListNode* temp = head;
        while(i--){ if(!temp) return res; temp = temp->next; }
        i = k;
        if(first) tail = head;
        begin = head;
        pre = nullptr;
        while(i--){
            if(!head) break;
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        i = k;
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
        addr2idx[a[i][0]] = i;
        if(a[i][0] == start)f = i;
    }

    Create_Link(L, a, addr2idx, f);                     
    ListNode* head = L;                               

    ListNode* res = reverseKGroup(head, k);

    
    ListNode* p = res;
    while(p != nullptr){
        if(p->next != nullptr)
            cout<<p->data[0]<<" "<<p->data[1]<<" "<<p->next->data[0]<<endl;
        else
            cout<<p->data[0]<<" "<<p->data[1]<<" -1"<<endl;
        p = p->next;
    }
}