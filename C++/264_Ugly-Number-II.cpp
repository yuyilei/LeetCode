/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:  

1 is typically treated as an ugly number.
n does not exceed 1690.

*/

class Solution {
public:
    int nthUglyNumber(int n) {
        // 小顶堆
        priority_queue<long, vector<long>, greater<long>> q;
        vector<long> nums;
        vector<int> factor = {2, 3, 5};
        q.push(1);
        // 记录所有出现的数字
        set<long> vis;
        for (int i = 0; i < n; i++) {
            long ugly = q.top();
            q.pop();
            nums.push_back(ugly);
            for (int f: factor) {
                long new_ugly = ugly * f;
                if (vis.find(new_ugly) == vis.end()) {
                    q.push(new_ugly);
                    vis.insert(new_ugly);
                }
            }
        }
        return nums[n-1];
    }
};


// 三指针
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<vector<int>> v = {{0, 2, 0}, {0, 3, 0}, {0, 5, 0}};
        vector<int> nums = {1};
        set<int> s;            // 存储所有出现过的丑数，防止重复
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                v[j][0] = v[j][1] * nums[v[j][2]];
            }
            sort(v.begin(), v.end());
            int ugly = v[0][0];
            v[0][2]++;
            if (s.find(ugly) != s.end()) {
                i--;
                continue;
            }
            s.insert(ugly);
            nums.push_back(ugly);
        }
        return nums[n-1];
    }
};


// 三指针法
//
class Solution {
public:
    int nthUglyNumber(int n) {
        int p2 = 0, p3 = 0, p5 = 0;
        vector<int> nums = {1};
        for (int i = 1; i < n; i++) {
            int minn = min(2*nums[p2], min(3*nums[p3], 5*nums[p5]));
            // 对于每个乘积等于min的指针都加一，防止重复
            if (minn == 2*nums[p2])
                p2++;
            if (minn == 3*nums[p3])
                p3++;
            if (minn == 5*nums[p5])
                p5++;
            nums.push_back(minn);
        }
        return nums.back();
    }
};
