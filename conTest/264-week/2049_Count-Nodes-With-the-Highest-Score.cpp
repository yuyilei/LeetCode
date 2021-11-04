class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size(); 
        count.resize(n, 0); 
        kids.resize(n); 
        int maxscore = 0; 
        // build the tree 
        for (int i = 1; i < n; i++) {
            kids[parents[i]].push_back(i); 
        }
        // get the node count of each subtree
        dfs(0); 
        // get the score of each node
        for (int i = 0; i < n; i++) {
            getScore(i, parents); 
        }
        // m.rbegin() has the max key
        maxscore = m.rbegin()->second; 
        return maxscore; 
    }
private: 
    vector<int> count; 
    vector<vector<int>> kids; 
    map<long, int> m;  
    int n; 
    void dfs(int cur) {
        count[cur] = 1;
        if (kids[cur].size()==0) {
            return; 
        }
        for (int i = 0; i < kids[cur].size(); i++) {
            dfs(kids[cur][i]); 
            count[cur] += count[kids[cur][i]]; 
        }
    }
    void getScore(int cur, vector<int>& parents) {
        long product = 1;
        if (parents[cur] != -1) {
            product *= count[0]-count[cur]; 
        }
        for (int i = 0; i < kids[cur].size(); i++) {
            product *= count[kids[cur][i]];
        }
        m[product]++;
    }
};