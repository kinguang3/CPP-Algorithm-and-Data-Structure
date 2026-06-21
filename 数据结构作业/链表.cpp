#include <bits/stdc++.h>
using namespace std;

#define ok 1
#define error 0


typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prior;
} listNode, *LinkList;


void initList(LinkList &L) {
    L = (LinkList)malloc(sizeof(listNode));
    L->next = NULL;
    L->prior = NULL;
}


LinkList MergeUnique(LinkList La, LinkList Lb) {
    listNode *pa = La->next, *pb = Lb->next, *pc = La;
    while (pa && pb) {
        if (pa->data < pb->data) {
            pc->next = pa; pc = pa; pa = pa->next;
        } else if (pa->data > pb->data) {
            pc->next = pb; pc = pb; pb = pb->next;
        } else {
            pc->next = pa; pc = pa; pa = pa->next;
            listNode *tmp = pb; pb = pb->next; free(tmp);
        }
    }
    pc->next = pa ? pa : pb;
    free(Lb);
    return La;
}


LinkList MergeDescend(LinkList La, LinkList Lb) {
    listNode *pa = La->next, *pb = Lb->next, *pc = La;
    while (pa && pb) {
        if (pa->data <= pb->data) { pc->next = pa; pc = pa; pa = pa->next; }
        else                      { pc->next = pb; pc = pb; pb = pb->next; }
    }
    pc->next = pa ? pa : pb;
    free(Lb);
    // 原地逆置
    listNode *prev = NULL, *curr = La->next, *next;
    while (curr) { next = curr->next; curr->next = prev; prev = curr; curr = next; }
    La->next = prev;
    return La;
}


LinkList Intersection(LinkList La, LinkList Lb) {
    listNode *pa = La->next, *pb = Lb->next, *pc = La;
    while (pa && pb) {
        if (pa->data == pb->data) {
            pc->next = pa; pc = pa; pa = pa->next; pb = pb->next;
        } else if (pa->data < pb->data) {
            listNode *tmp = pa; pa = pa->next; free(tmp);
        } else {
            pb = pb->next;
        }
    }
    while (pa) { listNode *tmp = pa; pa = pa->next; free(tmp); }
    pc->next = NULL;
    return La;
}


int Difference(LinkList La, LinkList Lb) {
    listNode *pa = La->next, *pb = Lb->next, *pc = La;
    int count = 0;
    while (pa && pb) {
        if (pa->data < pb->data) {
            pc->next = pa; pc = pa; pa = pa->next; count++;
        } else if (pa->data > pb->data) {
            pb = pb->next;
        } else {
            listNode *tmp = pa; pa = pa->next; free(tmp); pb = pb->next;
        }
    }
    while (pa) { pc->next = pa; pc = pa; pa = pa->next; count++; }
    pc->next = NULL;
    return count;
}


void SplitList(LinkList La, LinkList *Lb, LinkList *Lc) {
    *Lb = La;
    *Lc = (listNode*)malloc(sizeof(listNode));
    (*Lc)->next = NULL;
    listNode *pb = *Lb, *pc = *Lc, *p = La->next;
    (*Lb)->next = NULL;
    while (p) {
        listNode *next = p->next;
        if (p->data < 0) { pb->next = p; pb = p; }
        else             { pc->next = p; pc = p; }
        p = next;
    }
    pb->next = pc->next = NULL;
}


LinkList MaxNode(LinkList L) {
    listNode *p = L->next;
    if (!p) return NULL;
    listNode *maxp = p;
    while ((p = p->next))
        if (p->data > maxp->data) maxp = p;
    return maxp;
}


LinkList Reverse(LinkList L) {
    listNode *prev = NULL, *curr = L->next, *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    L->next = prev;
    return L;
}


void DeleteRange(LinkList L, int mink, int maxk) {
    listNode *p = L;
    while (p->next && p->next->data <= mink)
        p = p->next;
    while (p->next && p->next->data < maxk) {
        listNode *tmp = p->next;
        p->next = tmp->next;
        free(tmp);
    }
}


void Change(listNode *p) {
    listNode *q     = p->prior;
    listNode *qprev = q->prior;
    listNode *pnext = p->next;
    qprev->next = p;   p->prior  = qprev;
    p->next     = q;   q->prior  = p;
    q->next     = pnext; pnext->prior = q;
}


void DeleteItem(listNode *L, int item, int n) {
    int k = 0;
    for (int i = 0; i < n; i++)
        if (L->data != item)
            L = L->next;
}