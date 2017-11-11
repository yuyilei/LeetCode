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
    vector<TreeNode*> getres(int s, int e ){ 
        vector<TreeNode*> res ; 
        if ( s > e ) {
            res.push_back(NULL) ;    // 没有节点，返回null 
            return res ; 
        }
        for ( int i = s ; i <= e ; i++ ){
            vector<TreeNode*> left = getres(s,i-1) ; // 左子树的列表
            vector<TreeNode*> right = getres(i+1,e) ;  // 右子树的列表 
            for ( int j = 0 ; j < left.size() ; j++ ){
                for ( int k = 0 ; k < right.size() ; k++ ){
                    TreeNode *root = new TreeNode(i) ;  // 当前节点为根节点 
                    root->left = left[j] ;              // 遍历每一个左子树
                    root->right = right[k] ;            // 遍历每一个右子树  
                    res.push_back(root) ; 
                }
            }
        }
        return res ; 
    }
    vector<TreeNode*> generateTrees(int n) {
        if ( !n ) return {} ;
        return getres(1,n) ; 
    } 
};
// 递归算法，原先的想法和上面的差不多，但是getres函数是返回void，但是没办法获得左子树和右子树的列表