/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if ( !root ) return ; 
        queue<TreeLinkNode *> q ; 
        q.push(root) ; 
        while ( !q.empty() ){
            int len = q.size() ; 
            TreeLinkNode *pre = NULL, *now = NULL ; 
            for ( int i = 0 ; i < len ; i++ ) {
                now = q.front() ;
                q.pop() ; 
                if ( now->left ) q.push(now->left) ; 
                if ( now->right ) q.push(now->right) ; 
                if ( pre ) pre->next = now ;
                pre = now ; 
            } 
            now->next = NULL ; 
        } 
    }
};