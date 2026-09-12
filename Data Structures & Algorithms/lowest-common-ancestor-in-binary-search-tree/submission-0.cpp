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
    pair<TreeNode*,bool> solve(TreeNode* root,TreeNode* p, TreeNode* q){
        if(root==p || root==q){
            return make_pair(root,true);
        }
        if(root==nullptr){
            return make_pair(root,false);
        }
        pair<TreeNode*,bool> left = solve(root->left, p, q);
        pair<TreeNode*,bool> right = solve(root->right,p,q);

        if(left.second && right.second)return make_pair(root,true);
        if(left.second)return make_pair(left.first, true);
        if(right.second)return make_pair(right.first,true);
        return make_pair(left.first,false);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q).first;
    }
};
