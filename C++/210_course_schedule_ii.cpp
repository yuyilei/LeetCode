class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& pre) {
        vector<int> res;
        vector<int> indegree (numCourses,0); 
        vector<vector<int>> to (numCourses);
        for ( int i = 0 ; i < pre.size() ; i++ ) {
            int last = pre[i].second, next = pre[i].first; 
            indegree[next]++;
            to[last].push_back(next); 
        }
        
        while ( res.size() < numCourses ) {
            int now = -1; 
            for ( int i = 0 ; i < numCourses ; i++ ) {
                if ( indegree[i] == 0 ) {
                    now = i;
                    indegree[i] = -1; 
                    break; 
                }
            }
            if ( now == -1 ) {
                vector<int> null; 
                return null; 
            } 
            res.push_back(now);
            for ( int i = 0 ; i < to[now].size() ; i++ ) {
                if ( indegree[to[now][i]] > 0 ) {
                    indegree[to[now][i]]--;
                }   
            }
        }
        return res;
    }
};