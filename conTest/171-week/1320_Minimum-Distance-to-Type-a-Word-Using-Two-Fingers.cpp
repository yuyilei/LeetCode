/*
You have a keyboard layout as shown above in the XY plane, where each English uppercase letter is located at some coordinate, for example, the letter A is located at coordinate (0,0), the letter B is located at coordinate (0,1), the letter P is located at coordinate (2,3) and the letter Z is located at coordinate (4,1).

Given the string word, return the minimum total distance to type such string using only two fingers. The distance between coordinates (x1,y1) and (x2,y2) is |x1 - x2| + |y1 - y2|. 

Note that the initial positions of your two fingers are considered free so don't count towards your total distance, also your two fingers do not have to start at the first letter or the first two letters.

 

Example 1:

Input: word = "CAKE"
Output: 3
Explanation:
Using two fingers, one optimal way to type "CAKE" is:
Finger 1 on letter 'C' -> cost = 0
Finger 1 on letter 'A' -> cost = Distance from letter 'C' to letter 'A' = 2
Finger 2 on letter 'K' -> cost = 0
Finger 2 on letter 'E' -> cost = Distance from letter 'K' to letter 'E' = 1
Total distance = 3
Example 2:

Input: word = "HAPPY"
Output: 6
Explanation:
Using two fingers, one optimal way to type "HAPPY" is:
Finger 1 on letter 'H' -> cost = 0
Finger 1 on letter 'A' -> cost = Distance from letter 'H' to letter 'A' = 2
Finger 2 on letter 'P' -> cost = 0
Finger 2 on letter 'P' -> cost = Distance from letter 'P' to letter 'P' = 0
Finger 1 on letter 'Y' -> cost = Distance from letter 'A' to letter 'Y' = 4
Total distance = 6
Example 3:

Input: word = "NEW"
Output: 3
Example 4:

Input: word = "YEAR"
Output: 7
 

Constraints:

2 <= word.length <= 300
Each word[i] is an English uppercase letter.


*/

/*
 *  dp[i][l][r] 表示在输入了字符串 word 的第 i 个字母后，左手的位置为 l，右手的位置为 r
 *  对于dp[i][l][r]，上一个字母 pre = word[i-1]，dp[i][l][r] 可由 dp[i-1][pre][r] 移动左手指得到，或者由dp[i-1][l][pre]移动右手指得到
 */
class Solution {
public:
    int minimumDistance(string word) {
        if (word.size() <= 2)
            return 0;
        int n = word.size();
        int res = INT_MAX;
        vector<vector<vector<int>>> dp (n+1, vector<vector<int>> (26, vector<int> (26, INT_MAX)));
        for (int l = 0; l < 26; l++) {
            for (int r = 0; r < 26; r++) {
                dp[0][l][r] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            int pre = word[i-1] - 'A';
            for (int l = 0; l < 26; l++) {
                for (int r = 0; r < 26; r++) {
                    // 上一个状态存在
                    if (dp[i-1][l][r] != INT_MAX) {
                        dp[i][pre][r] = min(dp[i][pre][r], dp[i-1][l][r]+distance(pre, l));
                        dp[i][l][pre] = min(dp[i][l][pre], dp[i-1][l][r]+distance(pre, r));
                    }
                    if (i == n) {
                        res = min(res, dp[i][pre][r]);
                        res = min(res, dp[i][l][pre]);
                    }
                }
            }
        }
        return res;
    }
private:
    int distance(int ta, int tb) {
        int x = abs(ta/6 - tb/6);
        int y = abs(ta%6 - tb%6);
        return x+y;
    }
};
