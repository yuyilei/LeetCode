/*
给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。

示例 1 :

输入: 2736
输出: 7236
解释: 交换数字2和数字7。
示例 2 :

输入: 9973
输出: 9973
解释: 不需要交换。
注意:

给定数字的范围是 [0, 108]

*/

// 将数字从大到小排列，与原数字比较，找出第一位置不一样的数，交换
// 下面是步骤：
// 先将数字转化为数组tmp，高位在后，低位在前
// 再将此数组拷贝一份other，后排序，从小到大
// 从最后一位开始比较两个数组（也就是从高位开始和排序后的从大到小的数列各位比较）
// 一旦遇到不同的位，就要交换（只交换一次），注意在tmp中寻找tmp[j] == other[i]时（i为当前位），要使j尽量小
// 如，输入，1993， tmp为3, 9, 9, 1，other为1，3，9，9，当 i = 3时，tmp[i] != other[i]
// 寻找tmp[j] = other[i]，j尽量小，所以j = 1而不是j = 2
// 也就是尽量用低位的数去交换

class Solution {
public:
    int maximumSwap(int num) {
        vector<int> tmp;
        int n = num;
        while (n > 0) {
            tmp.push_back(n%10);
            n = n/10;
        }
        vector<int> other = tmp;
        sort(other.begin(), other.end());
        int len = tmp.size();
        for (int i = len-1 ; i >= 0 ; i--) {
            if (tmp[i] != other[i]) {
                int index = i;
                for (int j = i-1; j >= 0 ;j--) {
                    if (tmp[j] == other[i]) {
                        index = j;
                    }
                }
                if (index != i) {
                    tmp[index] = tmp[i];
                    tmp[i] = other[i];
                }
                break;
            }
        }
        int res = 0;
        for (int i = len-1 ; i >= 0 ; i--) {
            res = res*10 + tmp[i];
        }
        return res;
    }
};
