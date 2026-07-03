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
    TreeNode* build(vector<int>& preorder,int preSt, int preEnd, vector<int>& inorder, int inSt, int inEnd, map<int,int>&mpp){
        if(preSt>preEnd || inSt>inEnd) return NULL;
        TreeNode *root= new TreeNode(preorder[preSt]);
        int inroot=mpp[root->val];
        int left= inroot-inSt;
        root->left=build(preorder, preSt+1, preSt+left, inorder, inSt, inroot-1, mpp);
        root->right=build(preorder, preSt+left+1, preEnd, inorder, inroot+1, inEnd, mpp);
        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0 || inorder.size()==0) return NULL;
        map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mpp);
        
    }
};
