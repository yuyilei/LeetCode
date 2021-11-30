/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<int> n;
        ListNode* t = head; 
        while (t) {
            n.push_back(t->val); 
            t = t->next; 
        }
        ListNode* pre = new ListNode(0); 
        ListNode* cur = pre;
        int len = n.size(); 
        int g = 1, i = 0; 
        while (i < len) {
            int start = i; 
            int end; 
            if (len-1-i >= g) {
                end = i+g-1;
            }
            else {
                end = len-1; 
            }
            bool isEvent = (end-start+1)%2 == 0 ? true : false; 
            if (isEvent) {
                for (int j = end; j >= start; j--) {
                    cur->next = new ListNode(n[j]); 
                    cur = cur->next;
                }
            }
            else {
                for (int j = start; j <= end; j++) {
                    cur->next = new ListNode(n[j]); 
                    cur = cur->next;
                }
            }
            g++; 
            i = end+1; 
        }
        return pre->next;
    }
};