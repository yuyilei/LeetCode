class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while ( left <= right ){
            int middle = ( left + right ) / 2;
            if ( nums[middle] == target )
                return true;
            if ( nums[middle] > nums[left] ){              // 前半部分是有序的
                if ( nums[middle] > target && nums[left] <= target )  // 在前半部分
                    right = middle - 1;
                else 
                    left = middle + 1;
            }
            else if ( nums[middle] < nums[left]) {         // 后半部分是有序的
                if ( nums[middle] < target && nums[right] >= target )  //  在后半部分 
                    left = middle + 1;
                else 
                    right = middle -1;
            }
            else{                                          // nums[middle] == nums[left]                              
                left++; 
            }
        }
        return false;
    }
};