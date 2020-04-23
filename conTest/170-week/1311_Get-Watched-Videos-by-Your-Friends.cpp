/*
There are n people, each person has a unique id between 0 and n-1. Given the arrays watchedVideos and friends, where watchedVideos[i] and friends[i] contain the list of watched videos and the list of friends respectively for the person with id = i.

Level 1 of videos are all watched videos by your friends, level 2 of videos are all watched videos by the friends of your friends and so on. In general, the level k of videos are all watched videos by people with the shortest path exactly equal to k with you. Given your id and the level of videos, return the list of videos ordered by their frequencies (increasing). For videos with the same frequency order them alphabetically from least to greatest. 

 

Example 1:



Input: watchedVideos = [["A","B"],["C"],["B","C"],["D"]], friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 1
Output: ["B","C"]
Explanation:
You have id = 0 (green color in the figure) and your friends are (yellow color in the figure):
Person with id = 1 -> watchedVideos = ["C"] 
Person with id = 2 -> watchedVideos = ["B","C"] 
The frequencies of watchedVideos by your friends are: 
B -> 1 
C -> 2
Example 2:



Input: watchedVideos = [["A","B"],["C"],["B","C"],["D"]], friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 2
Output: ["D"]
Explanation:
You have id = 0 (green color in the figure) and the only friend of your friends is the person with id = 3 (yellow color in the figure).
 

Constraints:

n == watchedVideos.length == friends.length
2 <= n <= 100
1 <= watchedVideos[i].length <= 100
1 <= watchedVideos[i][j].length <= 8
0 <= friends[i].length < n
0 <= friends[i][j] < n
0 <= id < n
1 <= level < n
if friends[i] contains j, then friends[j] contains i

*/

// bfs + sort

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        vector<string> res;
        vector<bool> vis (n, false);
        vis[id] = true;
        queue<int> q;
        q.push(id);
        while (level > 0 && !q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                int cur = q.front();
                q.pop();
                for (int f: friends[cur]) {
                    if (!vis[f]) {
                        q.push(f);
                        vis[f] = true;
                    }
                }
            }
            level--;
        }
        map<string, int> index;
        vector<pair<int, string>> v;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (string w: watchedVideos[cur]) {
                if (index.find(w) == index.end()) {
                    v.push_back({1, w});
                    index[w] = v.size()-1;
                }
                else {
                    v[index[w]].first++;
                }
            }
        }
        sort(v.begin(), v.end(), cmp1);
        for (auto e: v) {
            res.push_back(e.second);
        }
        return res;
    }
private:
    static bool cmp1(pair<int, string>& a, pair<int, string>& b) {
        if (a.first != b.first)
            return a.first < b.first;
        else
            return a.second < b.second;
    }
};
