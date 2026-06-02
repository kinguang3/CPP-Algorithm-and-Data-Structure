#include <bit>s/stdc++.h>
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
    TreeNode* FindParents(TreeNode* anicent, TreeNode* p, TreeNode* q)
    {

        while (true)
        {
            if(anicent -> val > p -> val && anicent -> val > q -> val)
            {
                anicent = anicent -> left;
            }
            else if(anicent -> val < p -> val && anicent -> val < q -> val)
            {
                anicent = anicent -> right;
            }
            else break;
        }
        return anicent;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = FindParents(root, p, q);
        return res;
    }
};