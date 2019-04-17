/*
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
*/
class Solution {
public:
    void swap(vector<int>& nums, int a, int b) {
        int tmp = nums[a]; 
        nums[a] = nums[b]; 
        nums[b] = tmp;  
    }
    void rotate(vector<int>& nums, int k) {
        if ( nums.empty() ) {
            return; 
        }
        k %= nums.size(); 
        int nk = nums.size() - k;
        for ( int i = 0 ; i < nk / 2 ; i++ ) {
            swap(nums,i,nk-1-i); 
        }
        for ( int i = 0 ; i < k / 2 ; i++ ) {
            swap(nums,i+nk,nums.size()-1-i);
        }
        for ( int i = 0 ; i < nums.size() / 2 ; i++ ) {
            swap(nums,i,nums.size()-1-i); 
        }
    }  
};

/*其实是一样的*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //在k处分开，前半段逆序，后半段逆序，然后整体逆序
        if (nums.empty() || (k %= nums.size()) == 0) return;
        int n = nums.size();
        reverse(nums.begin(), nums.begin()+n-k);
        reverse(nums.begin()+n-k, nums.end());
        reverse(nums.begin(), nums.end());
        return;
        
    }
};

// 其实还是一样的
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if ( nums.empty() ) 
            return;
        int len = nums.size();
        k = k % len;
        if ( k == 0 )
            return;
        Swap(nums, 0, len-1);
        Swap(nums, 0, k-1);
        Swap(nums, k, len-1);
    }
private:
    void Swap(vector<int>& nums, int s, int e) {
        while ( s < e ) {
            swap(nums[s++], nums[e--]);
        }
    }
};
