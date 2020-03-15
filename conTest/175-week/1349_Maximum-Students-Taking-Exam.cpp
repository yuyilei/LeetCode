/*
Given a m * n matrix seats  that represent seats distributions in a classroom. If a seat is broken, it is denoted by '#' character otherwise it is denoted by a '.' character.

Students can see the answers of those sitting next to the left, right, upper left and upper right, but he cannot see the answers of the student sitting directly in front or behind him. Return the maximum number of students that can take the exam together without any cheating being possible..

Students must be placed in seats in good condition.

 

Example 1:


Input: seats = [["#",".","#","#",".","#"],
                [".","#","#","#","#","."],
                ["#",".","#","#",".","#"]]
Output: 4
Explanation: Teacher can place 4 students in available seats so they don't cheat on the exam.
Example 2:

Input: seats = [[".","#"],
                ["#","#"],
                ["#","."],
                ["#","#"],
                [".","#"]]
Output: 3
Explanation: Place all students in available seats.

Example 3:

Input: seats = [["#",".",".",".","#"],
                [".","#",".","#","."],
                [".",".","#",".","."],
                [".","#",".","#","."],
                ["#",".",".",".","#"]]
Output: 10
Explanation: Place students in available seats in column 1, 3 and 5.
 

Constraints:

seats contains only characters '.' and'#'.
m == seats.length
n == seats[i].length
1 <= m <= 8
1 <= n <= 8

*/



/*
 * 动态规划
 */
class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size();
        int n = seats[0].size();
        vector<vector<int>> dp (m+1, vector<int> (1<<n, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < (1<<n); j++) {
                bitset<8> bs (j);        // n 个比特位表示这一行的状态, 1表示坐了人，0表示没坐人
                // 检查这一行
                bool ok = true;
                for (int k = 0; k < n; k++) {
                    if (bs[k] && seats[i-1][k] == '#') {   // 坐在了坏椅子上
                        ok = false;
                        break;
                    }
                    if ((k > 0 && bs[k] && bs[k-1]) ||
                        (k < n-1 && bs[k] && bs[k+1])) {   // 坐在了相邻的位置上
                        ok = false;
                        break;
                    }
                }
                if (!ok) {          // 这一行不能组成有效的位置，继续检查下一种状态
                    dp[i][j] = -1;
                    continue;
                }
                // 检查上一行的所有状态
                for (int last = 0; last < (1<<n); last++) {
                    if (dp[i-1][last] == -1) {        // 检查上一行是否被放弃
                        continue;
                    }
                    bitset<8> ls (last);
                    ok = true;
                    for (int k = 0; k < n; k++) {
                        if (k > 0 && bs[k] && ls[k-1]) {   // 左上方有座位，不行
                            ok = false;
                            break;
                        }
                        if (k < n-1 && bs[k] && ls[k+1]) {  // 右上方有座位，不行
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {            // 上一行检查都满足条件
                        // bs.count() 表示本行人数
                        dp[i][j] = max(dp[i][j], dp[i-1][last]+(int)bs.count());
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < (1<<n); i++) {
            if (dp[m][i] != -1)
                res = max(res, dp[m][i]);
        }
        return res;
    }
};
