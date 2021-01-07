/*
A good meal is a meal that contains exactly two different food items with a sum of deliciousness equal to a power of two.

You can pick any two different foods to make a good meal.

Given an array of integers deliciousness where deliciousness[i] is the deliciousness of the i​​​​​​th​​​​​​​​ item of food, return the number of different good meals you can make from this list modulo 109 + 7.

Note that items with different indices are considered different even if they have the same deliciousness value.

 

Example 1:

Input: deliciousness = [1,3,5,7,9]
Output: 4
Explanation: The good meals are (1,3), (1,7), (3,5) and, (7,9).
Their respective sums are 4, 8, 8, and 16, all of which are powers of 2.
Example 2:

Input: deliciousness = [1,1,1,3,3,3,7]
Output: 15
Explanation: The good meals are (1,1) with 3 ways, (1,3) with 9 ways, and (1,7) with 3 ways.
 

Constraints:

1 <= deliciousness.length <= 105
0 <= deliciousness[i] <= 220

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-good-meals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
枚举2的0次方到2的22次方
*/

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        map<int, long> count;
        for (int d: deliciousness) {
            count[d]++;
        }
        vector<int> v;
        int power = 1;
        for (int i = 0; i < 22; i++) {
            v.push_back(power);
            power *= 2;
        }
        int res = 0;
        int mod = 1000000007;
        for (auto cur: count) {
            int c = cur.first;
            int n = cur.second;
            for (int i = 0; i < 22; i++) {
                int p = v[i];
                int d = p - c;
                if (count.find(d) != count.end() && count[d] != 0) {
                    if (d != c) {
                        long tmp = (count[d]*count[c]);
                        res = (res + tmp) % mod;
                    }
                    else if (count[c] != 1){
                        long tmp = (count[c]*(count[c]-1))/2;
                        res = (res + tmp) % mod;
                    }
                }
            }
            count[c] = 0;
        }
        return res;
    }
};
