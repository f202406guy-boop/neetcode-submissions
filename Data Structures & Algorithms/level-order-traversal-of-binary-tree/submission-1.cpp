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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {vector<int> sub;
            int size=q.size();
            for(int i=0;i<size;i++){
            TreeNode* t=q.front();
            q.pop();
           
           if(t){
            sub.push_back(t->val);
            q.push(t->left);
            q.push(t->right);
             
           }
            }
            if(!sub.empty()){ans.push_back(sub);}
        }
        return ans;

    }
};
