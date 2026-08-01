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
    int deleted(TreeNode* &t,int x){
        int cnt=0;
        if(t==NULL) return 0;
        cnt+=deleted(t->left,x);cnt+=deleted(t->right,x);
        if(t->right==NULL && t->left==NULL&&t->val==x) {delete t;t=NULL; cnt++;return cnt;}
        else if(t->right==NULL && t->left==NULL){ return cnt;}
        else { return cnt; }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        deleted(root,target);
        return root;
    }
};
