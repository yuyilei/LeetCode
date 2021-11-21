/*

含有5种元音的substring = 最多含有5种元音的substring - 最多含有4种元音的子串 

atMostKVowel(string &s, int k): 计算s中最多含有k种元音的substring数量 

*/

class Solution {
public:
    int countVowelSubstrings(string word) {
        return atMostKVowel(word, 5) - atMostKVowel(word, 4); 
    }
private: 
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'); 
    }
    int atMostKVowel(string &s, int k) {
        int count = 0;
        unordered_map<char, int> m;        // 计算 s[left, right] 中各个元音出现的频率
        int len = s.size(); 
        int left = 0, right = 0; 
        while (right < len) {
            if (!isVowel(s[right])) {      // 不是元音，清空 
                right++; 
                left = right; 
                m.clear(); 
                continue; 
            }
            m[s[right]]++; 
            right++;                       
            while (m.size() > k) {        // 如果所含有的元音种类比k多，需要滑动窗口的左边往右移动，直到元音种类为k
                m[s[left]]--; 
                if (m[s[left]] == 0) {
                    m.erase(s[left]); 
                }
                left++;
            }
            count += (right-left+1);     // right-left+1 =  s[left, right] 中 以 s[right] 为结尾的substring数量
        }
        return count; 
    }
};