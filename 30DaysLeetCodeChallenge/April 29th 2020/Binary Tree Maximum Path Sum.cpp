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
    int maxPathSum(TreeNode* root) {
         int res = INT_MIN;
        helper(root, res);
        return res;
    }
    int helper(TreeNode* node, int &res) {
        if (node == NULL) {
            return 0;
        }
        int left = max(helper(node->left, res), 0); // if left is less than 0, ignore it
        int right = max(helper(node->right, res), 0); // same as above
        int tree = left + right + node->val; // check the sum of node + left + right
        res = max(res, tree); // compare with res
        return node->val + max(left, right); // output the max of this branch
    }
};
