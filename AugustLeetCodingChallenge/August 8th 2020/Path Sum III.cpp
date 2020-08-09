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
    int checkSum(TreeNode *root,int sum){
	if(root == NULL) return 0;
	int left = checkSum(root->left,sum - root->val);
	int right = checkSum(root->right,sum - root->val);
	    if(root->val == sum)
		   return 1+left+right;
	    else
		   return left+right;
 }
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
		  return 0;
	    return checkSum(root,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
    }
};
