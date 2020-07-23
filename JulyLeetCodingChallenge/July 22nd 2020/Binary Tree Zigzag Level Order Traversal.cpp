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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        // exiting if the tree is empty
        if (!root) return res;
        // some good old initialisation
        queue<TreeNode*> layer;
        layer.push(root);
        int len;
        bool flip = false;
        TreeNode *currNode;
        // core BFS loop, layer by layer
        while (layer.size()) {
            len = layer.size();
            vector<int> tmp(len);
            for (int i = 0; i < len; i++) {
                currNode = layer.front();
                tmp[i] = currNode->val;
                if (currNode->left) layer.push(currNode->left);
                if (currNode->right) layer.push(currNode->right);
                layer.pop();
            }
            if (flip) reverse(begin(tmp), end(tmp));
            flip = !flip;
            res.push_back(tmp);
        }
        return res;
    }
};
