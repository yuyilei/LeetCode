/*
Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

Example 1:
Input:
nums = [1,3,1]
k = 1
Output: 0
Explanation:
Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
Note:
2 <= len(nums) <= 10000.
0 <= nums[i] < 1000000.
1 <= k <= len(nums) * (len(nums) - 1) / 2.

*/


// 法一：类似于排序，将各个差值放入桶中，会超时
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        map<int, long> sub;
        map<int, long> cnt;
        vector<int> un;
        int res;
        for (int n: nums) {
            if (cnt.find(n) == cnt.end()) {
                cnt[n] = 0;
                un.push_back(n);
            }
            cnt[n]++;
        }
        int len = cnt.size();
        for (int i = 0; i < len-1; i++) {
            for (int j = i+1; j < len; j++) {
                int tmp = abs(un[i]-un[j]);
                long all = cnt[un[i]] * cnt[un[j]];
                sub[tmp] += all;
            }
        }
        for (auto it: cnt) {
            sub[0] += (it.second)*(it.second-1)/2;
        }
        for (auto it: sub) {
            if (it.second < k) {
                k -= it.second;
            }
            else {
                res = it.first;
                break;
            }
        }
        return res;
    }
};



// 二分法+滑动窗口
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int low = 0, high = nums[len-1] - nums[0];
        while (low < high) {
            int mid = (low+high)/2;
            int count = 0;
            int left = 0;
            for (int right = 0; right < len; right++) {
                while (nums[right]-nums[left] > mid) left++;
                count += right - left;
            }
            if (count >= k) {
                high = mid;
            }
            else {
                low = mid+1;
            }
        }
        return low;
    }
};
