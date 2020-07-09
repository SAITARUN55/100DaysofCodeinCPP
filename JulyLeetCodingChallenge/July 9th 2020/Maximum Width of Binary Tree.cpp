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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int result = 1;
        queue<pair<TreeNode*, int>> Q;
        Q.push({root, 0});
        while(!Q.empty()){
            int count = Q.size();
            int start = Q.front().second;
            int end = Q.back().second;
            result = max(result, end-start+1);
            for(int i = 0; i < count; ++i){
                pair<TreeNode*, int> p = Q.front();
                int idx = p.second - start;
                Q.pop();
                if(p.first->left) Q.push({p.first->left, 2*idx+1});
                if(p.first->right) Q.push({p.first->right, 2*idx+2});
            }
            
        }
        return result;
    }
};
