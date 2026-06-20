#include <bits/stdc++.h>
using namespace std;

#define ok 1
#define error 0


typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prior;
} listNode, *linkList;


void initList(linkList &L) {
    L = (linkList)malloc(sizeof(listNode));
    L->next = NULL;
    L->prior = NULL;
}



