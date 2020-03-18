/*
There are n engineers numbered from 1 to n and two arrays: speed and efficiency, where speed[i] and efficiency[i] represent the speed and efficiency for the i-th engineer respectively. Return the maximum performance of a team composed of at most k engineers, since the answer can be a huge number, return this modulo 10^9 + 7.

The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency among their engineers.



Example 1:

Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
Output: 60
Explanation:
We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7). That is, performance = (10 + 5) * min(4, 7) = 60.
Example 2:

Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
Output: 68
Explanation:
This is the same example as the first but k = 3. We can select engineer 1, engineer 2 and engineer 5 to get the maximum performance of the team. That is, performance = (2 + 10 + 5) * min(5, 4, 7) = 68.
Example 3:

Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
Output: 72


Constraints:

1 <= n <= 10^5
speed.length == n
efficiency.length == n
1 <= speed[i] <= 10^5
1 <= efficiency[i] <= 10^8
1 <= k <= n
*/


/*
 * 1. 根据efficiency进行降序排序
 * 2. 遍历排序后的数组，满足以下条件：
 *      a. 当前k个工程师的最低效率为当前效率
 *      b. 用小顶堆遍历过的工程师的速度，堆顶元素为最小速度
 *      c. 当小顶堆的元素个数大于k时，取出堆顶元素，剩余为当前所有工程师的速度和
 *      d. 有一个特殊情况：如果新加入的工程师是当前速度最小和效率最小时，且被小顶堆pop出来时，此时不应该再计算sum*eff，因为当前效率没有被更新（被pop出去了）
 */

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long mod = 1000000007;
        long res = 0;
        long sum = 0;
        vector<vector<int>> es;
        for (int i = 0; i < n; i++) {
            es.push_back({efficiency[i], speed[i]});
        }
        sort(es.rbegin(), es.rend());
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < n; i++) {
            sum += es[i][1];                    // 当前所有工程师的速度和
            int eff = es[i][0];                 // 当前工程师的效率就是这k个工程师中最小效率
            q.push(es[i][1]);                   // 将当前速度加入小顶堆
            bool flag = false;                  // 检测当前工程师是否被pop出去
            while (q.size() > k) {              // 小顶堆的元素的大于k时，取出堆顶元素（最小速度）
                if (q.top() == es[i][1]) {
                    flag = true;
                }
                sum -= q.top();
                q.pop();
            }
            if (!flag)
                res = max(res, eff*sum);
        }
        return (int)(res%mod);
    }
};
