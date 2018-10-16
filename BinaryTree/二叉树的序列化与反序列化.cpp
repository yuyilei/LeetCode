/*
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 根据先序遍历序列化，再根据先序遍历反序列化
// 每次从streamstring读出的string是被 空格 分割开
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        serialize(root,ss);
        return ss.str();
    }

    void serialize(TreeNode* root, stringstream &ss) {
        if ( !root ) {
            ss << "# ";
            return;
        }
        ss << root->val << " ";
        serialize(root->left,ss);
        serialize(root->right,ss);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        TreeNode* root = deserialize(ss);
        return root;
    }

    TreeNode* deserialize(stringstream &ss) {
        string val;
        ss >> val;
		// 遇到空格就停止读出
        if ( val == "#" )
            return NULL;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(ss);
        root->right = deserialize(ss);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
