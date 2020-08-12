/*
Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.

 

Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
 

Constraints:

1 <= arr.length <= 10^4
1 <= arr[i] <= 10^5

*/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxi = -1;
        int len = arr.size();
        for (int i = len-1; i >= 0; i--) {
            int tmp = arr[i];
            arr[i] = maxi;
            maxi = max(maxi, tmp);
        }
        return arr;
    }
};
