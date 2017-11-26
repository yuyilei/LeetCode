// subpalind[i][j] == 1 表示 i到j的字符是回文的， res[i]表示，i到n-1中最小的分割数  
class Solution {
public:
    int minCut(string s) {
        int len = s.length() ; 
        vector<vector<int>> subpalind (len,vector<int>(len,0)) ; 
        vector<int> res (len+1,-1) ; 
        for ( int i = 0 ; i < len ; i++ )
            subpalind[i][i] = 1 ;                      // 一个字符一定是回文的
        for ( int i = len-1 ; i >= 0 ; i-- ){
            res[i] = res[i+1]+1 ;                      // 初始化res[i] = res[i+1]+1 (多一个字符就多一次分割) 这是最大情况
            for ( int j = i+1 ; j < len ; j++ ){
                if ( s[i] == s[j] ){                   
                    if ( j == i+1 || subpalind[i+1][j-1] ){   // 一个新的回文字符串出现，res[i]就有可能变小，因为里面可能出现更长的回文字符串可以减小分割 
                        subpalind[i][j] = 1 ; 
                        res[i] = min(res[i],res[j+1]+1) ;     // res[j+1] 表示 j之后的回文字符串， +1 表示新出现的回文字符串 
                    }
                }
            }
        }
        return res[0] ; 
    }
};

// res[i] 表示 0 到 第 i 字符 的分割数。 
class Solution {
public:
    int minCut(string s) {
        int n = s.length() ; 
        vector<int> res(n+1,0) ; 
        for ( int i = 0 ; i <= n ; i++ ) 
            res[i] = i - 1 ;                     // 同理先初始化，此时是最大分割数，把每个字符都分割
        for ( int i = 0 ; i < n ; i++ ){         // 以i为中心， j为两边字符的长度，进行查找 ，分两种情况
            for ( int j = 0 ; i-j-1 >= 0 && i+j < n ; j++ ){    
                if ( s[i-j-1] != s[i+j] ) 
                    break ; 
                res[i+j+1] = min(res[i+j+1],res[i-j-1]+1) ;   // 字符串中出现新的回文字符串，就要跟新分割数，因为回文字符串增长可能会减小分割数 
            } 
            for ( int j = 0 ; i-j >= 0 && i+j < n ; j++ ){
                if ( s[i-j] != s[i+j] ) 
                    break ; 
                res[i+j+1] = min(res[i+j+1],res[i-j]+1) ; 
            }
        }
        return res[n] ; 
    }
};