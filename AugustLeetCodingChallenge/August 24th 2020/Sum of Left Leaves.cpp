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
    void solve(TreeNode* root,int &ans,bool flag)
    {
        if(!root) return ;
        if(!root->left && !root->right)
        {
            if(flag==1) ans+=root->val;
            //flag==1 when we are on left child of a node
             return;
        }
    
        solve(root->left,ans,1);
        solve(root->right,ans,0);
        return;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        bool flag=0;
        int ans=0;
        solve(root,ans,flag);
        return ans;
    }
};
