/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int search(vector<int>& inorder, int start, int end, int key) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == key) {
                return i;
            }
        }
        return -1;
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int &i,int start, int end) {
        if (start > end) {
            return NULL;
        }

        TreeNode* node = new TreeNode(preorder[i]);
        int inIdx = search(inorder, start, end, preorder[i]);
        i++;

        node->left = helper(preorder, inorder, i, start, inIdx - 1);
        node->right = helper(preorder, inorder, i, inIdx + 1, end);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        int n = inorder.size();
        return helper(preorder, inorder, idx, 0, n - 1);
    }
};