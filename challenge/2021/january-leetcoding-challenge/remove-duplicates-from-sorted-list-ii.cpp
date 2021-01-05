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

// O(n) time, O(1) space
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;
        
        while(cur) {
            ListNode *it = cur;
            while(it->next and it->val == it->next->val)    it = it->next;
            
            if(it != cur)   pre->next = it->next;
            if(it == cur)   pre = it;
            cur = it->next;
        }
        return dummy->next;
    }
};
