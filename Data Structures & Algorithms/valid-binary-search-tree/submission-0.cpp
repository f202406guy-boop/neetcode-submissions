/**
 * Definition for a binary tree n.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define ll long long 
class Solution {
public:
    bool chk(TreeNode* n,ll l, ll r )
    {
        if(!n) return true;
        if (!(l < n->val && n->val < r)) {
            return false;}
        return chk(n->left,l,n->val)&&chk(n->right,n->val,r);
    }
    bool isValidBST(TreeNode* root) {
        return chk(root,LLONG_MIN,LLONG_MAX);
    }
};
