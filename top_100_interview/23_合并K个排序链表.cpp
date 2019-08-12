/*
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<TreeNode*, vector<ListNode*>, cmp> q;
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        for (ListNode* node: lists) {
            if (node)
                q.push(node);
        }
        while (!q.empty()) {
            ListNode* now = q.top();
            q.pop();
            cur->next = now;
            if (q.empty())
                break;
            if (now->next)
                q.push(now->next);
            cur = cur->next;
        }
        return res->next;
    }
struct cmp{
        bool operator()(ListNode*a,ListNode*b){
            return a->val > b->val;
        }
    };
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;
        if (lists.size() == 1)
            return lists[0];
        if (lists.size() == 2)
            return merge(lists[0], lists[1]);
        int mid = lists.size()/2;
        vector<ListNode*> tmp1 (mid);
        vector<ListNode*> tmp2 (lists.size()-mid);
        for (int i = 0; i < mid; i++) {
            tmp1[i] = lists[i];
        }
        for (int i = mid; i < lists.size(); i++) {
            tmp2[i-mid] = lists[i];
        }
        return merge(mergeKLists(tmp1), mergeKLists(tmp2));
    }
private:
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        while (a && b) {
            if (a->val < b->val) {
                cur->next = a;
                a = a->next;
            }
            else {
                cur->next = b;
                b = b->next;
            }
            cur = cur->next;
        }
        if (a)
            cur->next = a;
        if (b)
            cur->next = b;
        return res->next;
    }
};


