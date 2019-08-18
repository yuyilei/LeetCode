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
        if (word.empty())
            return true;
        if (board.empty() || board[0].empty())
            return false;
        int row = board.size();
        int col = board[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (search(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
private:
    bool search(vector<vector<char>> &matrix, int x, int y, string word, int index) {
        int row = matrix.size();
        int col = matrix[0].size();
        if (word.size() == index)
            return true;
        if (x < 0 || x >= row || y < 0 || y >= col || matrix[x][y] == '#' || matrix[x][y] != word[index])
            return false;
        char tmp = matrix[x][y];
        matrix[x][y] = '#';
        bool res = search(matrix, x+1, y, word, index+1) ||
                   search(matrix, x-1, y, word, index+1) ||
                   search(matrix, x, y+1, word, index+1) ||
                   search(matrix, x, y-1, word, index+1);
        matrix[x][y] = tmp;
        return res;
    }
};
