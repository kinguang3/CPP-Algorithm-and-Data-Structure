#include <bits/stdc++.h>
using namespace std;
#define OK 1
#define ERROR 0
#define Status int


typedef struct LinkList{
    int data;
    ListNode* next;
}ListNode,*LinkList;

//链表初始化
Status InitList(LinkList &L){
    L = new ListNode;
    L->next = NULL;
    return OK;
}

//插入元素
Status InsertList(LinkList &L,int i,int e){
    ListNode* p = L;
    int j = 0;
    while(p != NULL && j < i-1){
        p = p->next;
        j++;
    }
    if(p == NULL){
        return ERROR;
    }
    ListNode* q = new ListNode;
    q->data = e;
    q->next = p->next;
    p->next = q;
    return OK;
}

//删除元素
Status DeleteList(LinkList &L,int i,int &e){
    ListNode* p = L;
    int j = 0;
    while(p != NULL && j < i-1){
        p = p->next;
        j++;
    }
    if(p == NULL){
        return ERROR;
    }
    ListNode* q = p->next;
    p->next = q->next;
    e = q->data;
    delete q;
    return OK;
}



