/*
There is a hidden integer array arr that consists of n non-negative integers.

It was encoded into another integer array encoded of length n - 1, such that encoded[i] = arr[i] XOR arr[i + 1]. For example, if arr = [1,0,2,1], then encoded = [1,2,3].

You are given the encoded array. You are also given an integer first, that is the first element of arr, i.e. arr[0].

Return the original array arr. It can be proved that the answer exists and is unique.

 

Example 1:

Input: encoded = [1,2,3], first = 1
Output: [1,0,2,1]
Explanation: If arr = [1,0,2,1], then first = 1 and encoded = [1 XOR 0, 0 XOR 2, 2 XOR 1] = [1,2,3]
Example 2:

Input: encoded = [6,2,7,3], first = 4
Output: [4,2,0,7,4]
 

Constraints:

2 <= n <= 104
encoded.length == n - 1
0 <= encoded[i] <= 105
0 <= first <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decode-xored-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


/*
 *  encoded[i] = arr[i] ^ arr[i+1]
 *  encoded[i] ^ arr[i] = arr[i] ^ arr[i+1] ^ arr[i]
 *  encoded[i] ^ arr[i] = arr[i+1] ^ 0
 *  encoded[i] ^ arr[i] = arr[i+1]
 */

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res;
        res.push_back(first);
        int len = encoded.size();
        for (int i = 0; i < len; i++) {
            res.push_back(res[i] ^ encoded[i]);
        }
        return res;
    }
};
