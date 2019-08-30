/*
假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。

注意：
总人数少于1100人。

示例

输入:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

输出:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

*/

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        if (people.empty())
            return res;
        sort(people.begin(),people.end(),cmp);
        for (auto person: people) {
            res.insert(res.begin()+person[1], person);
        }
        return res;
    }
private:
    static bool cmp(vector<int> a, vector<int> b) {
        if (a[0] != b[0])
            return a[0] > b[0];
        return a[1] < b[1];
    }
};
