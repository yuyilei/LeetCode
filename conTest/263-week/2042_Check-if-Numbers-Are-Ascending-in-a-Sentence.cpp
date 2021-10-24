class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int> nums; 
        s += ' '; 
        int len = s.size(); 
        int cur = 0, prev = 0; 
        while (cur != len) {
            if (s[cur] == ' ') {
                string sub = s.substr(prev, cur-prev); 
                if (s[prev] > '0' && s[prev] <= '9') {
                    int num = stoi(sub); 
                    if (!nums.empty() && nums.back() >= num) {
                        return false; 
                    }
                    nums.push_back(num); 
                }
                prev = cur+1; 
            }
            cur++; 
        }
        return true; 
    }
};