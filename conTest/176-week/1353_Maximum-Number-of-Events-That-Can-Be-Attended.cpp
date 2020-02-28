/*
Given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei. Notice that you can only attend one event at any time d.

Return the maximum number of events you can attend.

 

Example 1:


Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.
Example 2:

Input: events= [[1,2],[2,3],[3,4],[1,2]]
Output: 4
Example 3:

Input: events = [[1,4],[4,4],[2,2],[3,4],[1,1]]
Output: 4
Example 4:

Input: events = [[1,100000]]
Output: 1
Example 5:

Input: events = [[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]]
Output: 7
 

Constraints:

1 <= events.length <= 10^5
events[i].length == 2
1 <= events[i][0] <= events[i][1] <= 10^5

*/

/*
 * 走弯路了，写了一个小时思路错了， 最后借鉴别人的方法:
 * 贪心法：
 * 对于某一天，能够举行当前开始以及之前时间开始且结束时间在还未结束的会议，在这些会议中，应该选择
 * 结束时间最小的会议举行，因为别的结束时间大的会议有更多选择，用小顶堆记录结束时间最小的会议
 */

#define MAX 1e5+1
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int res = 0;
        vector<vector<int>> start (MAX);
        // 记录从当天开始的所有的会议的索引
        for (int i = 0; i < events.size(); i++) {
            start[events[i][0]].emplace_back(i);
        }
        // 小顶堆，记录当前扫描过的所有会议的结束时间，堆顶是最小结束时间
        priority_queue<int, vector<int>, greater<int>> q;
        // 扫描所有时间
        for (int now = 1; now < MAX; now++) {
            // 在小顶堆中加入当前时间开始的所有会议的结束时间
            for (int index: start[now]) {
                q.push(events[index][1]);
            }
            // 剔除当前时间无法举行的会议（结束时间 < 当前时间）
            while (!q.empty() && q.top() < now) {
                q.pop();
            }
            // 取出堆顶的最小时间，举行该会议
            if (!q.empty()) {
                res++;
                q.pop();
            }
        }
        return res;
    }
};
