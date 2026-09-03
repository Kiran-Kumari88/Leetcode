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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes; //vertical,level -> multiset
        queue<pair<TreeNode*,pair<int,int>>>q;  // TreeNode* node,int vertical,int level

        q.push({root,{0,0}});

        while(!q.empty()){
            auto p=q.front();
            TreeNode* node= p.first;
            int vertical=p.second.first;
            int level=p.second.second;
            q.pop();

            nodes[vertical][level].insert(node->val); // inserting node value at the coordinate
            if(node->left!=NULL){
                q.push({node->left,{vertical-1,level+1}}); // vertical-1,level+1 for left
            } 
            if(node->right!=NULL){
                q.push({node->right,{vertical+1,level+1}}); //vertical+1,level+1 for right
            }  
        }
        vector<vector<int>>ans;
        for(auto p:nodes){
            vector<int>col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};