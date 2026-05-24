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
    void getleaves(vector<int> &pa, TreeNode *tree)
    {
        if(tree == nullptr) return;
        if(tree -> left == nullptr && tree -> right == nullptr)
        {
            pa.push_back(tree -> val);
        }
        getleaves(pa, tree -> left);
        getleaves(pa, tree -> right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1,r2;
        getleaves(r1, root1);
        getleaves(r2, root2);
        if(r1.size() != r2.size())return false;
        for(auto i=0; i < max(r1.size(),r2.size()); ++i)
        {
            if(r1[i] != r2[i])return false;
            else continue;
        }
        return true;
    }
};