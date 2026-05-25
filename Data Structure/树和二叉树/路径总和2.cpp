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
            sum -= root -> val;
            return;
        }
        getleaves(pa, pb, root -> left, sum, targetSum);
        getleaves(pa, pb, root -> right, sum, targetSum);
        pb.pop_back();
        sum -= root->val;


    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> pa;
        vector<int> pb;
        int sum = 0;
        getleaves(pa, pb, root, sum, targetSum);
        return pa;
    }
};