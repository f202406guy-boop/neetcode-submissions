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
    unordered_map<TreeNode*, int> mem;

    int dp(TreeNode* t, bool pos)
    {   
        if(t==NULL) return 0;
        if(pos==true && mem.count(t)) return mem[t];
        
        if(pos==false) return dp(t->left,true)+dp(t->right,true);
        return mem[t]=max(dp(t->left,true)+dp(t->right,true),t->val+dp(t->left,false)+dp(t->right,false));
    }

    int rob(TreeNode* root) {
        return dp(root,true);
    }
};
