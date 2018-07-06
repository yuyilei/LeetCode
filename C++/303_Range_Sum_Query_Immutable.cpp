/*

*/
class NumArray {
private:
    vector<int> sums; 
public:
    NumArray(vector<int> nums) {
        if ( nums.size() == 0 )
            return;
        sums.push_back(nums[0]);
        for ( int i = 1 ; i < nums.size() ; i++)
            sums.push_back(sums[i-1]+nums[i]); 
    }
    
    int sumRange(int i, int j) {
        return ( i == 0 ) ? sums[j] : sums[j] - sums[i-1]; 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */