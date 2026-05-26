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
        pa[height] = max(pa[height], root -> val);
        if(root -> left == nullptr && root -> right == nullptr)
        {
            he = max(he, height);
            // height--;
        }
        getleaves(root -> left, height, pa, he);
        getleaves(root -> right, height, pa, he);
        height--;
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> pa(10000,INT_MIN);
        vector<int> pb;
        int height = 0;
        int he = 0;
        getleaves(root, height, pa, he);
        for(auto i=0; i<he; ++i)
        {
            pb.push_back(pa[i+1]);
        }
        return pb;
    }
};