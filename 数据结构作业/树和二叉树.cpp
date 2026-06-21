#include <bits/stdc++.h>
using namespace std;

typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;


int Cout_Leaves(BiTree T) {
    if (T == NULL) {
        return 0; // 空树没有叶子节点
    }
    if (T->lchild == NULL && T->rchild == NULL) {
        return 1; // 当前节点是叶子节点
    }
    return Cout_Leaves(T->lchild) + Cout_Leaves(T->rchild); // 递归统计左右子树的叶子节点数
}


bool Judge_Same_BiTree(BiTree T1, BiTree T2) {
    if (T1 == NULL && T2 == NULL) {
        return true; // 两棵树都为空，视为相同
    }
    if (T1 == NULL || T2 == NULL) {
        return false; // 一棵树为空，另一棵树不为空，不相同
    }
    if (T1->data != T2->data) {
        return false; // 当前节点的值不同，不相同
    }
    // 递归比较左右子树
    return Judge_Same_BiTree(T1->lchild, T2->lchild) && Judge_Same_BiTree(T1->rchild, T2->rchild);
}


void Change_Leaves(BiTree &T) {
    if (T == NULL) {
        return; // 空树没有叶子节点
    }
    BiTree L = T -> lchild; // 保存当前节点的指针
    BiTree R = T -> rchild; // 保存当前节点的指针
    swap(L -> data, R -> data); // 交换左右子树的值
    Change_Leaves(L); // 递归交换左子树的叶子节点
    Change_Leaves(R); // 递归交换右子树的叶子节点
}


void Double_Search_Tree(BiTree &T) {
    if (T == NULL) {
        return; // 空树不需要处理
    }
    cout << T->data << " "; // 输出当前节点的值
    Double_Search_Tree(T->lchild); // 递归处理左子树
    cout << T->data << " "; // 输出当前节点的值
    Double_Search_Tree(T->rchild); // 递归处理右子树
}


// 计算二叉树的宽度
int Tree_Width(BiTree T) {
    if (T == NULL) {
        return 0; // 空树宽度为0
    }
    queue<BiTree> q; // 使用队列进行层次遍历
    q.push(T); // 将根节点入队
    int maxWidth = 0; // 初始化最大宽度为0

    while (!q.empty()) {
        int levelSize = q.size(); // 当前层的节点数
        maxWidth = max(maxWidth, levelSize); // 更新最大宽度

        for (int i = 0; i < levelSize; ++i) {
            BiTree node = q.front(); // 获取队首节点
            q.pop(); // 出队

            if (node->lchild != NULL) {
                q.push(node->lchild); // 左子节点入队
            }
            if (node->rchild != NULL) {
                q.push(node->rchild); // 右子节点入队
            }
        }
    }

    return maxWidth; // 返回最大宽度
}


