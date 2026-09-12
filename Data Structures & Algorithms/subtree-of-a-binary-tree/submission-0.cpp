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
    bool check(TreeNode* root, TreeNode* subRoot){
        if(root==nullptr && subRoot==nullptr)return true;

        if(root==nullptr || subRoot==nullptr)return false;

        return (root->val == subRoot->val ) && check(root->left,subRoot->left) && check(root->right,subRoot->right);
    }
    void solve(TreeNode* root,TreeNode* subRoot,bool& ans){
        if(ans)return;

        if(root==nullptr)return;
        
        ans= check(root,subRoot);

        solve(root->left,subRoot,ans);
        solve(root->right,subRoot,ans);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans = false;
        solve(root,subRoot,ans);
        return ans;
    }
};
