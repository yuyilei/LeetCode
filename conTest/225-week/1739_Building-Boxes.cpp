/*
You have a cubic storeroom where the width, length, and height of the room are all equal to n units. You are asked to place n boxes in this room where each box is a cube of unit side length. There are however some rules to placing the boxes:

You can place the boxes anywhere on the floor.
If box x is placed on top of the box y, then each side of the four vertical sides of the box y must either be adjacent to another box or to a wall.
Given an integer n, return the minimum possible number of boxes touching the floor.

 

Example 1:



Input: n = 3
Output: 3
Explanation: The figure above is for the placement of the three boxes.
These boxes are placed in the corner of the room, where the corner is on the left side.
Example 2:



Input: n = 4
Output: 3
Explanation: The figure above is for the placement of the four boxes.
These boxes are placed in the corner of the room, where the corner is on the left side.
Example 3:



Input: n = 10
Output: 6
Explanation: The figure above is for the placement of the ten boxes.
These boxes are placed in the corner of the room, where the corner is on the back side.
 

Constraints:

1 <= n <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/building-boxes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    int minimumBoxes(int n) {
        if (n <= 3)
            return n;
        int sum = 0;
        int layer = 1;
        int res = 0;
        while (sum < n) {                      // 先按照对角线的方式尽量填满，直到总数大于或等于n
            res = layer*(layer+1)/2;           // res是最底下一层的个数，layer表示层数
            sum += res;
            layer++;
        }
        layer--;
        while (sum - layer >= n) {             // 每次需要减去层数个方形体才能成功减去底层的一个正方体
            sum -= layer;
            layer--;
            res--;
        }
        return res;
    }
};
