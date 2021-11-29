class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res  = 0;
        int kt = tickets[k]; 
        int len = tickets.size(); 
        for (int i = 0; i <len; i++) {
            int num; 
            if (i <= k) {
                num = min(kt, tickets[i]); 
            }
            else {
                num = min(kt-1, tickets[i]); 
            }
            res += num;
        }
        return res; 
    }
};