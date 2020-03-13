/*
Given an array arr of integers, check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).

More formally check if there exists two indices i and j such that :

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]
 

Example 1:

Input: arr = [10,2,5,3]
Output: true
Explanation: N = 10 is the double of M = 5,that is, 10 = 2 * 5.
Example 2:

Input: arr = [7,1,14,11]
Output: true
Explanation: N = 14 is the double of M = 7,that is, 14 = 2 * 7.
Example 3:

Input: arr = [3,1,7,11]
Output: false
Explanation: In this case does not exist N and M, such that N = 2 * M.
 

Constraints:

2 <= arr.length <= 500
-10^3 <= arr[i] <= 10^3

*/

/*
 * 两个map，分别标记可能是 别的数两倍的数、别的数二分之一的数
 * 时间复杂度: 0(n), 空间复杂度: O(n)
 */
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int, bool> n, m;
        for (int num: arr) {
            if (n.find(num*2) != n.end()) {
                return true;
            }
            if (num % 2 == 0 && m.find(num/2) != m.end()) {
                return true;
            }
            // 检查num是否有可能是某个数的两倍，即检查是否为偶数
            if (num % 2 == 0) {
                n[num] = true;
            }
            // num作为整数，一定是某个数的二分之一，所以直接标记
            m[num] = true;
        }
        return false;
    }
};
