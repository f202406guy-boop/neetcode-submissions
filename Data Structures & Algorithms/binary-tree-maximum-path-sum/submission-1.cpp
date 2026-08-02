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
    int mx_sum(TreeNode* t)
    {
       if(t==nullptr) return 0;
       int nxt_l=mx_sum(t->left);
       int nxt_r=mx_sum(t->right);
       return max(t->val + max({0, nxt_l, nxt_r}),0);
    }
    int maxPathSum(TreeNode* root) {
        if(root==nullptr) return INT_MIN;
       int l=0,r=0;
       if(root->left) l = mx_sum(root->left);if(root->right) r = mx_sum(root->right);
       if(root->left==NULL &&root->right==NULL) return root->val;
       return max({l+r+root->val,(int)maxPathSum(root->left),(int)maxPathSum(root->right)});
    }
};
