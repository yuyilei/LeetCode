/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream s;
        serialize(root,s); 
        return s.str();
    }

    void serialize(TreeNode* root, stringstream &s) {
        if ( !root ) {
            s << "# ";
            return;  
        }
        s << root->val << " ";
        serialize(root->left,s);
        serialize(root->right,s); 
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream s(data);
        return deserialize(s); 
    }
    
    TreeNode* deserialize(stringstream &s) {
        string val; 
        s >> val;
        if ( val == "#" ) {
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(s);
        root->right = deserialize(s);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));