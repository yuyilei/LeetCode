/*
Given an undirected tree consisting of n vertices numbered from 1 to n. A frog starts jumping from the vertex 1. In one second, the frog jumps from its current vertex to another unvisited vertex if they are directly connected. The frog can not jump back to a visited vertex. In case the frog can jump to several vertices it jumps randomly to one of them with the same probability, otherwise, when the frog can not jump to any unvisited vertex it jumps forever on the same vertex. 

The edges of the undirected tree are given in the array edges, where edges[i] = [fromi, toi] means that exists an edge connecting directly the vertices fromi and toi.

Return the probability that after t seconds the frog is on the vertex target.

 

Example 1:



Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 2, target = 4
Output: 0.16666666666666666
Explanation: The figure above shows the given graph. The frog starts at vertex 1, jumping with 1/3 probability to the vertex 2 after second 1 and then jumping with 1/2 probability to vertex 4 after second 2. Thus the probability for the frog is on the vertex 4 after 2 seconds is 1/3 * 1/2 = 1/6 = 0.16666666666666666.
Example 2:



Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 1, target = 7
Output: 0.3333333333333333
Explanation: The figure above shows the given graph. The frog starts at vertex 1, jumping with 1/3 = 0.3333333333333333 probability to the vertex 7 after second 1.
Example 3:

Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 20, target = 6
Output: 0.16666666666666666
 

Constraints:

1 <= n <= 100
edges.length == n-1
edges[i].length == 2
1 <= edges[i][0], edges[i][1] <= n
1 <= t <= 50
1 <= target <= n
Answers within 10^-5 of the actual value will be accepted as correct.

*/

class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vis.resize(n+1);
        pro.resize(n+1);
        for (int i = 1; i <= n; i++) {
            vis[i] = false;
            pro[i] = 0;
        }
        for (vector<int> edge: edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        pro[1] = 1.0;
        vis[1] = true;
        dfs(t, 1);
        return pro[target];
    }
private:
    vector<bool> vis;
    vector<double> pro;        // pro[i] 表示t时间后，青蛙在i处的概率
    map<int, vector<int>> tree;
    void dfs(int time, int cur) {
        if (time <= 0) {
            return;
        }
        int to_count = 0;
        for (int to: tree[cur]) {
            if (!vis[to])
                to_count++;
        }
        if (to_count == 0)
            return;
        // 去某一个点的概率
        double p = pro[cur] / to_count;
        // 当前点的概率清零，因为跳到下一个点
        pro[cur] = 0;
        for (int to: tree[cur]) {
            if (!vis[to]) {
                vis[to] = true;
                // 为所有能去的点都加上概率
                pro[to] += p;
                dfs(time-1, to);
                vis[to] = false;
            }
        }
    }
};
