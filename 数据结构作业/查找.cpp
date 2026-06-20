#include <bits/stdc++.h>
using namespace std;

int a[1000];
typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int Search_bin(int a[], int n, int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2; // 防止溢出
        if (a[mid] == key) 
        {
            return mid;
        } 
        else if (a[mid] < key)
        {
            return Search_bin(a, n, mid + 1, high, key); // 在右半部分继续搜索
        } 
        else 
        {
            return Search_bin(a, n, low, mid - 1, key); // 在左半部分继续搜索
        }
    }
    return -1;  
}

bool Judge_SortTree(BiTree T, int &pre) {
    if (T == NULL) {
        return true;
    }
    if (!Judge_SortTree(T->lchild, pre)) {
        return false;
    }
    if (T->data <= pre) {
        return false; // 当前节点的值必须大于前一个节点的值
    }
    pre = T->data; // 更新前一个节点的值
    return Judge_SortTree(T->rchild, pre);
}



void Find_Element(BiTree T, int key) {
    if (T == NULL) {
        cout << "Element not found." << endl;
        return;
    }
    Find_Element(T->lchild, key);
    if (T->data >= key) {
        cout << T->data <<" "<< endl;
    }
    Find_Element(T->rchild, key);
}



