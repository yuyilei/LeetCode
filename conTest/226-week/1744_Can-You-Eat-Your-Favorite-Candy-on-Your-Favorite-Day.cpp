/*
You are given a (0-indexed) array of positive integers candiesCount where candiesCount[i] represents the number of candies of the ith type you have. You are also given a 2D array queries where queries[i] = [favoriteTypei, favoriteDayi, dailyCapi].

You play a game with the following rules:

You start eating candies on day 0.
You cannot eat any candy of type i unless you have eaten all candies of type i - 1.
You must eat at least one candy per day until you have eaten all the candies.
Construct a boolean array answer such that answer.length == queries.length and answer[i] is true if you can eat a candy of type favoriteTypei on day favoriteDayi without eating more than dailyCapi candies on any day, and false otherwise. Note that you can eat different types of candy on the same day, provided that you follow rule 2.

Return the constructed array answer.

 

Example 1:

Input: candiesCount = [7,4,5,3,8], queries = [[0,2,2],[4,2,4],[2,13,1000000000]]
Output: [true,false,true]
Explanation:
1- If you eat 2 candies (type 0) on day 0 and 2 candies (type 0) on day 1, you will eat a candy of type 0 on day 2.
2- You can eat at most 4 candies each day.
   If you eat 4 candies every day, you will eat 4 candies (type 0) on day 0 and 4 candies (type 0 and type 1) on day 1.
      On day 2, you can only eat 4 candies (type 1 and type 2), so you cannot eat a candy of type 4 on day 2.
	  3- If you eat 1 candy each day, you will eat a candy of type 2 on day 13.
	  Example 2:

	  Input: candiesCount = [5,2,6,4,1], queries = [[3,1,2],[4,10,3],[3,10,100],[4,100,30],[1,3,1]]
	  Output: [false,true,true,false,false]
	   

	  Constraints:

	  1 <= candiesCount.length <= 105
	  1 <= candiesCount[i] <= 105
	  1 <= queries.length <= 105
	  queries[i].length == 3
	  0 <= favoriteTypei < candiesCount.length
	  0 <= favoriteDayi <= 109
	  1 <= dailyCapi <= 109

	  来源：力扣（LeetCode）
	  链接：https://leetcode-cn.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day
	  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int type = candiesCount.size();
        vector<long> sum (type, 0);
        sum[0] = candiesCount[0];
        for (int i = 1; i < type; i++) {
            sum[i] = (long)sum[i-1] + candiesCount[i];
        }
        int q = queries.size();
        vector<bool> res (q, false);
        int index = 0;
        for (auto query: queries) {
            int t = query[0];
            int d = query[1];
            int cap = query[2];
            long minEat = d+1;                // 0到d天每天只吃一个糖果
            long maxEat = (long)(d+1)*cap;    // 0到d天每天都吃最大个数的糖果
            if (t == 0 && sum[t] >= minEat) {
                res[index] = true;
            }
            // 如果0到d天都吃cap个糖果，一定要能把0到t-1的糖果都消耗完,且还至少多吃一个空档吃第t种糖果
            // 如果0到d天都只吃1个糖果，一定要能支撑到第d天，也就是0到t-1种糖果的总数一定要大于d
            if (t != 0 && sum[t] >= minEat && sum[t-1]+1 <= maxEat) {
                res[index] = true;
            }

            index++;
        }
        return res;
    }
};
