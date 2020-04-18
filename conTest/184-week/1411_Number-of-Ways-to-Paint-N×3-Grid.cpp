/*
You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colours: Red, Yellow or Green while making sure that no two adjacent cells have the same colour (i.e no two cells that share vertical or horizontal sides have the same colour).

You are given n the number of rows of the grid.

Return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 10^9 + 7.

 

Example 1:

Input: n = 1
Output: 12
Explanation: There are 12 possible way to paint the grid as shown:

Example 2:

Input: n = 2
Output: 54
Example 3:

Input: n = 3
Output: 246
Example 4:

Input: n = 7
Output: 106494
Example 5:

Input: n = 5000
Output: 30228214
 

Constraints:

n == grid.length
grid[i].length == 3
1 <= n <= 5000

*/

// 每一行有两种情况： abc和aba
// abc的下一行有4中情况：bab,bcb,bca,cab，分别是2个aba和2个abc
// aba的下一行有5中情况：bab,bcb,cac,bac,cab，分别是3个aba和2个abc

class Solution {
public:
    int numOfWays(int n) {
        const int maxx = 1000000007;
        long aba = 6;
        long abc = 6;
        for (int i = 1; i < n; i++) {
            long tmp = aba;
            aba = aba*3+abc*2;
            abc = abc*2+tmp*2;
            if (aba > maxx)
                aba %= maxx;
            if (abc > maxx)
                abc %= maxx;
        }
        return (abc+aba) % maxx;
    }
};
