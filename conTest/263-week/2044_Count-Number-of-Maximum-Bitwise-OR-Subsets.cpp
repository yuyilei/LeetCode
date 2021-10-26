/*
DFS
*/

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        for (int num : nums) {
            maxi |= num;
        }
        dfs(0, 0, nums);
        return count; 
    }
    
    void dfs(int index, int curSum, vector<int>& nums) {
        if (curSum == maxi) {
            count += (1 << (nums.size()-index)); 
            return; 
        }
        if (index == nums.size()) {
            return; 
        }
        dfs(index+1, curSum|nums[index], nums); 
        dfs(index+1, curSum, nums); 
    }
private: 
    int maxi = 0; 
    int count = 0; 
}; 



/*
*/

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size(); 
        int dp[131072] = {0};               // 131072 = pow(2,17) > pow(10,5)
        int res = 0; 
        for (int i = 0; i < pow(2,n); i++) { // there are pow(2,n) schemes in total.  
            int tmp = 0; 
            for (int mask = 0; mask < n; mask++) {
                if ((i&(1<<mask)) != 0) {    // collect nums that are in current scheme
                    tmp |= nums[mask]; 
                }
            }
            res = max(res, tmp); 
            dp[tmp]++;                      
        }
        return dp[res];
    }
};