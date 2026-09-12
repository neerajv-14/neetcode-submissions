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
    pair<pair<int,int>,bool> solve(TreeNode* root){
        if(root->left==nullptr && root->right == nullptr){
            return make_pair(make_pair(root->val,root->val), true);
        }
        // <<mini,maxi>,flag>
        pair<pair<int,int>,bool> left, right;
        bool flag = true;
        int maxi = root->val, mini = root->val;
        if(root->left!=nullptr){
            left = solve(root->left);
            flag = flag && left.second && (left.first.second < root->val);
            mini = min(mini, left.first.first);
        }

        if(root->right!=nullptr){
            right = solve(root->right);
            flag = flag && right.second && (right.first.first > root->val);
            maxi = max(maxi,right.first.second);
        }

        return make_pair(make_pair(mini,maxi),flag);
        
    }
    bool isValidBST(TreeNode* root) {
        return solve(root).second;
    }
};
