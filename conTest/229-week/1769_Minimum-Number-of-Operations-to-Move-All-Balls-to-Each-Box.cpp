/*
You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.

In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.

Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.

Each answer[i] is calculated considering the initial state of the boxes.

 

Example 1:

Input: boxes = "110"
Output: [1,1,3]
Explanation: The answer for each box is as follows:
1) First box: you will have to move one ball from the second box to the first box in one operation.
2) Second box: you will have to move one ball from the first box to the second box in one operation.
3) Third box: you will have to move one ball from the first box to the third box in two operations, and move one ball from the second box to the third box in one operation.
Example 2:

Input: boxes = "001011"
Output: [11,8,5,4,3,4]
 

Constraints:

n == boxes.length
1 <= n <= 2000
boxes[i] is either '0' or '1'.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int len = boxes.size();
        vector<int> res (len, 0);
        for (int i = 0; i < len; i++) {
            for (int j = i+1; j < len; j++) {
                int dis = j - i;
                if (boxes[i] == '1')
                    res[j] += dis;
                if (boxes[j] == '1')
                    res[i] += dis;
            }
        }
        return res;
    }
};


// dp
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int len = boxes.size();
        vector<int> dp (len, 0);
        int left = 0, right = 0;   // left表示当前位置左边的1的个数，right表示当前几其右边的0的个数
        for (int i = 0; i < len; i++) {   // 计算 dp[0]
            if (boxes[i] == '1') {
                dp[0] += i;
                right++;
            }
        }
        for (int i = 1; i < len; i++) {
            if (boxes[i-1] == '1') {
                left++;
                right--;
            }
            dp[i] = dp[i-1] + left - right;
        }
        return dp;
    }
};
