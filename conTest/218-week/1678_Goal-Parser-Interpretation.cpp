/*
You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order. The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". The interpreted strings are then concatenated in the original order.

Given the string command, return the Goal Parser's interpretation of command.

 

Example 1:

Input: command = "G()(al)"
Output: "Goal"
Explanation: The Goal Parser interprets the command as follows:
G -> G
() -> o
(al) -> al
The final concatenated result is "Goal".
Example 2:

Input: command = "G()()()()(al)"
Output: "Gooooal"
Example 3:

Input: command = "(al)G(al)()()G"
Output: "alGalooG"
 

Constraints:

1 <= command.length <= 100
command consists of "G", "()", and/or "(al)" in some order.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/goal-parser-interpretation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    string interpret(string command) {
        string res = "";
        int len = command.size();
        for (int i = 0; i < len; ) {
            char cur = command[i];
            if (cur == 'G') {
                res += 'G';
                i++;
            }
            else if (cur == '(') {
                if (command[i+1] == 'a') {
                    res += "al";
                    i += 3;
                }
                else {
                    res += 'o';
                    i += 2;
                }
            }
            else {
                i++;
            }
        }
        return res;
    }
};
