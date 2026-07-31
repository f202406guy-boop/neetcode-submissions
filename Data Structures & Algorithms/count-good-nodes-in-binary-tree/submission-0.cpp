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
    void dp(TreeNode* n , int mx,int &ans) 
        {
           if(!n) return ;
           if(n->val>=mx){ mx=n->val;ans++;}
           dp (n->left,mx,ans);
           dp(n->right,mx,ans);
        }
    
    int goodNodes(TreeNode* root) {
        int x=0;
        dp(root,root->val,x);
        return x;
    }
};
