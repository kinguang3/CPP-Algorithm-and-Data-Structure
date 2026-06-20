#include <bits/stdc++.h>
using namespace std;

int a[1000];
typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct VNode{
    int data;
    struct VNode *next;
} VNode, *AdjList[1000];


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


//递归创建平衡二叉搜索树
void Create_BST(BiTree &T, int a[], int n) {
    if (n == 0) {
        T = NULL;
        return;
    }
    int mid = n / 2; // 选择中间元素作为根节点
    T = new BiTNode; // 创建根节点
    T->data = a[mid]; // 设置根节点的值
    Create_BST(T->lchild, a, mid); // 递归创建左子树
    Create_BST(T->rchild, a + mid + 1, n - mid - 1); // 递归创建右子树
}


int BiTree_Depth(BiTree T) {
    if (T == NULL) {
        return 0; // 空树的深度为0
    }
    int leftDepth = BiTree_Depth(T->lchild); // 左子树深度
    int rightDepth = BiTree_Depth(T->rchild); // 右子树深度
    return max(leftDepth, rightDepth) + 1; // 当前节点的深度为左右子树深度的最大值加1
}


int H(int x, int n)
{
    if (x == 0) {
        return 0; // 空树的高度为0
    }
    return x % (n + 1); // 完全二叉树的高度公式
}


void Add_Hash_Ele(AdjList &G, int n, int m) {
    for (int i = 0; i < n; i++) {
        G[i] = NULL; // 初始化邻接表
    }
    for (int i = 0; i < n; ++i) {
        if(G[H(m, n)] == NULL) G[H(m, n)] -> data = m;
        else {
            while(G[H(m, n)] -> next != NULL) {
                G[H(m, n)] = G[H(m, n)] -> next;
            }
            G[H(m, n)] -> data = m;
        }
    }
}


void Delete_Hash_Ele(AdjList &G, int n, int m) {
    int hashIndex = H(m, n);
    VNode* current = G[hashIndex];
    VNode* prev = NULL;

    while (current != NULL) {
        if (current->data == m) {
            if (prev == NULL) 
            {
                G[hashIndex] = current->next; // 删除头节点
            } 
            else 
            {
                prev->next = current->next; // 删除非头节点
            }
            delete current; // 释放内存
            return;
        }
        prev = current;
        current = current->next;
    }
}