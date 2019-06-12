/*
假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。

给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。

示例 1:

输入: flowerbed = [1,0,0,0,1], n = 1
输出: True
示例 2:

输入: flowerbed = [1,0,0,0,1], n = 2
输出: False
注意:

数组内已种好的花不会违反种植规则。
输入的数组长度范围为 [1, 20000]。
n 是非负整数，且不会超过输入数组的大小。


*/

// 如果有三个连续的0，就可以在中间种一朵花
// 在数组的两边都加上一个0
// 遍历数组，用num记录当前0的个数，当遇到1的时候，num清零，当num到达3的时候，种一朵花，并且将num设定为1（在三个0中间种的花）
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if ( n == 0 )
            return true;
        if ( flowerbed.size() < 2*n-1 )
            return false;
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        int num = 0;
        int count = 0;
        for ( int i = 0 ; i < flowerbed.size() && count < n ; i++ ) {
            if ( flowerbed[i] == 1 ) {
                num = 0;
                continue;
            }
            num++;
            if ( num == 3 ) {
                num = 1;
                count++;
            }
        }
        return count == n;
    }
};
