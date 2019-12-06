class Solution {
public:
    int candy(vector<int>& ratings) {
        int res = 0;
        int len = ratings.size();
        vector<int> help (len, 1);
        for (int i = 1; i < len; i++) {
            if (ratings[i] > ratings[i-1]) {
                help[i] = help[i-1]+1;
            }
        }
        for (int i = len-1; i > 0; i--) {
            if (ratings[i-1] > ratings[i]) {
                help[i-1] = max(help[i-1], help[i]+1);
            }
            res += help[i];
            // cout << help[i] << endl;
        }
        res += help[0];
        // cout << help[0] << endl;
        return res;
    }
};
