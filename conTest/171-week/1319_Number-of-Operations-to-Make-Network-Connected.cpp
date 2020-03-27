/*
There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a network where connections[i] = [a, b] represents a connection between computers a and b. Any computer can reach any other computer directly or indirectly through the network.

Given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected. Return the minimum number of times you need to do this in order to make all the computers connected. If it's not possible, return -1. 

 

Example 1:



Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
Example 2:



Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.
Example 4:

Input: n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
Output: 0
 

Constraints:

1 <= n <= 10^5
1 <= connections.length <= min(n*(n-1)/2, 10^5)
connections[i].length == 2
0 <= connections[i][0], connections[i][1] < n
connections[i][0] != connections[i][1]
There are no repeated connections.
No two computers are connected by more than one cable.

*/

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int count = 0;          // 联通分量的个数
        int surplus = 0;        // 多余的边
        vis.resize(n+1);
        for (vector<int> con: connections) {
            grid[con[0]].push_back(con[1]);
            grid[con[1]].push_back(con[0]);
        }
        for (int i = 0; i < n; i++) {
            if (grid.find(i) == grid.end()) {
                count++;
            } else {
                if (!vis[i]) {
                    count++;
                    int edge = 0;
                    int node = 0;
                    DFS(grid, i, edge, node);
                    edge /= 2;
                    surplus += (edge - (node-1));
                }
            }
        }
        return (surplus >= (count-1)) ? count - 1: -1;
    }
private:
    vector<bool> vis;
    map<int, vector<int>> grid;
    void DFS(map<int, vector<int>> &grid, int cur, int &edge, int &node) {
        vis[cur] = true;
        edge += grid[cur].size();
        node++;
        for (int c: grid[cur]) {
            if (!vis[c]) {
                DFS(grid, c, edge, node);
            }
        }
    }
};
