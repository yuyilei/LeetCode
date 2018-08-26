/*
类似于拓扑排序，每次都找出度为1的点，删除，最后剩下的两个或一个点是最长树的中间点，也就是根结点. 
每次去掉当前图的所有叶子节点，重复此操作直到只剩下最后的根。 
*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if ( edges.size() == 0 ) {
            return vector<int> (1,0);
        }
        vector<vector<int>> graph (n);
        vector<int> degree (n,0);
        for ( auto each : edges ) {
            graph[each.first].push_back(each.second);
            graph[each.second].push_back(each.first); 
            degree[each.first]++;
            degree[each.second]++;
        }
        vector<int> leaves;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( degree[i] == 1 ) {
                leaves.push_back(i); 
                degree[i] = -1;
            }
        }
        while ( n > 2 ) {
            vector<int> next;
            for ( auto leaf : leaves ) {
                for ( auto each : graph[leaf] ) {
                    if ( degree[each] > 1 )
                        degree[each]--;
                    if ( degree[each] == 1 ) {
                        degree[each] = -1;
                        next.push_back(each);
                    }
                }
            }
            n -= leaves.size();
            leaves = next;
        }
        return leaves;
    }
};