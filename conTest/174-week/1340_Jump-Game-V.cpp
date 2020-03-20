/*
Given an array of integers arr and an integer d. In one step you can jump from index i to index:

i + x where: i + x < arr.length and 0 < x <= d.
i - x where: i - x >= 0 and 0 < x <= d.
In addition, you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] for all indices k between i and j (More formally min(i, j) < k < max(i, j)).

You can choose any index of the array and start jumping. Return the maximum number of indices you can visit.

Notice that you can not jump outside of the array at any time.



Example 1:


Input: arr = [6,4,14,6,8,13,9,7,10,6,12], d = 2
Output: 4
Explanation: You can start at index 10. You can jump 10 --> 8 --> 6 --> 7 as shown.
Note that if you start at index 6 you can only jump to index 7. You cannot jump to index 5 because 13 > 9. You cannot jump to index 4 because index 5 is between index 4 and 6 and 13 > 9.
Similarly You cannot jump from index 3 to index 2 or index 1.
Example 2:

Input: arr = [3,3,3,3,3], d = 3
Output: 1
Explanation: You can start at any index. You always cannot jump to any index.
Example 3:

Input: arr = [7,6,5,4,3,2,1], d = 1
Output: 7
Explanation: Start at index 0. You can visit all the indicies.
Example 4:

Input: arr = [7,1,7,1,7,1], d = 2
Output: 2
Example 5:

Input: arr = [66], d = 1
Output: 1


Constraints:

1 <= arr.length <= 1000
1 <= arr[i] <= 10^5
1 <= d <= arr.length
*/

/*
 * 思路： 一个点能访问此点左右两边d距离内，且高度小于此点的所有点
 * 动态规划，以高度对点进行升序排序，从低点开始，找出每个点能访问的左右边界left、right（d距离内，且高度小于此点），dp[i] = max(dp[left:right]) + 1 （加一表示能访问自己）
 */

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int len = arr.size();
        vector<vector<int>> idx;
        vector<int> dp (len, 1);
        int res = 0;
        for (int i = 0; i < len; i++) {
            idx.push_back({arr[i], i});
        }
        sort(idx.begin(), idx.end());
        for (int i = 0; i < len; i++) {
            int index = idx[i][1];
            int left = index-1;
            int right = index+1;
            while (index-left<=d) {
                if (left == -1 || arr[index] <= arr[left])
                    break;
                left--;
            }
            while (right-index<=d) {
                if (right == len || arr[index] <= arr[right])
                    break;
                right++;
            }
            left++;
            right--;
            int maxx = 0;
            for (int j = left; j <= right; j++) {
                if (j != index)
                    maxx = max(maxx, dp[j]);
            }
            dp[index] = maxx+1;
            res = max(res, dp[index]);
        }
        return res;
    }
};

