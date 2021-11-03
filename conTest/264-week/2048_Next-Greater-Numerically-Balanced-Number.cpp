class Solution {
public:
    int nextBeautifulNumber(int n) {
        int min = n+1, max = 7777777; 
        int len = to_string(n).size(); 
        for (int i = min; i <= max; i++) {
            if (isBeautiful(i, len)) {
                return i; 
            }
        }
        return -1; 
    }
private: 
    bool isBeautiful(int cur, int len) {
        int cnt[8] = {0};
        while (cur > 0) {
            int t = cur % 10; 
            if (t > 7 || t == 0) {
                return false;
            }
            cnt[t]++; 
            cur /= 10; 
        }
        for (int i = 1; i < 8; i++) {
            if (cnt[i] != 0 && cnt[i] != i) {
                return false; 
            }
        }
        return true; 
    }
};