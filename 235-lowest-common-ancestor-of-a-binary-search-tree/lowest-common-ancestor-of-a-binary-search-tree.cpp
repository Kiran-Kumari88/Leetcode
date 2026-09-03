/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;

        if(root->val < p->val && root->val < q->val){ // both lies on right side
            return lowestCommonAncestor(root->right,p,q); // go on right
        }

        if(root->val > p->val && root->val > q->val){ // both lies on left side
            return lowestCommonAncestor(root->left,p,q); // go on left
        }
        return root; // both on different sides   
    }
};