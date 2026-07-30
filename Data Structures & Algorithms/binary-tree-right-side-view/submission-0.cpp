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
    vector<int> rightSideView(TreeNode* root) {
       queue<TreeNode*> q;
       q.push(root);
       vector<vector<int>> b;
       while(!q.empty()) 
       {
        vector<int> v;
        int size =q.size();
       
        for(int i=0;i<size;i++){
        TreeNode* t=q.front();
        q.pop();
        if(t)
        {
            q.push(t->left);
           q.push(t->right);
           v.push_back(t->val);
        }
        }
        if(!v.empty()){b.push_back(v);}
       }vector<int>ans;
       for(auto i:b) ans.push_back(i[i.size()-1]);
       return ans;
       
         

       
    }
};
