/**
 * Definition for a binary tree Info.
 * struct TreeInfo {
 *     int val;
 *     TreeInfo *left;
 *     TreeInfo *right;
 *     TreeInfo() : val(0), left(nullptr), right(nullptr) {}
 *     TreeInfo(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeInfo(int x, TreeInfo *left, TreeInfo *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;

    class Info {
    public:
        bool isBST;
        int minValue;   // minimum value in this subtree
        int maxValue;   // maximum value in this subtree
        int sum;

        Info(bool isBST, int minValue, int maxValue, int sum) {
            this->isBST = isBST;
            this->minValue = minValue;
            this->maxValue = maxValue;
            this->sum = sum;
        }
    };

    Info solve(TreeNode* root) {
        if(root==NULL) {
            return Info(true,INT_MAX,INT_MIN,0);
        }
        Info left=solve(root->left);
        Info right=solve(root->right);

        if(left.isBST && right.isBST && root->val>left.maxValue && root->val<right.minValue ){ //  bst
            int currSum=left.sum+right.sum+root->val;
            ans=max(ans,currSum);

            int currMin=min(left.minValue,root->val);
            int currMax=max(right.maxValue,root->val);

            return Info(true,currMin,currMax,currSum);
        }

        // if not a bst
        return Info(false, INT_MIN, INT_MAX, 0);
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};