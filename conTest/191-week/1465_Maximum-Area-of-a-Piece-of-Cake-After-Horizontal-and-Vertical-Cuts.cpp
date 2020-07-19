/*
Given a rectangular cake with height h and width w, and two arrays of integers horizontalCuts and verticalCuts where horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.

Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a huge number, return this modulo 10^9 + 7.

 

Example 1:



Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
Output: 4
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green piece of cake has the maximum area.
Example 2:



Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
Output: 6
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green and yellow pieces of cake have the maximum area.
Example 3:

Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
Output: 9
 

Constraints:

2 <= h, w <= 10^9
1 <= horizontalCuts.length < min(h, 10^5)
1 <= verticalCuts.length < min(w, 10^5)
1 <= horizontalCuts[i] < h
1 <= verticalCuts[i] < w
It is guaranteed that all elements in horizontalCuts are distinct.
It is guaranteed that all elements in verticalCuts are distinct.

*/

// 设置成long才不会溢出
class Solution {
public:
    int maxArea(int h, int w, vector<int>& ho, vector<int>& ve) {
        ho.push_back(0); ve.push_back(0);
        ho.push_back(h); ve.push_back(w);
        sort(ho.begin(), ho.end());
        sort(ve.begin(), ve.end());
        long maxh = 0;
        long maxv = 0;
        const long mod  = 1000000007;
        for (int i = 0; i < ho.size() - 1; i++) {
            if (ho[i+1] - ho[i] > maxh) {
                maxh = ho[i+1] - ho[i];
            }
        }
        for (int i = 0; i < ve.size() - 1; i++) {
            if (ve[i+1] - ve[i] > maxv) {
                maxv = ve[i+1] - ve[i];
            }
        }
        return ((maxh *maxv) % mod);
    }
};

