/*
找到给定字符串（由小写字符组成）中的最长子串 T ， 要求 T 中的每一字符出现次数都不少于 k 。输出 T 的长度。

示例 1:

输入:
s = "aaabb", k = 3

输出:
3

最长子串为 "aaa" ，其中 'a' 重复了 3 次。
示例 2:

输入:
s = "ababbc", k = 2

输出:
5

最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。

*/

class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.empty())
            return 0;
        if (k == 1)
            return s.size();
        return longestSub(s, k, 0, s.size()-1);
    }
private:
    int longestSub(string s, int k, int p1, int p2) {
        if (p2-p1+1 < k)
            return 0;
        int counter[26] = {0};
        for (int i = p1; i <= p2; i++)
            counter[s[i]-'a']++;
        while (p2-p1+1 >= k && counter[s[p1]-'a'] < k)
            p1++;
        while (p2-p1+1 >= k && counter[s[p2]-'a'] < k)
            p2--;
        if (p2-p1+1 < k)
            return 0;
        for (int i = p1; i <= p2; i++) {
            if (counter[s[i]-'a'] < k)
                return max(longestSub(s, k, p1, i-1), longestSub(s, k, i+1, p2));
        }
        return p2-p1+1;
    }

};
