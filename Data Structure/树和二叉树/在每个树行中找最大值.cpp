#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    void getleaves(TreeNode *root, int &height, vector<int> &pa, int &he)
    {
        if(root == nullptr)return;
        height++;
        pa[height] = max(pa[height], root -> val);//如果当前节点的值比当前层的最大值还大，就更新当前层的最大值
        if(root -> left == nullptr && root -> right == nullptr)
        {
            he = max(he, height);
            // height--;
        }
        getleaves(root -> left, height, pa, he);
        getleaves(root -> right, height, pa, he);
        height--;//回退到父节点，因为在递归调用中，height已经加上了当前节点的值，所以在回退时需要减去当前节点的值，以恢复到父节点的状态。
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> pa(10000,INT_MIN);
        vector<int> pb;
        int height = 0;
        int he = 0;
        getleaves(root, height, pa, he);
        for(auto i=0; i<he; ++i)
        {
            pb.push_back(pa[i+1]);//将每一层的最大值加入到结果数组中,因为在递归调用中，height是从1开始的，所以在访问pa数组时需要使用i+1作为索引。
        }
        return pb;
    }
};