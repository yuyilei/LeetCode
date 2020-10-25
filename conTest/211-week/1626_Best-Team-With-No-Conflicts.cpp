/*
You are the manager of a basketball team. For the upcoming tournament, you want to choose the team with the highest overall score. The score of the team is the sum of scores of all the players in the team.

However, the basketball team is not allowed to have conflicts. A conflict exists if a younger player has a strictly higher score than an older player. A conflict does not occur between players of the same age.

Given two lists, scores and ages, where each scores[i] and ages[i] represents the score and age of the ith player, respectively, return the highest overall score of all possible basketball teams.

 

Example 1:

Input: scores = [1,3,5,10,15], ages = [1,2,3,4,5]
Output: 34
Explanation: You can choose all the players.
Example 2:

Input: scores = [4,5,6,5], ages = [2,1,2,1]
Output: 16
Explanation: It is best to choose the last 3 players. Notice that you are allowed to choose multiple people of the same age.
Example 3:

Input: scores = [1,2,3,5], ages = [8,9,10,1]
Output: 6
Explanation: It is best to choose the first 3 players.
 

Constraints:

1 <= scores.length, ages.length <= 1000
scores.length == ages.length
1 <= scores[i] <= 106
1 <= ages[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-team-with-no-conflicts
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


/*
 * 排序 + 动态规划
 * 1. 对成员进行排序，先根据年龄升序排序，对于年龄相同的，根据分数进行升序排序
 * 2. 对于排序后的成员，dp[i]表示以第i位成员为最后一位的最大分数
        对于dp[i] 遍历0到i-1，遇到（年龄相同）或（年龄小于第i位且分数小于等于第i位）的情况，则可以把第i位加上去，需要从所有可行的情况中选取最大值
 */
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int len = scores.size();
        vector<pair<int, int>> p;
        for (int i = 0; i < len; i++) {
            p.push_back({ages[i], scores[i]});
        }
        sort(p.begin(), p.end(), cmp);
        vector<int> dp (len, 0);
        dp[0] = p[0].second;
        int res = dp[0];
        for (int i = 1; i < len; i++) {
            pair<int, int> cur = p[i];
            int tmp = 0;
            for (int j = 0; j < i; j++) {
                pair<int, int> pre = p[j];
                if (cur.first == pre.first || cur.second >= pre.second) {
                    tmp = max(tmp, dp[j]);
                }
            }
            dp[i] = tmp + cur.second;
            res = max(res, dp[i]);
        }
        return res;
    }
private:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if (a.first != b.first) {
            return a.first < b.first;
        }
        return a.second < b.second;
    }
};
