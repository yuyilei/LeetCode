/*
You are given an integer array jobs, where jobs[i] is the amount of time it takes to complete the ith job.

There are k workers that you can assign jobs to. Each job should be assigned to exactly one worker. The working time of a worker is the sum of the time it takes to complete all jobs assigned to them. Your goal is to devise an optimal assignment such that the maximum working time of any worker is minimized.

Return the minimum possible maximum working time of any assignment.

 

Example 1:

Input: jobs = [3,2,3], k = 3
Output: 3
Explanation: By assigning each person one job, the maximum time is 3.
Example 2:

Input: jobs = [1,2,4,7,8], k = 2
Output: 11
Explanation: Assign the jobs the following way:
Worker 1: 1, 2, 8 (working time = 1 + 2 + 8 = 11)
Worker 2: 4, 7 (working time = 4 + 7 = 11)
The maximum working time is 11.
 

Constraints:

1 <= k <= jobs.length <= 12
1 <= jobs[i] <= 107


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-minimum-time-to-finish-all-jobs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


/*
 * 1. 先用贪心算法得出一个次优解
 * 2. dfs剪枝
 */
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int len = jobs.size();
        vector<int> sum (k, 0);
        int res = getTmpRes(jobs, k);
        dfs(jobs, sum, 0, res);
        return res;
    }
private:
    void dfs(vector<int>& jobs, vector<int>& sum, int cur, int& res) {
        if (cur == jobs.size()) {
            int tmp = 0;
            for (int s: sum)
                tmp = max(tmp, s);
            res = min(res, tmp);
            return;
        }
        int worker = sum.size();
        for (int i = 0; i < worker; i++) {
            if (sum[i] + jobs[cur] >= res)
                continue;
            sum[i] += jobs[cur];                     // 把当前作业给第i个工人
            dfs(jobs, sum, cur+1, res);
            sum[i] -= jobs[cur];
            if (sum[i] == 0)                // 如果第i个工人此时没有作业，说明在所有的情况中，前cur-1份工作不需要第i个人做，说明前cur-1份工作的所有情况已经被检查完毕，后面的人也不再需要检查
                return;
        }
    }
    int getTmpRes(vector<int>& jobs, int k) {
        int res = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < k; i++)
            q.push(0);
        for (int i = 0; i < jobs.size(); i++) {
            int t = q.top();
            q.pop();
            q.push(t+jobs[i]);
            res = res == 0 ? t+jobs[i] : max(res, t+jobs[i]);
        }
        return res;
    }
};
