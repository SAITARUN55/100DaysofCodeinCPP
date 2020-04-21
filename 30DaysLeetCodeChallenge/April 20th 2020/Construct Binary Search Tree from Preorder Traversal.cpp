/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return bstFromPreorderHelper(preorder, index, INT_MIN, INT_MAX);
    }
    
    TreeNode* bstFromPreorderHelper(vector<int>& preorder, int& index, int minV, int maxV) {
        if(index >= preorder.size()) return NULL;
        if(preorder[index] < minV || preorder[index] > maxV) return NULL;
        TreeNode* root = new TreeNode(preorder[index++]);
        root-> left = bstFromPreorderHelper(preorder, index, minV, root-> val);
        root-> right = bstFromPreorderHelper(preorder, index, root-> val, maxV);
        return root;
    }
};
