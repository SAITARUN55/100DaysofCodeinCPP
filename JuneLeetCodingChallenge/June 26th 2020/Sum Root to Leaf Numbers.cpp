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
    int current = 0;
public:
    int sumNumbers(TreeNode*& node) {
        if (!node) return 0;
        current = current * 10 + node->val;
        const int res = node->left || node->right ? sumNumbers(node->left) + sumNumbers(node->right) : current;
        current /= 10;
        return res;
    }
};
