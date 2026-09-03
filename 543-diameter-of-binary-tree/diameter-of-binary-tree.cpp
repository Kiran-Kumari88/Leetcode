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
    int height(TreeNode* root){
        if(root==NULL) return 0;

        int leftht=height(root->left);
        int rightht=height(root->right);

        return max(leftht,rightht)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;

        int leftDia=diameterOfBinaryTree(root->left);// root ke left m h diameter
        int rightDia=diameterOfBinaryTree(root->right);// root ke right se h 
        int currDia=height(root->left)+height(root->right);// dia=leftheight+rightheight
        
        return max(currDia,max(leftDia,rightDia));
    }
};