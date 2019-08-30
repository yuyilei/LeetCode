/*
根据每日 气温 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0 来代替。

例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。

*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int len = T.size();
        if (T.empty())
            return {};
        vector<int> res (len, 0);
        stack<pair<int,int>> s;
        for (int i = 0; i < T.size(); i++) {
            if (s.empty() || s.top().first >= T[i])
                s.push({T[i], i});
            else {
                while (!s.empty() && s.top().first < T[i]) {
                    int temp = s.top().second;
                    s.pop();
                    res[temp] = i-temp;
                }
                s.push({T[i], i});
            }
        }
        return res;
    }
};
