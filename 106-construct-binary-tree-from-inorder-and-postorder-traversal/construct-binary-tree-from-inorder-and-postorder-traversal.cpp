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
    int search(vector<int>& inorder, int start, int end, int val) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == val)
                return i;
        }
        return -1;
    }

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int& postIdx,int start, int end) {
        if (start > end)
            return NULL;

        TreeNode* root = new TreeNode(postorder[postIdx]);
        int inIdx = search(inorder, start, end, postorder[postIdx]);
        postIdx--;


        root->right = helper(inorder, postorder, postIdx, inIdx + 1, end);
        root->left = helper(inorder, postorder, postIdx, start, inIdx - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postIdx = n - 1;
        return helper(inorder, postorder, postIdx, 0, n - 1);
    }
};