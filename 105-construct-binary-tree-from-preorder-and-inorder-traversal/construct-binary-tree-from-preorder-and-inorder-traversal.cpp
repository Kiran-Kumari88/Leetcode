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
    int search(vector<int>& inorder,int start,int end,int val){
        for(int i=start;i<=end;i++){
            if(inorder[i]==val){
                return i;
            }
        }
        return -1;
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int &preIdx ,int start,int end){
        if(start>end){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[preIdx]);
        int inIdx=search(inorder,start,end,preorder[preIdx]);
        preIdx++;

        root->left=helper(preorder,inorder,preIdx,start,inIdx-1);
        root->right=helper(preorder,inorder,preIdx,inIdx+1,end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx=0;
        int n=inorder.size();
        return helper(preorder,inorder,preIdx,0,n-1);     
    }
};