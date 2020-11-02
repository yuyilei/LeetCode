/*
You are given an array of distinct integers arr and an array of integer arrays pieces, where the integers in pieces are distinct. Your goal is to form arr by concatenating the arrays in pieces in any order. However, you are not allowed to reorder the integers in each array pieces[i].

Return true if it is possible to form the array arr from pieces. Otherwise, return false.

 

Example 1:

Input: arr = [85], pieces = [[85]]
Output: true
Example 2:

Input: arr = [15,88], pieces = [[88],[15]]
Output: true
Explanation: Concatenate [15] then [88]
Example 3:

Input: arr = [49,18,16], pieces = [[16,18,49]]
Output: false
Explanation: Even though the numbers match, we cannot reorder pieces[0].
Example 4:

Input: arr = [91,4,64,78], pieces = [[78],[4,64],[91]]
Output: true
Explanation: Concatenate [91] then [4,64] then [78]
Example 5:

Input: arr = [1,3,5,7], pieces = [[2,4,6,8]]
Output: false
 

Constraints:

1 <= pieces.length <= arr.length <= 100
sum(pieces[i].length) == arr.length
1 <= pieces[i].length <= arr.length
1 <= arr[i], pieces[i][j] <= 100
The integers in arr are distinct.
The integers in pieces are distinct (i.e., If we flatten pieces in a 1D array, all the integers in this array are distinct).

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-array-formation-through-concatenation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int len = arr.size();
        for (int i = 0; i < len; i) {
            bool find = false;
            for (int j = 0; j < pieces.size(); j++) {
                if (pieces[j][0] == arr[i]) {
                    i++;
                    for (int k = 1; k < pieces[j].size(); k++) {
                        if (arr[i] == pieces[j][k]) {
                            i++;
                        }
                        else {
                            return false;
                        }
                    }
                    find = true;
                    break;
                }
            }
            if (!find)
                return false;
        }
        return true;
    }
};


class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        map<int, vector<int>> idx;
        for (int i = 0; i < pieces.size(); i++) {
            idx[pieces[i][0]] = pieces[i];
        }
        for (int i = 0; i < arr.size(); ) {
            if (idx.find(arr[i]) == idx.end()) {
                return false;
            }
            int tmp = i;
            for (int j = 0; j < idx[arr[tmp]].size(); j++, i++) {
                // cout << idx[arr[tmp]][j] << " " << arr[tmp] << endl;
                if (idx[arr[tmp]][j] != arr[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
