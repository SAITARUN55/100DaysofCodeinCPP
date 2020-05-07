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
    int findLevel(TreeNode* root, int v, int level) {
        if (nullptr == root) {
            return 0;
        }
        if (v == root->val) {
            return level;
        }
        int leftLevel = findLevel(root->left, v, level + 1);
        int rightLevel = findLevel(root->right, v, level + 1);
        
        return leftLevel + rightLevel;
    }
    
    bool isSibling(TreeNode* root, int x, int y) {
        if (nullptr == root) {
            return false;
        }
        if (nullptr == root->left) {
            return isSibling(root->right, x, y);
        }
        if (nullptr == root->right) {
            return isSibling(root->left, x, y);
        }
        if ((root->left->val == x || root->right->val == x) && 
            (root->left->val == y || root->right->val == y)) {
            return true;
        }
        return isSibling(root->left, x, y) || isSibling(root->right, x, y);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        int xLevel = findLevel(root, x, 0);
        int yLevel = findLevel(root, y, 0);
        
        return xLevel == yLevel && !isSibling(root, x, y);
    }
};
