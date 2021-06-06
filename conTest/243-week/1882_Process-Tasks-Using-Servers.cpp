/*
[200~You are given two 0-indexed integer arrays servers and tasks of lengths n​​​​​​ and m​​​​​​ respectively. servers[i] is the weight of the i​​​​​​th​​​​ server, and tasks[j] is the time needed to process the j​​​​​​th​​​​ task in seconds.

You are running a simulation system that will shut down after all tasks are processed. Each server can only process one task at a time. You will be able to process the jth task starting from the jth second beginning with the 0th task at second 0. To process task j, you assign it to the server with the smallest weight that is free, and in case of a tie, choose the server with the smallest index. If a free server gets assigned task j at second t,​​​​​​ it will be free again at the second t + tasks[j].

If there are no free servers, you must wait until one is free and execute the free tasks as soon as possible. If multiple tasks need to be assigned, assign them in order of increasing index.

You may assign multiple tasks at the same second if there are multiple free servers.

Build an array ans​​​​ of length m, where ans[j] is the index of the server the j​​​​​​th task will be assigned to.

Return the array ans​​​​.

 

Example 1:

Input: servers = [3,3,2], tasks = [1,2,3,2,1,2]
Output: [2,2,0,2,1,2]
Explanation: Events in chronological order go as follows:
- At second 0, task 0 is added and processed using server 2 until second 1.
- At second 1, server 2 becomes free. Task 1 is added and processed using server 2 until second 3.
- At second 2, task 2 is added and processed using server 0 until second 5.
- At second 3, server 2 becomes free. Task 3 is added and processed using server 2 until second 5.
- At second 4, task 4 is added and processed using server 1 until second 5.
- At second 5, all servers become free. Task 5 is added and processed using server 2 until second 7.
Example 2:

Input: servers = [5,1,4,3,2], tasks = [2,1,2,4,5,2,1]
Output: [1,4,1,4,1,3,2]
Explanation: Events in chronological order go as follows:
- At second 0, task 0 is added and processed using server 1 until second 2.
- At second 1, task 1 is added and processed using server 4 until second 2.
- At second 2, servers 1 and 4 become free. Task 2 is added and processed using server 1 until second 4.
- At second 3, task 3 is added and processed using server 4 until second 7.
- At second 4, server 1 becomes free. Task 4 is added and processed using server 1 until second 9.
- At second 5, task 5 is added and processed using server 3 until second 7.
- At second 6, task 6 is added and processed using server 2 until second 7.
 

Constraints:

servers.length == n
tasks.length == m
1 <= n, m <= 2 * 105
1 <= servers[i], tasks[j] <= 2 * 105


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/process-tasks-using-servers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


struct FreeNode {
    int weight;
    int index;
    FreeNode(int w, int i): weight(w), index(i){}
    bool operator< (const struct FreeNode& t) const{
        if (weight != t.weight)
            return weight > t.weight;
        return index > t.index;
    }
};

struct BusyNode {
    int endTime;
    int index;
    BusyNode(int e, int i): endTime(e), index(i) {}
    bool operator< (const struct BusyNode& t) const{
        return endTime > t.endTime;
    }
};

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int s = servers.size(), t = tasks.size();
        vector<int> res (t, 0);
        priority_queue<struct FreeNode> fq;
        priority_queue<struct BusyNode> bq;
        for (int i = 0; i < s; i++) {
            fq.push(FreeNode(servers[i], i));
        }
        int cur = 0, index = 0;  // cur表示当前时刻，index表示当前正在被分配的task
        while (index < t) {
            while (!bq.empty()) {         // 取出当前时刻已经完成task的所有node
                if (bq.top().endTime <= cur) {
                    struct BusyNode bn = bq.top();
                    bq.pop();
                    fq.push(FreeNode(servers[bn.index], bn.index));
                }
                else {
                    break;
                }
            }
            if (fq.empty()) {     // 当前时刻没有任何node空闲
                cur = bq.top().endTime;  // 直接跳到有node空闲的时刻
                continue;
            }
            while (index < t && index <= cur && !fq.empty()) {  //  按照题目要求，每次尽量多地分配task
                struct FreeNode fn = fq.top();
                fq.pop();
                res[index] = fn.index;
                bq.push(BusyNode(cur+tasks[index], fn.index));
                index++;
            }
            cur++;
        }
        return res;
    }
};
