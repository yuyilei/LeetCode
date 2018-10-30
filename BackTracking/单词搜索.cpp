/*
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true.
给定 word = "SEE", 返回 true.
给定 word = "ABCB", 返回 false.
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if ( word.size() == 0 )
            return true;
        if ( board.empty() || board[0].empty() )
             return false;
        int len1 = board.size(), len2 = board[0].size();
        vector<vector<bool>> tmp (len1, vector<bool> (len2,false));
        for ( int i = 0 ; i < len1 ; i++ ) {
            for ( int j = 0 ; j < len2 ; j++ ) {
                if ( dfs(board,i,j,word,0,tmp) )
                    return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int x, int y, string word, int index, vector<vector<bool>>& tmp) {
        if ( index == word.size() )
            return true;
        if ( x < 0 || x >= board.size() || y < 0 || y >= board[0].size() )
            return false;
        if ( tmp[x][y] == true || board[x][y] != word[index] )
            return false;
        tmp[x][y] = true;
        bool res = false;
        res = res || dfs(board,x+1,y,word,index+1,tmp);
        res = res || dfs(board,x-1,y,word,index+1,tmp);
        res = res || dfs(board,x,y+1,word,index+1,tmp);
        res = res || dfs(board,x,y-1,word,index+1,tmp);
        tmp[x][y] = false;
        return res;
    }
};
