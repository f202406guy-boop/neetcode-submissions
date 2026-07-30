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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if((p==NULL &&q!=NULL)||(q==NULL&&p!=NULL)) return false;
    
        if(isSameTree(p->right,q->right)&&isSameTree(p->left,q->left)&&
        (p->val)==(q->val)) return true;
        else return false ;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL &&subRoot!=NULL) return false;
        if(subRoot==NULL)return true;
        bool b=isSameTree(root,subRoot);
        bool b1=isSubtree(root->right,subRoot);
        bool b2=isSubtree(root->left,subRoot);
        return b||b1||b2;

    }
};
