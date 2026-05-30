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
    void getleaves(vector<vector<int>> &pa, vector<int> &pb, TreeNode *root, int &sum, int targetSum)
    {
        if(root == nullptr)return;
        sum += root -> val;
        pb.push_back(root -> val);
        if(root -> left == nullptr && root -> right == nullptr)
        {
            if(sum == targetSum)
            {
                pa.push_back(pb);
            }
            pb.pop_back();
            sum -= root -> val;//回退到父节点，因为在递归调用中，sum已经加上了当前节点的值，所以在回退时需要减去当前节点的值，以恢复到父节点的状态。
            return;
        }
        getleaves(pa, pb, root -> left, sum, targetSum);//递归调用左子树
        getleaves(pa, pb, root -> right, sum, targetSum);//递归调用右子树
        pb.pop_back();//回退到父节点
        sum -= root->val;//回退到父节点，因为在递归调用中，sum已经加上了当前节点的值，所以在回退时需要减去当前节点的值，以恢复到父节点的状态。


    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> pa;
        vector<int> pb;
        int sum = 0;
        getleaves(pa, pb, root, sum, targetSum);
        return pa;
    }
};