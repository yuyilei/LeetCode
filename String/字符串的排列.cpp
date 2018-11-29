/*
给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

换句话说，第一个字符串的排列之一是第二个字符串的子串。

示例1:

输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").


示例2:

输入: s1= "ab" s2 = "eidboaoo"
输出: False


注意：

输入的字符串只包含小写字母
两个字符串的长度都在 [1, 10,000] 之间

*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if ( s2.size() < s1.size() )
            return false;
        vector<int> count (26,0);
        for ( char c : s1 )
            count[c-'a']++;
        for ( int i = 0 ; i <= s2.size() - s1.size() ; i++ ) {
            if ( count[s2[i]-'a'] == 0 ) {
                continue;
            }
            else {
                vector<int> tmp;
                tmp.assign(count.begin(),count.end());
                int j;
                for ( j = i ; j < i + s1.size() ; j++ ) {
                    if ( tmp[s2[j]-'a'] == 0 )
                        break;
                    tmp[s2[j]-'a']--;
                }
                if ( j == i + s1.size() )
                    return true;
            }
        }
        return false;
    }
};
