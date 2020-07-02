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
    // Dfs will have the current node, the current level and the current state of ans array
    void dfs(TreeNode* root,int level,vector<vector<int>>& ans){
        if(!root) return; // If the node is NULL return
        if(level == ans.size()) ans.push_back({});  // if index = level of array is ot present, create empty array at that index
        ans[level].push_back(root->val);  // insert the value at index = level
        dfs(root->left,level+1,ans);  // Perform dfs on left sub tree increase level by 1
        dfs(root->right,level+1,ans);  // Perform dfs on right sub tree increase level by 1
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};  // Return if null
        vector<vector<int>>ans;  // We store our ans in this array
        dfs(root,0,ans);  // Perform dfs and fill ans array, initial level is 0
        reverse(ans.begin(),ans.end()); // reverse array
        return ans;
    }
};
