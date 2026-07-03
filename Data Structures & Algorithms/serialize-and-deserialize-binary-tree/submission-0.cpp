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

class Codec {
private:
    void shelper(TreeNode* node, stringstream& ss){
        if(!node){
            ss<<"#"<<" ";
            return;
        }
        ss<<node->val<<" ";
        shelper(node->left,ss);
        shelper(node->right,ss);

    }
    TreeNode* dhelper(stringstream & ss){
        string val;
        ss>>val;
        if(val=="#")return nullptr;
        TreeNode* root= new TreeNode(stoi(val));
        root->left=dhelper(ss);
        root->right=dhelper(ss);
        return root;

    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        shelper(root,ss);
        return ss.str();
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return dhelper(ss);
    }
};
