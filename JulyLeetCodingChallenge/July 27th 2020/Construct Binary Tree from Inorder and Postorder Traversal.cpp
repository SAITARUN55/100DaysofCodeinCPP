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
    TreeNode* construct(int sti,int eni,int stp,int enp,vector<int>& inorder, vector<int>& postorder){
        int rt=postorder[enp];
        TreeNode* root=new TreeNode(rt);
        for(int i=sti;i<=eni;i++){
            if(inorder[i]==rt){
                if(i==sti) root->left=nullptr;
                else root->left=construct(sti,i-1,stp,stp+(i-1-sti),inorder,postorder);
                if(i==eni) root->right=nullptr;
                else root->right=construct(i+1,eni,enp-1-(eni-i-1),enp-1,inorder,postorder);
            }
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        if(n==0) return nullptr;
        return construct(0,n-1,0,n-1,inorder,postorder);
    }
};
