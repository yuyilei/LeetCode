/*
有一个同学在学习分式。他需要将一个连分数化成最简分数，你能帮助他吗？



连分数是形如上图的分式。在本题中，所有系数都是大于等于0的整数。

 

输入的cont代表连分数的系数（cont[0]代表上图的a0，以此类推）。返回一个长度为2的数组[n, m]，使得连分数的值等于n / m，且n, m最大公约数为1。

 

示例 1：

输入：cont = [3, 2, 0, 2]
输出：[13, 4]
解释：原连分数等价于3 + (1 / (2 + (1 / (0 + 1 / 2))))。注意[26, 8], [-13, -4]都不是正确答案。
示例 2：

输入：cont = [0, 0, 3]
输出：[3, 1]
解释：如果答案是整数，令分母为1即可。
限制：

cont[i] >= 0
1 <= cont的长度 <= 10
cont最后一个元素不等于0
答案的n, m的取值都能被32位int整型存下（即不超过2 ^ 31 - 1）。

*/


/*
 gcd(a, b) = gcd(b, a mod b);
 */

/*
 * a + 1 / b 必定是最简分数，所以不用求GCD了。 （前提：a是整数，b是一个最简分数） 因为b是最简分数，所以 1 / b肯定也是一个最简分数，加上一个整数仍然是最简分数
 */
class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        return subfraction(cont, 0);
    }
private:
    vector<int> subfraction(vector<int>& cont, int index) {
        if (index == cont.size()-1)
            return {cont[index], 1};
        vector<int> next = subfraction(cont, index+1);
        int num = next[1];
        int den = next[0];
        num += cont[index]*den;
        return {num, den};
    }
};




class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        int n = cont.size();
        int num = cont[n-1];
        int den = 1;
        for (int i = n-1; i > 0; i--) {
            int cur = cont[i-1];
            int tmp = num;                           // 交换分子分母
            num = den;
            den = tmp;
            num += cur*den;
        }
        return {num, den};
    }
};
