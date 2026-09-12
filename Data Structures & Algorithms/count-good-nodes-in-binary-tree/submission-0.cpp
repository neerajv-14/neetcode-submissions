/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int solve(TreeNode* root, int currMaxi){
        if(root==nullptr)return 0;

        
        return ((root->val >= currMaxi) ? 1 : 0) + solve(root->left,max(currMaxi,root->val)) + solve(root->right, max(currMaxi,root->val));
    }
    int goodNodes(TreeNode* root) {
        if(root==nullptr)return 0;

        return solve(root,root->val);
    }
};
