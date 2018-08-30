/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
利用先序遍历

使用stringstream
1.使用stringstream类前，先在头文件中添加 include<sstream>
2.stringstream对象的使用和cout对象的使用相同
3.使用stringstream类前，先创建一个对象，并通过运算符“<<”将数据传给该对象
4.使用时调用 [对象名].str()就行了

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
        TreeNode *root = new TreeNode(stoi(val)); 
        root->left = deserialize(s);
        root->right = deserialize(s);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));