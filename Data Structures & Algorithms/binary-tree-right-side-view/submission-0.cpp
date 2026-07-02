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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(!root)return ans;
        map<int,int>mpp;
        queue<pair<int,TreeNode*>>q;
        q.push({0,root});
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto [level,node]=q.front();
                q.pop();
                mpp[level]=node->val;
                if(node->left!=NULL)q.push({level+1,node->left});
                if(node->right!=NULL)q.push({level+1,node->right});
            }
        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
        
    }
};
