/*
现在你总共有 n 门课需要选，记为 0 到 n-1。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]

给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习？

示例 1:

输入: 2, [[1,0]] 
输出: true
解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
示例 2:

输入: 2, [[1,0],[0,1]]
输出: false
解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。
说明:

输入的先决条件是由边缘列表表示的图形，而不是邻接矩阵。详情请参见图的表示法。
你可以假定输入的先决条件中没有重复的边。
提示:

这个问题相当于查找一个循环是否存在于有向图中。如果存在循环，则不存在拓扑排序，因此不可能选取所有课程进行学习。
通过 DFS 进行拓扑排序 - 一个关于Coursera的精彩视频教程（21分钟），介绍拓扑排序的基本概念。
拓扑排序也可以通过 BFS 完成。
*/

// 拓扑排序 
// 每次寻找入度为0的点，并删除该点连接的边，如果所有的点都能达到 入度为0的状态，就是说明存在拓扑排序
class Solution {
public:
    bool canFinish(int num, vector<pair<int, int>>& pre) {
        vector<int> to (num, 0);  // 计算每个入度
        map<int, vector<int>> m;   // 邻接表
        queue<int> q;
        int res = 0;
        for ( int i = 0 ; i < pre.size() ; i++ ) {
            to[pre[i].second]++;
            m[pre[i].first].push_back(pre[i].second);
        }
        // 不断的寻找 入度为0的点，只找到入度为0的点之后，在邻接表中删除该与该点相关的边 
        for ( int i = 0 ; i < num ; i++ )
            if ( to[i] == 0 )
                q.push(i);  // 寻找入度为0的点
        while ( !q.empty() ) {
            res++;  
            int tmp = q.front();
            q.pop();
            for ( int i = 0 ; i < m[tmp].size() ; i++ ) {
                to[m[tmp][i]]--;          // 更新 m[tmp][i] 的入度
                if ( to[m[tmp][i]] == 0 )  // 检查更新后入度是否为0 
                    q.push(m[tmp][i]);
            }
        }
        return (res == num);
    }
};
