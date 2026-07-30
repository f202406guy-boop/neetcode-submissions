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
    vector<int> preorderTraversal(TreeNode* root) {
         vector<int> v;
        if(root==NULL) return v;
        v.push_back(root->val);
        vector<int> v1=preorderTraversal(root->left);
        v.insert(v.end(),v1.begin(),v1.end());
        vector<int> v2=preorderTraversal(root->right);
        v.insert(v.end(),v2.begin(),v2.end());
        
        return v;
    }
};