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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode *left = root, *right = root;
        int h_l = 0, h_r = 0;
        while(left){
            h_l++;
            left = left->left;
        }
        while(right){
            h_r++;
            right = right->right;
        }
        if(h_l == h_r) return (1<<h_l) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
