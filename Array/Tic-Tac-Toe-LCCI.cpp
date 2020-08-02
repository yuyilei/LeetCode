/*
Design an algorithm to figure out if someone has won a game of tic-tac-toe. Input is a string array of size N x N, including characters " ", "X" and "O", where " " represents a empty grid.

The rules of tic-tac-toe are as follows:

Players place characters into an empty grid(" ") in turn.
The first player always place character "O", and the second one place "X".
Players are only allowed to place characters in empty grid. Replacing a character is not allowed.
If there is any row, column or diagonal filled with N same characters, the game ends. The player who place the last charater wins.
When there is no empty grid, the game ends.
If the game ends, players cannot place any character further.
If there is any winner, return the character that the winner used. If there's a draw, return "Draw". If the game doesn't end and there is no winner, return "Pending".

Example 1:

Input:  board = ["O X"," XO","X O"]
Output:  "X"
Example 2:

Input:  board = ["OOX","XXO","OXO"]
Output:  "Draw"
Explanation:  no player wins and no empty grid left
Example 3:

Input:  board = ["OOX","XXO","OX "]
Output:  "Pending"
Explanation:  no player wins but there is still a empty grid
Note:

1 <= board.length == board[i].length <= 100
Input follows the rules.

*/

// 检查井字棋的赢家

// 手动检查每行、每列、和对角线
// 多次遍历
class Solution {
public:
    string tictactoe(vector<string>& board) {
        bool xWinner = isWinner(board, 'X');
        if (xWinner)
            return "X";
        bool oWinner = isWinner(board, 'O');
        if (oWinner)
            return "O";
        int len = board.size();
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (board[i][j] == ' ')
                    return "Pending";
            }
        }
        return "Draw";
    }
private:
    bool isWinner(vector<string> &board, char c) {
        int len = board.size();
        bool isWinner = true;
        for (int i = 0; i < len; i++) {
            if (board[i][i] != c) {
                isWinner = false;
                break;
            }
        }
        if (isWinner) return true;
        isWinner = true;
        for (int i = 0; i < len; i++) {
            if (board[i][len-1-i] != c) {
                isWinner = false;
                break;
            }
        }
        if (isWinner) return true;
        for (int i = 0; i < len; i++) {
            isWinner = true;
            for (int j = 0; j < len; j++) {
                if (board[i][j] != c) {
                    isWinner = false;
                    break;
                }
            }
            if (isWinner) return true;
        }
        for (int i = 0; i < len; i++) {
            isWinner = true;
            for (int j = 0; j < len; j++) {
                if (board[j][i] != c) {
                    isWinner = false;
                    break;
                }
            }
            if (isWinner) return true;
        }
        return false;
    }
};


// 一次遍历
class Solution {
public:
    string tictactoe(vector<string>& board) {
        int len = board.size();
        bool xDia = false, xiDia = false;
        bool oDia = false, oiDia = false;
        bool is_full = true;
        for (int i = 0; i < len; i++) {
            bool xRow = false, xCol = false;
            bool oRow = false, oCol = false;
            for (int j = 0; j < len; j++) {
                if (is_full && board[i][j] == ' ')
                    is_full = false;
                if (!xRow) xRow = board[i][j] != 'X';
                if (!oRow) oRow = board[i][j] != 'O';
                if (!xCol) xCol = board[j][i] != 'X';
                if (!oCol) oCol = board[j][i] != 'O';
            }
            if (!xRow || !xCol) return "X";
            if (!oRow || !oCol) return "O";
            if (!xDia) xDia = board[i][i] != 'X';
            if (!oDia) oDia = board[i][i] != 'O';
            if (!xiDia) xiDia = board[i][len-1-i] != 'X';
            if (!oiDia) oiDia = board[i][len-1-i] != 'O';
        }
        if (!xDia || !xiDia) return "X";
        if (!oDia || !oiDia) return "O";
        if (is_full)
            return "Draw";
        return "Pending";
    }
};
