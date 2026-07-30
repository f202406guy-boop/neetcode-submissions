class Solution {
private:
    int height(TreeNode* node) {
        if (node == NULL) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        
        int x1=diameterOfBinaryTree(root->left);
        int x2=diameterOfBinaryTree(root->right);
        
        int c = height(root->left) + height(root->right);
        return max(c, max(x1, x2));
    }
};
