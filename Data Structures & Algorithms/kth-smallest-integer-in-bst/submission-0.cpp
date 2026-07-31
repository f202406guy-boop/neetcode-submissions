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
    void vec(vector<int> &v,TreeNode* t )
    {
       if(t==NULL) return;
       v.push_back(t->val);
       vec(v,t->right);
       vec(v,t->left);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        vec(v,root);
        sort(v.begin(),v.end());
        for(auto i:v) cout<<i<<" ";
        return v[k-1];


    }
};
