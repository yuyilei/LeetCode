class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int len = values.size(); 
        vector<bool> vis(len, false); 
        res = 0; 
        maxT = maxTime;
        for (auto edge: edges) {
            int e1 = edge[0], e2 = edge[1]; 
            int time = edge[2]; 
            g[e1].push_back(make_pair(e2, time)); 
            g[e2].push_back(make_pair(e1, time)); 
        }  
        vis[0] = true; 
        dfs(0, values[0], 0, vis, values); 
        return res;
    }
private: 
    unordered_map <int, vector<pair<int, int>>> g;
    int maxT; 
    long res;
    void dfs(int cur, long tmpDis, int tmpTime, vector<bool>& vis, vector<int>& values) {
        if (cur == 0) 
            res = max(tmpDis, res); 
        if (g.find(cur) != g.end()) {
            for (pair<int, int> p: g[cur]) {
                int next = p.first; 
                int time = p.second; 
                if (tmpTime+time <= maxT) {
                    bool nextVis = vis[next]; 
                    long nextDis = nextVis ? tmpDis : tmpDis + values[next]; 
                    vis[next] = true; 
                    dfs(next, nextDis, tmpTime+time, vis, values); 
                    vis[next] = nextVis; 
                }
            }
        }
    }
};