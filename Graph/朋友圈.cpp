/*
班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 的朋友。所谓的朋友圈，是指所有朋友的集合。

给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。你必须输出所有学生中的已知的朋友圈总数。

示例 1:

输入:
[[1,1,0],
 [1,1,0],
 [0,0,1]]
输出: 2
说明：已知学生0和学生1互为朋友，他们在一个朋友圈。
第2个学生自己在一个朋友圈。所以返回2。
示例 2:

输入:
[[1,1,0],
 [1,1,1],
 [0,1,1]]
输出: 1
说明：已知学生0和学生1互为朋友，学生1和学生2互为朋友，所以学生0和学生2也是朋友，所以他们三个在一个朋友圈，返回1。
注意：

N 在[1,200]的范围内。
对于所有学生，有M[i][i] = 1。
如果有M[i][j] = 1，则有M[j][i] = 1。
*/

// 其实就是求图有几个连通分量

// dfs:
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if ( M.empty() )
            return 0;
        int len = M.size();
        int res = 0;
        vector<bool> visited (len,false);
        for ( int i = 0 ; i < len ; i++ ) {
            if ( visited[i] )
                continue;
            res++;
            dfs(i,M,visited);
        }
        return res;
    }
private:
    void dfs(int now, vector<vector<int>> &M, vector<bool> &visited) {
        visited[now] = true;
        int len = M.size();
        for ( int i = 0 ; i < len ; i++ ) {
            if ( M[now][i] == 1 && !visited[i] ) {
                dfs(i,M,visited);
            }
        }
    }
};


// 并查集
// 压缩路径
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int res = 0;
        int len = M.size();
        for ( int i = 0 ; i < len ; i++ ) {
            root[i] = i;
        }
        for ( int i = 0 ; i < len ; i++ ) {
            for ( int j = 0 ; j < len ; j++ ) {
                if ( i != j && M[i][j] == 1 ) {
                    Union(i,j);
                }
            }
        }
        for ( int i = 0 ; i < len ; i++ ) {
            if ( root[i] == i ) {
                res++;
            }
        }
        return res;
    }
private:
    int root[201];
    void Union(int x, int y) {
        x = findRoot(x);
        y = findRoot(y);
        if ( x != y )
            root[x] = y;
    }
    int findRoot(int x) {
        if ( root[x] != x )
            root[x] = findRoot(root[x]);
        return root[x];
    }
};
