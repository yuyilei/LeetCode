/*
There is a special kind of apple tree that grows apples every day for n days. On the ith day, the tree grows apples[i] apples that will rot after days[i] days, that is on day i + days[i] the apples will be rotten and cannot be eaten. On some days, the apple tree does not grow any apples, which are denoted by apples[i] == 0 and days[i] == 0.

You decided to eat at most one apple a day (to keep the doctors away). Note that you can keep eating after the first n days.

Given two integer arrays days and apples of length n, return the maximum number of apples you can eat.

 

Example 1:

Input: apples = [1,2,3,5,2], days = [3,2,1,4,2]
Output: 7
Explanation: You can eat 7 apples:
- On the first day, you eat an apple that grew on the first day.
- On the second day, you eat an apple that grew on the second day.
- On the third day, you eat an apple that grew on the second day. After this day, the apples that grew on the third day rot.
- On the fourth to the seventh days, you eat apples that grew on the fourth day.
Example 2:

Input: apples = [3,0,0,0,0,2], days = [3,0,0,0,0,2]
Output: 5
Explanation: You can eat 5 apples:
- On the first to the third day you eat apples that grew on the first day.
- Do nothing on the fouth and fifth days.
- On the sixth and seventh days you eat apples that grew on the sixth day.
 

Constraints:

apples.length == n
days.length == n
1 <= n <= 2 * 104
0 <= apples[i], days[i] <= 2 * 104
days[i] = 0 if and only if apples[i] = 0.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-eaten-apples
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 贪心算法，使用优先队列，每次先吃掉容易坏掉的苹果
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int res = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> q;
        int n = days.size();
        int len = n;
        for (int i = 0; i < n || !q.empty(); i++) {
            if (i < len && apples[i] != 0 && days[i] != 0) {
                q.push({i+days[i], apples[i]});
            }
            while (!q.empty() && q.top().first <= i) {
                q.pop();
            }
            if (!q.empty()) {
                pair<int, int> t = q.top();
                q.pop();
                res++;
                t.second--;
                if (t.second > 0) {
                    q.push(t);
                }
            }
        }
        return res;
    }
};
