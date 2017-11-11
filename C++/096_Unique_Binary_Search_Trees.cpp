// 寻找二叉搜索树，已知二叉搜素树的先序遍历是有序的（升序的）
// 给定一个序列1.....n，为了构造所有二叉树，使用1......n中的每一个数i作为根节点，自然1......(i-1)必然位于树的左子树中，(i+1).....n位于树的右子树中。
// res[i]是以i 作为跟节点的二叉搜索树的个数
// 非递归： 
class Solution {
public:
    int numTrees(int n) { 
        if ( n==1 || n==0 ) return 1 ;
        int res[n+1] = {1,1} ;
        for ( int i = 2 ; i <= n ; i++ ){
            for ( int j = 0 ; j < i ; j++ ) 
                res[i] += res[j]*res[i-j-1] ; 
        }
        return res[n] ; 
    }
};

// 递归：会超时
// 之前说过递归可以用二重循环加二维数组代替 
class Solution {
public:
    int numTrees(int n) {
        if ( n==0 || n==1 ) return 1 ; 
        int res = 0 ; 
        for ( int i = 0 ; i < n ; i++ )
            res += numTrees(i)*numTrees(n-i-1) ; 
        return res ; 
    }
};